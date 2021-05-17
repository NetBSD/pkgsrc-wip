
private package B7310016_1.Parent.Private_Child is
    pragma Elaborate_Body; -- So we can have one.

    type T3 is new Root with null record;
    -- Op1(T3) implicitly declared here.
    -- And Op2, also -- see AARM-7.3.1(7.n).
    type Op1_Type is access procedure(X: T3);
    Op1_Ptr: constant Op1_Type := Op1'Access; -- OK
    type Op2_Type is access procedure(X: T3);
    Op2_Ptr: constant Op2_Type := Op2'Access; -- OK

    package Nested is
        type T4 is new Root with null record;
    private
        Op2_Ptr: constant Op2_Type := Op2'Access; -- OK
        -- ...
    end Nested;
private
    OK_Op2_Ptr: constant Op2_Type := Op2'Access; -- OK
    -- Op2(T3) implicitly declared here.
    -- ...
end B7310016_1.Parent.Private_Child;
