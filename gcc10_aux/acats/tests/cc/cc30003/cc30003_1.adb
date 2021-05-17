

with TCTouch;
package body CC30003_1 is

   function Area (R : Rectangle) return Float is
   begin
      TCTouch.Touch ('r'); ----------------------------------------- r
      TCTouch.Touch ('a'); ----------------------------------------- a
      return R.Height*R.Width;
   end Area;

end CC30003_1;
