
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body CC40001_0.CC40001_4 is

  procedure TC_Verify_State is
  begin
    if Bad_Status( TC_Check_Object ) then
      Report.Failed( "CC40001_4 : Formal Object not adjusted" );
    end if;
  end TC_Verify_State;

end CC40001_0.CC40001_4;
