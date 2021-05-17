
with B7310016_1.Parent; use B7310016_1.Parent;
package B7310016_1.Unrelated is
    type T2 is new Root with null record;
    procedure Op2(X : T2);
    T2_Var: T2;
end B7310016_1.Unrelated;
