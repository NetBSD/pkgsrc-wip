
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body CC40001_0 is

  procedure User_Operation( COB: in out Simple_Object; Name : String ) is
  begin
    COB.Name := Ada.Strings.Unbounded.To_Unbounded_String(Name);
  end User_Operation;

  procedure Initialize( COB: in out Simple_Object ) is
  begin
    COB.TC_Current_State := Initialized;
  end Initialize;

  procedure Adjust    ( COB: in out Simple_Object ) is
  begin
    COB.TC_Current_State := Adjusted;
    TCTouch.Touch('A');  -------------------------------------------------- A
    TCTouch.Touch(COB.ID); ------------------------------------------------ ID
    -- note that the calls to touch will not be directly validated, it is
    -- expected that some number > 0 of calls will be made to this procedure,
    -- the subtests then clear (Flush) the Touch buffer and perform actions
    -- where an incorrect implementation might call this procedure.  Such a
    -- call will fail on the attempt to "Validate" the null string.
  end Adjust;

  procedure Finalize  ( COB: in out Simple_Object ) is
  begin
    COB.TC_Current_State := Erroneous;
    Finalization_Count := Finalization_Count +1;
  end Finalize;

  TC_Global_Object : Simple_Object('G');

end CC40001_0;
