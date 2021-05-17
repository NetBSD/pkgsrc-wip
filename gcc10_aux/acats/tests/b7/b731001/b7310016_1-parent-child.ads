
package B7310016_1.Parent.Child is
    pragma Elaborate_Body; -- So we can have one.

    -- See B7310016_1.Parent.Child_2 for the error cases.

    type T3 is new Root with null record;
    -- Op1(T3) implicitly declared here.
    type Op_Type is access procedure(X: T3);
    Op1_Ptr: constant Op_Type := Op1'Access; -- OK

    package Nested is
        type T4 is new Root with null record;
        type Op_Type is access procedure(X: T4);
        Op1_Ptr: constant Op_Type := Op1'Access; -- OK
    end Nested;
private
    OK_Op2_Ptr: constant Op_Type := Op2'Access; -- OK
    -- Op2(T3) implicitly declared here.
    -- ...
end B7310016_1.Parent.Child;
