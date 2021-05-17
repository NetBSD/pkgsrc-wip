
package B831003.Child2 is

    package Nested is

        type T is limited private;
        type A is array (Integer range <>) of T;
    private
        type T is new B831003.T;

        function "=" (X, Y : T) return Boolean;
        function "=" (X, Y : A) return Boolean;
    end Nested;

    type TT is new B831003.T;

end B831003.Child2;
