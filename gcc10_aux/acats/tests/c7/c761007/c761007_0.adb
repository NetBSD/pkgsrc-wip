 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C761007_0 is

  procedure Finalize( I : in out Internal ) is
    Previous_Side_Effect : Boolean := False;
  begin
    -- look to see if this character has been finalized yet
    for SEI in 1..Side_Effect_Finger loop
      Previous_Side_Effect := Previous_Side_Effect
                              or Side_Effect(Side_Effect_Finger) = I.Effect;
    end loop;

    -- if not, then tack it on to the string, and touch the character
    if not Previous_Side_Effect then
      Side_Effect_Finger := Side_Effect_Finger +1;
      Side_Effect(Side_Effect_Finger) := I.Effect;
      TCTouch.Touch(I.Effect);
    end if;

  end Finalize;

end C761007_0;
