
separate(CA21001_1.F)
package body F_Sub is
    True_Var: Boolean;
begin
    True_Var := True;
    if True_Var then -- OK by AI-2.
        X := X;
    else
        X := X + 2;
    end if;
end F_Sub;
