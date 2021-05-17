
with C731001_1.Parent.Child;
    use C731001_1.Parent;
    use C731001_1.Parent.Child;
    use C731001_1.Parent.Child.Nested;
with C731001_1.Unrelated; use C731001_1.Unrelated;
procedure C731001_1.Parent.Main is

    Root_Obj: Root := Make;
    Root_Class_Obj: Root_Class := Root'(Make);

    T2_Obj: T2 := Make;
    T2_Class_Obj: T2_Class := T2_Obj;
    T2_Root_Class_Obj: Root_Class := T2_Class_Obj;

    T3_Obj: T3 := Make;
    T3_Class_Obj: T3_Class := T3_Obj;
    T3_Root_Class_Obj: Root_Class := T3_Obj;

    T4_Obj: T4 := Make;
    T4_Class_Obj: T4_Class := T4_Obj;
    T4_Root_Class_Obj: Root_Class := T4_Obj;

begin
    Test("C731001_1", "Check that inherited operations can be overridden, even"
                    & " when they are inherited in a body");

    Check_String(Op1(Root_Obj), "Parent.Op1 body");
    Check_String(Op1(Root_Class_Obj), "Parent.Op1 body");

    Check_String(Call_Op2(Root_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(Root_Class_Obj), "Parent.Op2 body");

    Check_String(Op1(T2_Obj), "Parent.Op1 body");
    Check_String(Op1(T2_Class_Obj), "Parent.Op1 body");
    Check_String(Op1(T2_Root_Class_Obj), "Parent.Op1 body");

    Check_String(Op2(T2_Obj), "Unrelated.Op2 body");
    Check_String(Op2(T2_Class_Obj), "Unrelated.Op2 body");
    Check_String(Call_Op2(T2_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T2_Class_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T2_Root_Class_Obj), "Parent.Op2 body");

    Check_String(Op1(T3_Obj), "Parent.Op1 body");
    Check_String(Op1(T3_Class_Obj), "Parent.Op1 body");
    Check_String(Op1(T3_Root_Class_Obj), "Parent.Op1 body");

    Check_String(Call_Op2(T3_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T3_Class_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T3_Root_Class_Obj), "Parent.Op2 body");

    Check_String(Op1(T4_Obj), "Parent.Op1 body");
    Check_String(Op1(T4_Class_Obj), "Parent.Op1 body");
    Check_String(Op1(T4_Root_Class_Obj), "Parent.Op1 body");

    Check_String(Call_Op2(T4_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T4_Class_Obj), "Parent.Op2 body");
    Check_String(Call_Op2(T4_Root_Class_Obj), "Parent.Op2 body");

    Result;
end C731001_1.Parent.Main;
