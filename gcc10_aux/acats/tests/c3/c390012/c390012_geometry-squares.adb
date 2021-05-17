
with TCTouch;
with C390012_Manager;
with Ada.Numerics;
package body C390012_Geometry.Squares is

   function Make_Object (P : not null access Params) return Square is
   begin
      TCTouch.Touch ('M'); TCTouch.Touch ('S'); ------------------ "MS"
      return Square'(X_Coord => P.X_Coord, Y_Coord => P.Y_Coord,
                     Side    => P.Size);
   end Make_Object;

   function Area (S : in Square) return Float is
   begin
      TCTouch.Touch ('A'); TCTouch.Touch ('S'); ------------------ "AS"
      return S.Side**2;
   end Area;

   function Name (S : in Square) return String is
   begin
      return "Square";
   end Name;

   function Size_Param (S : in Square) return Float is
   begin
      return S.Side;
   end Size_Param;


begin
   C390012_Manager.Register (Square'Tag, 'S'); -- Register the Square type.
end C390012_Geometry.Squares;
