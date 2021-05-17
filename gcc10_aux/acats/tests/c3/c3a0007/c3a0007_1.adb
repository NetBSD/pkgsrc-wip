
with TCTouch;
package body C3A0007_1 is

   procedure Set_Priority (B : in out Priority_Button) is
   begin
      TCTouch.Touch( 's' ); --------------------------------------------- s
      B.Priority := 1;
   end Set_Priority;

   procedure Response (B : in out Priority_Button) is
   begin
      TCTouch.Touch( 'd' ); --------------------------------------------- d
   end Response;

end C3A0007_1;
