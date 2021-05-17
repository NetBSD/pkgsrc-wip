

with Ada.Assertions;
with Ada.Finalization;
with Ada.Unchecked_Deallocate_Subpool;
with Ada.Unchecked_Deallocation;
with System.Storage_Pools.Subpools;
with CDB4001_Tracked_Subpools;

with Report;
procedure CDB4001 is

    subtype Subpool_Handle is System.Storage_Pools.Subpools.Subpool_Handle;
    use type Subpool_Handle;

    type Subpool_Id is range 1 .. 5;
    type Index is range 1 .. 4;

    type Object_Id_Or_Nil is new Integer range 0 ..
      Integer (Subpool_Id'Last)
      * Integer (Index'Last + ((Index'Last * (Index'Last + 1)) / 2));
    --
    -- For each (Subpool,Index) pair, one object is created for the
    -- Obj_Ref array (declared below) and Index objects are created
    -- for the Vec_Ref array (declared below; see also the "1 .. Idx" in
    -- the body of Initializer_Task below).

    subtype Object_Id is Object_Id_Or_Nil range 1 .. Object_Id_Or_Nil'Last;

    protected Id_Allocator is
        procedure Next (Id : out Object_Id);
    private
        Counter : Object_Id_Or_Nil := 0;
    end Id_Allocator;

    protected body Id_Allocator is
        procedure Next (Id : out Object_Id) is
        begin
            Counter := Counter + 1;
            Id := Counter;
        end Next;
    end Id_Allocator;

    function Next return Object_Id is
    begin
        return Result : Object_Id do
            Id_Allocator.Next (Result);
        end return;
    end Next;

    type Object_Id_Set is array (Object_Id) of Boolean;
    Finalized : Object_Id_Set := (others => False);

    Test_Failed : exception;

    procedure Assert (Condition : Boolean; Descr : String) is
    begin
        if not Condition then
            Report.Failed (Descr => Descr);
            raise Test_Failed;
        end if;
    end Assert;

    package Pkg is
        type Object (Id : Object_Id := Next) is
          new Ada.Finalization.Limited_Controlled with
          null record;

        overriding
        procedure Finalize (X : in out Object);
    end Pkg;

    package body Pkg is
        procedure Finalize (X : in out Object) is
        begin
            Assert (not Finalized (X.Id), "limited object finalized twice");
            Finalized (X.Id) := True;
        end Finalize;
    end Pkg;

    type Rec is
      record
         Real : Long_Float := 1234.5;
         Obj  : Pkg.Object;
         Char : Character := 'C';
      end record;

    procedure Test is
        The_Pool : CDB4001_Tracked_Subpools.Tracked_Pool;

        Subpools : array (Subpool_Id) of Subpool_Handle;
          --  := (others => CDB4001_Tracked_Subpools.Create_Subpool (The_Pool));
          --  Can't initialize with aggregate because Create_Subpool's
          --  parameter is in-out.

        type Vec is array (Index range <>) of Rec;

        type Obj_Ref is access Pkg.Object;
        for Obj_Ref'Storage_Pool use The_Pool;

        type Vec_Ref is access Vec;
        for Vec_Ref'Storage_Pool use The_Pool;

        Obj_Refs : array (Index, Subpool_Id) of Obj_Ref
            with Independent_Components;
        Vec_Refs : array (Index, Subpool_Id) of Vec_Ref
            with Independent_Components;

        procedure Initialize_Refs is
            Next_Index : Index := Index'First;

            function Get_Index return Index is
            begin
                return Result : Index := Next_Index do
                    if Next_Index /= Index'Last then
                        Next_Index := Next_Index + 1;
                    end if;
                end return;
            end Get_Index;

            task type Initializer (Idx : Index := Get_Index);

            task body Initializer is
            begin
                for Subp in Subpool_Id loop
                  declare
                    Handle : Subpool_Handle renames Subpools (Subp);
                  begin
                    Obj_Refs (Idx, Subp) := new (Handle) Pkg.Object;
                    Vec_Refs (Idx, Subp) := new (Handle) Vec (1 .. Idx);
                  end;
                end loop;
            end Initializer;

        begin
            declare
                Initializers : array (Index) of Initializer;
            begin null; end;

            for Subp in Subpool_Id loop
                for Idx in Index loop
                    Assert (Obj_Refs (Idx, Subp) /= null,
                            "incomplete Obj_Refs initialization");
                    Assert (Vec_Refs (Idx, Subp) /= null,
                            "incomplete Vec_Refs initialization");
                end loop;
            end loop;
        end Initialize_Refs;

    begin
        for Id in Subpool_Id loop
           Subpools (Id) := CDB4001_Tracked_Subpools.Create_Subpool (The_Pool);
        end loop;

        Initialize_Refs;

        Report.Comment ("Initialization complete");

        for Subp in Subpool_Id loop
            for Idx in Index loop
                Assert
                  (CDB4001_Tracked_Subpools.Enclosing_Subpool
                     (The_Pool, Obj_Refs (Idx, Subp).all'Address)
                   = Subpools (Subp),
                   "wrong enclosing subpool for Obj_Refs element");
                Assert
                  (CDB4001_Tracked_Subpools.Enclosing_Subpool
                     (The_Pool, Vec_Refs (Idx, Subp).all'Address)
                   = Subpools (Subp),
                   "wrong enclosing subpool for Vec_Refs element");
            end loop;
        end loop;

        Report.Comment ("Enclosing_Subpool checking complete");

        declare
            procedure Free is new Ada.Unchecked_Deallocation
              (Pkg.Object, Obj_Ref);
            procedure Free is new Ada.Unchecked_Deallocation (Vec, Vec_Ref);

            Expected : Object_Id_Set := (others => False);
        begin
            for Subp in Subpool_Id loop
                for Idx in Index loop
                    case  (Integer (Subp) + Integer (Idx)) mod 5 is
                        when 1 =>
                            Expected (Obj_Refs (Idx, Subp).Id) := True;
                            Free (Obj_Refs (Idx, Subp));

                        when 2 =>
                            for I in Vec_Refs (Idx, Subp)'Range loop
                                Expected (Vec_Refs (Idx, Subp)(I).Obj.Id)
                                  := True;
                            end loop;
                            Free (Vec_Refs (Idx, Subp));

                        when others =>
                            null;
                    end case;
                    Assert (Finalized = Expected,
                            "unexpected finalization state after " &
                            "Unchecked_Deallocation call");
                end loop;
            end loop;

            Report.Comment ("Individual object deallocation complete");

            for Subp in Subpool_Id loop
                if Subp mod 3 = 1 then
                    for Idx in Index loop
                        if Obj_Refs (Idx, Subp) /= null then
                            Expected (Obj_Refs (Idx, Subp).Id) := True;
                        end if;
                        if Vec_Refs (Idx, Subp) /= null then
                            for I in Vec_Refs (Idx, Subp)'Range loop
                                Expected (Vec_Refs (Idx, Subp)(I).Obj.Id)
                                  := True;
                            end loop;
                        end if;
                    end loop;
                    Ada.Unchecked_Deallocate_Subpool (Subpools (Subp));
                    Assert (Finalized = Expected,
                            "unexpected finalization state after " &
                             "Unchecked_Deallocate_Subpool call");
                end if;
            end loop;

            Report.Comment ("Subpool deallocation complete");
        end;
    end Test;
begin
    Report.Test ("CDB4001",
                 "Allocation and deallocation of objects using subpools");
    begin
        Test;
        Assert (Finalized = (Finalized'Range => True),
                "not all allocated objects were finalized");
    exception
        when Test_Failed =>
            null;
        when others =>
            Report.Failed ("Unexpected exception");
    end;

    Report.Result;
end CDB4001;
