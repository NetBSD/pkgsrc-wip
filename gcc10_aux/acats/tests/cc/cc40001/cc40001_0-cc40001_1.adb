
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body CC40001_0.CC40001_1 is

  procedure Initialize( COB: in out Object_In_Time ) is
  begin
    COB.TC_Current_State := Initialized;
    COB.Birth := Ada.Calendar.Clock;
  end Initialize;

  procedure Adjust    ( COB: in out Object_In_Time ) is
  begin
    COB.TC_Current_State := Adjusted;
    TCTouch.Touch('a');    ------------------------------------------------ a
    TCTouch.Touch(COB.ID); ------------------------------------------------ ID
  end Adjust;

  procedure Finalize  ( COB: in out Object_In_Time ) is
  begin
    COB.TC_Current_State := Erroneous;
    Finalization_Count := Finalization_Count +1;
  end Finalize;

  procedure User_Operation( COB: in out Object_In_Time;
                           Name: String ) is
  begin
    CC40001_0.User_Operation( Simple_Object(COB), Name );
    COB.Activity := Ada.Calendar.Clock;
    COB.TC_Current_State := Reset;
  end User_Operation;

  TC_Time_Object  : Object_In_Time('g');

end CC40001_0.CC40001_1;
