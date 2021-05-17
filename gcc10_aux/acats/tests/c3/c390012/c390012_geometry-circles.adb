
with TCTouch;
with C390012_Manager;
with Ada.Numerics;
package body C390012_Geometry.Circles is

   function Make_Object (P : not null access Params) return Circle is
   begin
      TCTouch.Touch ('M'); TCTouch.Touch ('C'); ------------------ "MC"
      return Circle'(X_Coord => P.X_Coord, Y_Coord => P.Y_Coord,
                     Radius  => P.Size);
   end Make_Object;

   function Area (C : in Circle) return Float is
   begin
      TCTouch.Touch ('A'); TCTouch.Touch ('C'); ------------------ "AC"
      return Ada.Numerics.PI * C.Radius**2;
   end Area;

   function Name (C : in Circle) return String is
   begin
      return "Circle";
   end Name;

   function Size_Param (C : in Circle) return Float is
   begin
      return C.Radius;
   end Size_Param;

begin
   C390012_Manager.Register (Circle'Tag, 'C'); -- Register the Circle type.
end C390012_Geometry.Circles;
