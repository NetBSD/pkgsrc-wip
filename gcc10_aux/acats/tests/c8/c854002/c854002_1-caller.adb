
with Report; use Report; pragma Elaborate_All (Report);
with C854002_1.Renamings;
package body C854002_1.Caller is

    Some_Error: exception;

    procedure Call_Renamed_F(Should_Fail: Boolean) is
    begin
        if Should_Fail then
            begin
                Failed(C854002_1.Renamings.Renamed_F);
                raise Some_Error;
                    -- This raise statement is necessary, because the
                    -- Report package has a bug -- if Failed is called
                    -- before Test, then the failure is ignored, and the
                    -- test prints "PASSED".
                    -- Presumably, this raise statement will cause the
                    -- program to crash, thus avoiding the PASSED message.
            exception
                when Program_Error =>
                    Comment("Program_Error -- OK");
            end;
        else
            if C854002_1.Renamings.F_Result /= C854002_1.Renamings.Renamed_F then
                Failed("Bad result from renamed F");
            end if;
        end if;
    end Call_Renamed_F;

    procedure Call_Renamed_G(Should_Fail: Boolean) is
    begin
        if Should_Fail then
            begin
                Failed(C854002_1.Renamings.Renamed_G);
                raise Some_Error;
            exception
                when Program_Error =>
                    Comment("Program_Error -- OK");
            end;
        else
            if C854002_1.Renamings.G_Result /= C854002_1.Renamings.Renamed_G then
                Failed("Bad result from renamed G");
            end if;
        end if;
    end Call_Renamed_G;

begin
    -- At this point, the bodies of Renamed_F and Renamed_G have not yet
    -- been elaborated, so calling them should raise Program_Error:
    Call_Renamed_F(Should_Fail => True);
    Call_Renamed_G(Should_Fail => True);
end C854002_1.Caller;
