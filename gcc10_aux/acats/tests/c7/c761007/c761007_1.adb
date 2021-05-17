 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C761007_1 is

  procedure Finalize( C: in out Container ) is
    Previous_Side_Effect : Boolean := False;
  begin
    -- look to see if this character has been finalized yet
    for SEI in 1..Side_Effect_Finger loop
      Previous_Side_Effect := Previous_Side_Effect
                              or Side_Effect(Side_Effect_Finger) = C.Effect;
    end loop;

    -- if not, then tack it on to the string, and touch the character
    if not Previous_Side_Effect then
      Side_Effect_Finger := Side_Effect_Finger +1;
      Side_Effect(Side_Effect_Finger) := C.Effect;
      TCTouch.Touch(C.Effect);
    end if;

    raise This_Exception_Is_Supposed_To_Be_Ignored;

  end Finalize;

end C761007_1;
