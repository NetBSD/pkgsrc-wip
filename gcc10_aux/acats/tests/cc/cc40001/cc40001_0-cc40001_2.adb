
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body CC40001_0.CC40001_2 is

  procedure TC_Verify_State is
  begin
    if TC_Check_Object.TC_Current_State /= Adjusted then
      Report.Failed( "CC40001_2 : Formal Object not adjusted" );
    end if;
  end TC_Verify_State;

end CC40001_0.CC40001_2;
