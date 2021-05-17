
package B831003.Child1 is

    package Nested is

        type T is limited private;
        type A is array (Integer range <>) of T;
    private
        type T is new B831003.T;

        overriding
        function "=" (X, Y : T) return Boolean; -- OK

        overriding
        function "=" (X, Y : A) return Boolean; -- OK

        function "or" (X, Y : T) return T;
        function "or" (X, Y : A) return A;

    end Nested;

    type TT is new B831003.T;
private
    -- The fact that TT has all Boolean operations becomes known here.
    overriding
    function "xor" (X, Y : TT) return TT; -- OK

    not overriding
    function "*" (X, Y : TT) return TT; -- OK

end B831003.Child1;
