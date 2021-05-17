
package body B831003.Child1 is

    package body Nested is
        -- The full set of operations for the type T is available here.

        function "=" (X, Y : T) return Boolean is
        begin
            return True;
        end "=";

        function "=" (X, Y : A) return Boolean is
        begin
            return False;
        end "=";

        function "or" (X, Y : T) return T is
        begin
            return X and Y;
        end "or";

        function "or" (X, Y : A) return A is
        begin
            return X xor not Y;
        end "or";

    end Nested;

    overriding
    function "xor" (X, Y : TT) return TT is
    begin
        return X and Y;
    end "xor";

    not overriding
    function "*" (X, Y : TT) return TT is
    begin
        return X and Y;
    end "*";

end B831003.Child1;
