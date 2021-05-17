
package C854002_1.Caller is

    -- These procedures call the renamings; when called during elaboration,
    -- we pass Should_Fail => True, which checks that Program_Error is
    -- raised.  Later, we use Should_Fail => False.

    procedure Call_Renamed_F(Should_Fail: Boolean);
    procedure Call_Renamed_G(Should_Fail: Boolean);

end C854002_1.Caller;
