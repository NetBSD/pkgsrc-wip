

with TCTouch;
with Ada.Numerics.Elementary_Functions;
package body CC30003_2 is

   function Area (T : Right_Triangle) return Float is
   begin
      TCTouch.Touch ('t'); ----------------------------------------- t
      TCTouch.Touch ('a'); ----------------------------------------- a
      return (T.A * T.B) / 2.0;
   end Area;

   function Hypotenuse (T : Right_Triangle) return Float is
   begin
      TCTouch.Touch ('h'); ----------------------------------------- h
      return Ada.Numerics.Elementary_Functions.Sqrt(
              T.A ** 2 + T.B ** 2);
   end Hypotenuse;

   procedure Clear (T : in out Right_Triangle) is
   begin
      TCTouch.Touch ('t'); ----------------------------------------- t
      TCTouch.Touch ('c'); ----------------------------------------- c
      T.A := 0.0; T.B := 0.0;
   end Clear;

end CC30003_2;
