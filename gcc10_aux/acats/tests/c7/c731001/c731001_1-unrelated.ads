
with C731001_1.Parent; use C731001_1.Parent;
private package C731001_1.Unrelated is

    type T2 is new Root with null record;
    subtype T2_Class is T2'Class;
    function Make return T2;
    function Op2(X: T2) return String;
end C731001_1.Unrelated;
