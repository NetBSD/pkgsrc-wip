
with Report;
use Report;
package body C761012_0 is

    Finalization_Flag : Boolean := False;

    function Create return Ctrl is
        Obj : Ctrl (Ident_Bool (True));
    begin
        Obj.C2 := 3.0;
        return Obj;
    end Create;

    procedure Finalize (Obj : in out Ctrl) is
    begin
        Finalization_Flag := True;
    end Finalize;

    function Finalize_Was_Called return Boolean is
    begin
        if Finalization_Flag then
            Finalization_Flag := False;
            return True;
        else
            return False;
        end if;
    end Finalize_Was_Called;

end C761012_0;
