
with Report;
use Report;
package body C761011_0 is

    User_Error : exception;

    Finalize_Called : array (0 .. 50) of Boolean := (others => False);

    function Create (Id : Integer) return Ctrl is
        Obj : Ctrl (Boolean'Val (Id mod Ident_Int (2)));
    begin
        case Obj.D is
            when False =>
                Obj.C1 := Ident_Int (Id);
            when True =>
                Obj.C2 := Float (Ident_Int (Id + Ident_Int (Id)));
        end case;
        return Obj;
    end Create;

    procedure Finalize (Obj : in out Ctrl) is
    begin
        if not Obj.Finalized then
            Obj.Finalized := True;
            if Obj.D then
                if Integer (Obj.C2 / 2.0) mod Ident_Int (10) =
                   Ident_Int (3) then
                    raise User_Error;
                else
                    Finalize_Called (Integer (Obj.C2) / 2) := True;
                end if;
            else
                if Obj.C1 mod Ident_Int (10) = Ident_Int (0) then
                    raise Tasking_Error;
                else
                    Finalize_Called (Obj.C1) := True;
                end if;
            end if;
        end if;
    end Finalize;

    function Was_Finalized (Id : Integer) return Boolean is
    begin
        return Finalize_Called (Ident_Int (Id));
    end Was_Finalized;

    procedure Use_It (Obj : in Ctrl) is
       -- Use Obj to prevent optimization.
    begin
        case Obj.D is
            when True =>
                if not Equal (Boolean'Pos(Obj.Finalized),
                              Boolean'Pos(Obj.Finalized)) then
                    Failed ("Identity check - 1");
                end if;
            when False =>
                if not Equal (Obj.C1, Obj.C1) then
                    Failed ("Identity check - 2");
                end if;
        end case;
    end Use_It;

end C761011_0;
