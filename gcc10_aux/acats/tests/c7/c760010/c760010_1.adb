 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760010_1 is

  Initialize_Called : Natural;
  Adjust_Called     : Natural;
  Finalize_Called   : Natural;

  procedure Check_Counters(Init,Adj,Fin : Natural; Message: String) is
  begin
    if Init /= Initialize_Called then
      Report.Failed("Initialize mismatch " & Message);
    end if;
    if Adj /= Adjust_Called then
      Report.Failed("Adjust mismatch " & Message);
    end if;
    if Fin /= Finalize_Called then
      Report.Failed("Finalize mismatch " & Message);
    end if;
  end Check_Counters;

  procedure Reset_Counters is
  begin
    Initialize_Called := 0;
    Adjust_Called     := 0;
    Finalize_Called   := 0;
  end Reset_Counters;

  procedure Initialize( AV: in out Simple_Control ) is
  begin
    Initialize_Called := Initialize_Called +1;
    AV.Item := 0;
  end Initialize;

  procedure Adjust    ( AV: in out Simple_Control ) is
  begin
    Adjust_Called := Adjust_Called +1;
    AV.Item := AV.Item +1;
  end Adjust;

  procedure Finalize  ( AV: in out Simple_Control ) is
  begin
    Finalize_Called := Finalize_Called +1;
    AV.Item := AV.Item +1;
  end Finalize;

end C760010_1;
