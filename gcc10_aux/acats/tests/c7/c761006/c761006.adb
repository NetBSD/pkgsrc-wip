
--------------------------------------------------------------------- C761006

with Report;
with C761006_0;
with C761006_2;
with C761006_Support;
with Ada.Exceptions;
with Ada.Finalization;
with Unchecked_Deallocation;
procedure C761006 is

  package Sup renames C761006_Support;
  use type Sup.Event_Array;

  type Procedure_Handle is access procedure;

  type Test_ID is ( Simple, Initialize, Adjust, Finalize );

  Sub_Tests : array(Test_ID) of Procedure_Handle;

  procedure Simple_Test is
    A_Good_Object : C761006_0.Good; -- should call Initialize
  begin
    if not A_Good_Object.Initialized then
      Report.Failed("Good object not initialized");
    end if;

    -- should call Adjust
    A_Good_Object := ( Ada.Finalization.Controlled
                       with Unique => 0, others => False );
    if not A_Good_Object.Adjusted then
      Report.Failed("Good object not adjusted");
    end if;

    -- should call Finalize before end of scope
  end Simple_Test;

  procedure Initialize_Test is
  begin
    declare
      This_Object_Fails_In_Initialize : C761006_2.Init_Check;
    begin
      Report.Failed("Exception in Initialize did not occur");
    exception
      when others =>
        Report.Failed("Initialize caused exception at wrong lex");
    end;

    Report.Failed("Error in execution sequence");

  exception
    when Sup.Propagating_Exception => -- this is correct
      if not Sup.Events_Occurring(Sup.Good_Initialize) then
        Report.Failed("Initialization of Good Component did not occur");
      end if;
  end Initialize_Test;

  procedure Adjust_Test is
    This_Object_OK     : C761006_2.Adj_Check;
    This_Object_Target : C761006_2.Adj_Check;
  begin

    Check_Adjust_Due_To_Assignment: begin
      This_Object_Target := This_Object_OK;
      Report.Failed("Adjust did not propagate any exception");
    exception
      when Program_Error =>  -- expected case
             if not This_Object_Target.Good_Component.Adjusted then
               Report.Failed("other adjustment not performed");
             end if;
      when others =>
             Report.Failed("Adjust propagated wrong exception");
    end Check_Adjust_Due_To_Assignment;

    C761006_Support.Events_Occurring := (True, False, False);

    Check_Adjust_Due_To_Initial_Assignment: declare
      Another_Target : C761006_2.Adj_Check := This_Object_OK;
    begin
      Report.Failed("Adjust did not propagate any exception");
    exception
      when others => Report.Failed("Adjust caused exception at wrong lex");
    end Check_Adjust_Due_To_Initial_Assignment;

  exception
    when Program_Error =>  -- expected case
           if Sup.Events_Occurring(Sup.Good_Finalize) /=
              Sup.Events_Occurring(Sup.Good_Adjust) then
              -- RM 7.6.1(16/1) says that the good Adjust may or may not
              -- be performed; but if it is, then the Finalize must be
              -- performed; and if it is not, then the Finalize must not
              -- performed.
              if Sup.Events_Occurring(Sup.Good_Finalize) then
                 Report.Failed("Good adjust not performed with bad adjust, " &
                               "but good finalize was");
              else
                 Report.Failed("Good adjust performed with bad adjust, " &
                               "but good finalize was not");
              end if;
           end if;
    when others =>
           Report.Failed("Adjust propagated wrong exception");
  end Adjust_Test;

  procedure Finalize_Test is

    Fin_Not_Perf : constant String := "other finalizations not performed";

    procedure Finalize_15 is
      Item   : C761006_2.Fin_Check;
      Target : C761006_2.Fin_Check;
    begin

      Item := Target;
      -- finalization of Item should cause PE
      -- ARM7.6:21 allows the implementation to omit the assignment of the
      -- value into an anonymous object, which is the point at which Adjust
      -- is normally called.  However, this would result in Program_Error's
      -- being raised before the call to Adjust, with the consequence that
      -- Adjust is never called.

    exception
      when Program_Error => -- expected case
             if not Sup.Events_Occurring(Sup.Good_Finalize) then
               Report.Failed("Assignment: " & Fin_Not_Perf);
             end if;
      when others =>
             Report.Failed("Other exception in Finalize_15");

    -- finalization of Item/Target should cause PE
    end Finalize_15;

    -- check failure in finalize due to Unchecked_Deallocation

    procedure Finalize_17_Outer is
      -- This procedure exists to make Shark local, so everything allocated
      -- on it will be finalized when this routine exits.

      type Shark is access C761006_2.Fin_Check;

      procedure Catch is
        new Unchecked_Deallocation( C761006_2.Fin_Check, Shark );

      procedure Finalize_17_Inner is
        White : Shark := new C761006_2.Fin_Check;
      begin
        Catch (White);
          -- Note: It is unspecified if Catch deallocates the memory
          -- of the allocated object, and if it ceases to exist.
          -- As such, it is possible that it will be finalized when
          -- the scope of the access type is exited. We check for this
          -- case below.
      exception
        when Program_Error =>
           if not Sup.Events_Occurring(Sup.Good_Finalize) then
             Report.Failed("Unchecked_Deallocation: " & Fin_Not_Perf);
           end if;
      end Finalize_17_Inner;

    begin
       Finalize_17_Inner;
    exception
      when others =>
        Report.Failed("Unchecked_Deallocation check, unwanted exception in Outer");
    end Finalize_17_Outer;

  begin

    Exception_In_Finalization: begin
      Finalize_15;
    exception
      when Program_Error => null; -- anticipated
    end Exception_In_Finalization;

    Use_Of_Unchecked_Deallocation: begin
      Finalize_17_Outer;
    exception
      when Program_Error =>
        Report.Comment("Unchecked_Deallocation check, double finalization occurred");
      when others =>
        Report.Failed("Unchecked_Deallocation check, unwanted exception in caller");
    end Use_Of_Unchecked_Deallocation;

  end Finalize_Test;

begin  -- Main test procedure.

  Report.Test ("C761006", "Check that exceptions raised in Initialize, " &
                          "Adjust and Finalize are processed correctly" );

  Sub_Tests := (Simple_Test'Access, Initialize_Test'Access,
                Adjust_Test'Access, Finalize_Test'Access);

  for Test in Sub_Tests'Range loop
    begin

      Sup.Events_Occurring := (others => False);

      Sub_Tests(Test).all;

      case Test is
        when Simple | Adjust =>
          if Sup.Events_Occurring /= Sup.Event_Array ' ( others => True ) then
            Report.Failed ( "Other operation missing in " &
                            Test_ID'Image ( Test ) );
          end if;
        when  Initialize =>
          null;
        when Finalize  =>
          -- Note that for Good_Adjust, we may get either True or False
          if Sup.Events_Occurring ( Sup.Good_Initialize ) = False or
             Sup.Events_Occurring ( Sup.Good_Finalize ) = False
          then
            Report.Failed ( "Other operation missing in " &
                            Test_ID'Image ( Test ) );
          end if;
      end case;

    exception
       when How: others => Report.Failed( Ada.Exceptions.Exception_Name( How )
                                        & " from " & Test_ID'Image( Test ) );
    end;
  end loop;

  Report.Result;

end C761006;
