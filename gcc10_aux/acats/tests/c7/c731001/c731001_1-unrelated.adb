
with C731001_1.Parent; use C731001_1.Parent;
    pragma Elaborate(C731001_1.Parent);
package body C731001_1.Unrelated is

    function Make return T2 is
        Result: T2;
    begin
        return Result;
    end Make;

    function Op2(X: T2) return String is
    begin
        return "Unrelated.Op2 body";
    end Op2;
begin

    Check_String(Op1(T2'(Make)), "Parent.Op1 body");
    Check_String(Op1(T2_Class(T2'(Make))), "Parent.Op1 body");
    Check_String(Op1(Root_Class(T2'(Make))), "Parent.Op1 body");

    Check_String(Op2(T2'(Make)), "Unrelated.Op2 body");
    Check_String(Op2(T2_Class(T2'(Make))), "Unrelated.Op2 body");
    Check_String(Call_Op2(T2'(Make)), "Parent.Op2 body");
    Check_String(Call_Op2(T2_Class(T2'(Make))), "Parent.Op2 body");
    Check_String(Call_Op2(Root_Class(T2'(Make))), "Parent.Op2 body");

end C731001_1.Unrelated;
