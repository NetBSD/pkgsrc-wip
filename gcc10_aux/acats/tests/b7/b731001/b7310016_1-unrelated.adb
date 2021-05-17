
package body B7310016_1.Unrelated is
    procedure Op2(X : T2) is
    begin
        null;
    end Op2;
begin
    Op1(T2_Var); -- OK -- inherited from Root.  See AARM-7.3.1(7.m).
    Op2(T2_Var); -- OK -- unrelated to inherited one.
end B7310016_1.Unrelated;
