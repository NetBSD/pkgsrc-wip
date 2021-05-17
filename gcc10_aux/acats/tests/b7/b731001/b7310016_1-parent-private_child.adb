
with B7310016_1.Unrelated; use B7310016_1.Unrelated;
package body B7310016_1.Parent.Private_Child is
    package body Nested is
        -- Op2(T4) implicitly declared here.
    end Nested;

    type T5 is new T2 with null record;
    T3_Obj: T3;
begin
    Op2(T3_Obj); -- OK
end B7310016_1.Parent.Private_Child;
