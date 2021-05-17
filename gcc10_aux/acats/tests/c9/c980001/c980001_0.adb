 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body C980001_0 is

  TC_Master_Value : Integer := 0;


  function TC_Unique return Integer is  -- make all values unique.
  begin
    TC_Master_Value := TC_Master_Value +1;
    return TC_Master_Value;
  end TC_Unique;

  protected body Sticker is

    entry Lock when not Locked is
    begin
      Locked := True;
    end Lock;

    procedure Unlock is
    begin
      Locked := False;
    end Unlock;

    function Is_Locked return Boolean is
    begin
      return Locked;
    end Is_Locked;

  end Sticker;

  procedure Initialize( AV: in out Sticks_In_Initialize ) is
  begin
    TCTouch.Touch('I');  -------------------------------------------------- I
    Hold_Up.Unlock;               -- cause the select to abort
    Initialize_Called := True;
    AV.Item := TC_Unique;
    TCTouch.Touch('i');  -------------------------------------------------- i
    Progress.Unlock;              -- allows Wait_Your_Turn to continue
  end Initialize;

  procedure Adjust    ( AV: in out Sticks_In_Adjust ) is
  begin
    TCTouch.Touch('A');  -------------------------------------------------- A
    Hold_Up.Unlock;               -- cause the select to abort
    Adjust_Called := True;
    AV.Item := TC_Unique;
    TCTouch.Touch('a');  -------------------------------------------------- a
    Progress.Unlock;
  end Adjust;

  procedure Finalize  ( AV: in out Sticks_In_Finalize ) is
  begin
    TCTouch.Touch('F');  -------------------------------------------------- F
    Hold_Up.Unlock;               -- cause the select to abort
    Finalize_Called := True;
    AV.Item := TC_Unique;
    TCTouch.Touch('f');  -------------------------------------------------- f
    Progress.Unlock;
  end Finalize;

  procedure Fail_And_Clear( Message : String ) is
  begin
    Report.Failed(Message);
    Hold_Up.Unlock;
    Progress.Unlock;
  end Fail_And_Clear;

end C980001_0;
