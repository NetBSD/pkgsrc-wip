
with B7310016_1.Unrelated; use B7310016_1.Unrelated;
package body B7310016_1.Parent.Child is
    package body Nested is
        -- Op2(T4) implicitly declared here.
        T4_Obj: T4;
    begin
        Op2(T4_Obj); -- OK
    end Nested;

    type T5 is new T2 with null record;
    T5_Obj: T5;
    T3_Obj: T3;
begin
    Op2(T3_Obj); -- OK
    Op1(T5_Obj); -- OK
    Op2(T5_Obj); -- OK
end B7310016_1.Parent.Child;
