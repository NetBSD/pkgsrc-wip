
with Report; use Report; pragma Elaborate_All(Report);
with CA15003A.Pure_Instance;
with CA15003A.Pure_Preelaborate_Instance;
use CA15003A;
package body CA15003A.Empty_Elaborate_Body is
begin
    if Two /= Big_Positive'Base(Ident_Int(0)) then
	Failed ("Two should be zero now");
    end if;
    if Tres /= Big_Positive'Base(Ident_Int(0)) then
	Failed ("Tres should be zero now");
    end if;
    if Two /= Tres then
	Failed ("Tres should be zero now");
    end if;
    Two := Pure_Instance.F(Three'Access);
    Tres := Pure_Preelaborate_Instance.F(Three'Access);
    if Two /= Big_Positive(Ident_Int(2)) then
	Failed ("Two should be 2 now");
    end if;
    if Tres /= Big_Positive(Ident_Int(3)) then
	Failed ("Tres should be 3 now");
    end if;
end CA15003A.Empty_Elaborate_Body;
