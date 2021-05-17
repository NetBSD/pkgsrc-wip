
with TCTouch;
with C390012_Manager;
with Ada.Numerics;
package body C390012_Geometry.Triangles is

   function Make_Object (P : not null access Params) return Triangle is
   begin
      TCTouch.Touch ('M'); TCTouch.Touch ('T'); ------------------ "MT"
      return Triangle'(X_Coord => P.X_Coord, Y_Coord => P.Y_Coord,
                       Right_Side => P.Size);
   end Make_Object;

   function Area (T : in Triangle) return Float is
   begin
      TCTouch.Touch ('A'); TCTouch.Touch ('T'); ------------------ "AT"
      return T.Right_Side**2 / 2.0;
   end Area;

   function Name (T : in Triangle) return String is
   begin
      return "Triangle";
   end Name;

   function Size_Param (T : in Triangle) return Float is
   begin
      return T.Right_Side;
   end Size_Param;

begin
   C390012_Manager.Register (Triangle'Tag, 'T'); -- Register the Triangle type.
end C390012_Geometry.Triangles;
