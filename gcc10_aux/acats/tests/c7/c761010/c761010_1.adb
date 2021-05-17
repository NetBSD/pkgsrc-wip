
package body C761010_1 is
    function Square(X: Integer) return Integer is
    begin
        return X**2;
    end Square;

    procedure Initialize (Object : in out TC_Control) is
    begin
        Test("C761010_1",
             "Check that Adjust is not called"
              & " when aggregates are used to initialize objects");
    end Initialize;

    procedure Finalize (Object : in out TC_Control) is
    begin
        if not TC_Finalize_Called then
            Failed("Var_Strings Finalize never called");
        end if;
        Result;
    end Finalize;

    TC_Test : TC_Control; -- Starts test; finalization ends test.
end C761010_1;
