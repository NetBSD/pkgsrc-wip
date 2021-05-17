

-----------------------------------------------------------------------------


package body C3A0011_0 is

   function Heading return Compass_Point is
   begin
     return The_Heading;
   end Heading;

   procedure Rotate_Left is
   begin
      The_Heading := The_Heading - 90;
   end Rotate_Left;


   procedure Rotate_Right is
   begin
      The_Heading := The_Heading + 90;
   end Rotate_Right;


   procedure Center is
   begin
      The_Heading := 0;
   end Center;

end C3A0011_0;
