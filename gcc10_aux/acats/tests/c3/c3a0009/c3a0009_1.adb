
with TCTouch;
package body C3A0009_1 is -- Emergency_Items
   procedure Emergency (B : in out Push_Buttons.Button) is
      begin
        TCTouch.Touch( 'E' ); ------------------------------------------- E
      end Emergency;
end C3A0009_1;
