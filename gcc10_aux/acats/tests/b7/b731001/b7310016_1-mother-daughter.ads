
private package B7310016_1.Mother.Daughter is
    Root_Obj: Root;
    Root_Class_Obj: Root'Class := Root_Obj;
    X: String := Op1(Root_Obj); -- OK
    Y: String := Op1(Root_Class_Obj); -- OK
    XX: String := Op2(Root_Obj); -- OK
    YY: String := Op2(Root_Class_Obj); -- OK
private
    XXX: String := Op1(Root_Obj); -- OK
    YYY: String := Op1(Root_Class_Obj); -- OK
    XXXX: String := Op2(Root_Obj); -- OK
    YYYY: String := Op2(Root_Class_Obj); -- OK
end B7310016_1.Mother.Daughter;
