
with Report; use Report;
with CA15003A.Empty_Pure;
with CA15003A.Empty_Preelaborate;
with CA15003A.Empty_Elaborate_Body; use CA15003A.Empty_Elaborate_Body;
use type CA15003A.Big_Positive'Base;
procedure CA15003 is
begin
    Test("CA15003", "Placement of Program Unit Pragmas in Generic Packages");
    if Two /= 2 then
	Failed ("Two should be 2 now");
    end if;
    if Tres /= 3 then
	Failed ("Tres should be 3 now");
    end if;
    Result;
end CA15003;
