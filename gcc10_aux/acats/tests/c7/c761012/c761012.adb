
with Ada.Exceptions;
use Ada.Exceptions;
with C761012_0;
use C761012_0;
with Report;
use Report;
procedure C761012 is
begin
    Test ("C761012",
          "Check that an anonymous object is finalized with its enclosing " &
             "master if a transfer of control or exception occurs prior to " &
             "performing its normal finalization");

    Excep:
        begin

            declare
                I : Integer := Create.C1; -- Raises Constraint_Error
            begin
                Failed
                   ("Improper component selection did not raise Constraint_Error, I =" &
                    Integer'Image (I));
            exception
                when Constraint_Error =>
                    Failed ("Constraint_Error caught by the wrong handler");
            end;

            Failed ("Transfer of control did not happen correctly");

        exception
            when Constraint_Error =>
                if not Finalize_Was_Called then
                    Failed ("Finalize wasn't called when the master was left " &
                            "- Constraint_Error");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Information (E));
        end Excep;

    Transfer:
        declare
            Finalize_Was_Called_Before_Leaving_Exit : Boolean;
        begin

            begin
                loop
                    exit when Create.C2 = 3.0;
                end loop;
                Finalize_Was_Called_Before_Leaving_Exit := Finalize_Was_Called;
                if Finalize_Was_Called_Before_Leaving_Exit then
                    Comment ("Finalize called before the transfer of control");
                end if;
            end;

            if not Finalize_Was_Called and then
               not Finalize_Was_Called_Before_Leaving_Exit then
                Failed ("Finalize wasn't called when the master was left " &
                        "- transfer of control");
            end if;
        end Transfer;

    Result;
end C761012;

