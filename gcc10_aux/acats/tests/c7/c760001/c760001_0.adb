
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760001_0 is

  Global_Unique_Counter : Unique_ID := 0;
  
  function Unique_Value return Unique_ID is
  begin
    Global_Unique_Counter := Global_Unique_Counter +1;
    return Global_Unique_Counter;
  end Unique_Value;
  
  function Most_Recent_Unique_Value return Unique_ID is
  begin
    return Global_Unique_Counter;
  end Most_Recent_Unique_Value;
  
  procedure Initialize( R: in out Root_Controlled ) is
  begin
    if TC_Initialize_Calls_Is_Failing then
      Report.Failed("Initialized incorrectly called");
    end if;
    R.My_Init_ID := Unique_Value;
  end Initialize;

  procedure Adjust( R: in out Root_Controlled ) is
  begin
    R.My_Adj_ID := Unique_Value;
  end Adjust;

end C760001_0;
