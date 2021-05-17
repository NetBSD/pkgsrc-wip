 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760009_1 is

  -- Maintenance_Mode and TC_Trace are for the test writers and compiler
  -- developers to get more information from this test as it executes.
  -- Maintenance_Mode is always False for validation purposes.

  Maintenance_Mode : constant Boolean := False;

  procedure TC_Trace( Message: String ) is
  begin
    if Maintenance_Mode then
      Report.Comment( Message );
    end if;
  end TC_Trace;

  procedure Reset_Counters is
  begin
    Initialize_Called := 0;
    Adjust_Called     := 0;
    Finalize_Called   := 0;
  end Reset_Counters;

  Master_Count : Natural := 100;  -- Help distinguish values

  procedure Initialize( AV: in out Simple_Control ) is
  begin
    Initialize_Called := Initialize_Called +1;
    AV.Item := Master_Count;
    Master_Count := Master_Count +100;
    TC_Trace( "Initialize _1.Simple_Control" );
  end Initialize;

  procedure Adjust    ( AV: in out Simple_Control ) is
  begin
    Adjust_Called := Adjust_Called +1;
    AV.Item := AV.Item +1;
    TC_Trace( "Adjust _1.Simple_Control" );
  end Adjust;

  procedure Finalize  ( AV: in out Simple_Control ) is
  begin
    Finalize_Called := Finalize_Called +1;
    AV.Item := AV.Item +1;
    TC_Trace( "Finalize _1.Simple_Control" );
  end Finalize;

  procedure Validate  ( AV: in out Simple_Control ) is
  begin
    Report.Failed("Attempt to Validate at Simple_Control level");
  end Validate;

  function Item( AV: Simple_Control'Class ) return String is
  begin
    return Natural'Image(AV.Item);
  end Item;

end C760009_1;
