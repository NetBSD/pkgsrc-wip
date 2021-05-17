
with Report;
package body C760002_0 is

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

  procedure Initialize( R: in out Root ) is
  begin
    Report.Failed("Initialize called for Non_Controlled type");
  end Initialize;

  procedure Adjust    ( R: in out Root ) is
  begin
    Report.Failed("Adjust called for Non_Controlled type");
  end Adjust;

  procedure Initialize( R: in out Root_Controlled ) is
  begin
    R.Visit_Tag := 'I'; --------------------------------------------------- I
  end Initialize;

  procedure Adjust( R: in out Root_Controlled ) is
  begin
    R.Visit_Tag := 'A'; --------------------------------------------------- A
  end Adjust;

  procedure Initialize( R: in out Root_Limited_Controlled ) is
  begin
    R.Visit_Tag := 'i'; --------------------------------------------------- i
  end Initialize;

  procedure Adjust( R: in out Root_Limited_Controlled ) is
  begin
    Report.Failed("Adjust called for Limited_Controlled type");
  end Adjust;

end C760002_0;
