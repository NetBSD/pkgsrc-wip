
-----------------------------------------------------------------------------

with TCTouch;
package body C3A0007_0 is

   procedure Push (B : in out Button) is
   begin
      TCTouch.Touch( 'P' ); --------------------------------------------- P
      -- Invoking subprogram designated by access value
      B.Action (B);
   end Push;


   procedure Set_Response (B : in out Button;
                           R : in     Button_Response_Ptr) is
   begin
      TCTouch.Touch( 'S' ); --------------------------------------------- S
      -- Set procedure value in record
      B.Action := R;
   end Set_Response;


   procedure Response (B : in out Button) is
   begin
      TCTouch.Touch( 'D' ); --------------------------------------------- D
      Default_Call := True;
   end Response;

   procedure Default_Response (B : in out Button'Class) is
   begin
      TCTouch.Touch( 'C' ); --------------------------------------------- C
      Response(B);
   end Default_Response;

end C3A0007_0;
