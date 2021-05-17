
package body B831003.Child2 is

    package body Nested is
        -- The full set of operations for the type T is available here.

        overriding
        function "=" (X, Y : T) return Boolean is -- OK
        begin
            return True;
        end "=";

        overriding
        function "=" (X, Y : A) return Boolean is -- OK
        begin
            return False;
        end "=";

        overriding
        function "or" (X, Y : T) return T is -- OK
        begin
            return X and Y;
        end "or";

    end Nested;

    overriding
    function "xor" (X, Y : TT) return TT is -- OK
    begin
        return X and Y;
    end "xor";

end B831003.Child2;
