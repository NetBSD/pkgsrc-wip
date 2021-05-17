
with TCTouch;
package body C3A0007_2 is
   procedure Emergency (B : in out C3A0007_0.Button'Class) is
      begin
        TCTouch.Touch( 'E' ); ------------------------------------------- E
        Emergency_Call := True;
      end Emergency;
end C3A0007_2;
