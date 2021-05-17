
with C731001_1.Parent.Main;
package body C731001_1.Parent is

    procedure Call_Main is
    begin
        Main;
    end Call_Main;

    function Make return Root is
        Result: Root;
    begin
        return Result;
    end Make;

    function Op1(X: Root) return String is
    begin
        return "Parent.Op1 body";
    end Op1;

    function Op2(X: Root) return String is
    begin
        return "Parent.Op2 body";
    end Op2;

    function Call_Op2(X: Root'Class) return String is
    begin
        return Op2(X);
    end Call_Op2;

begin

    Check_String(Op1(Root'(Make)), "Parent.Op1 body");
    Check_String(Op1(Root_Class(Root'(Make))), "Parent.Op1 body");

    Check_String(Op2(Root'(Make)), "Parent.Op2 body");
    Check_String(Op2(Root_Class(Root'(Make))), "Parent.Op2 body");

end C731001_1.Parent;
