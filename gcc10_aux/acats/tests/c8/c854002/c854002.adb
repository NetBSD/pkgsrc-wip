
with Report; use Report;
with C854002_1.Caller;
procedure C854002 is
begin
    Test("C854002",
         "An elaboration check is performed for a call to a subprogram"
         & " whose body is given as a renaming-as-body");

    -- By the time we get here, all library units have been elaborated,
    -- so the following calls should not raise Program_Error:
    C854002_1.Caller.Call_Renamed_F(Should_Fail => False);
    C854002_1.Caller.Call_Renamed_G(Should_Fail => False);

    Result;
end C854002;
