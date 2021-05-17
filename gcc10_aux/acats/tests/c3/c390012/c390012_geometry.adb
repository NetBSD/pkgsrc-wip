
with Ada.Numerics.Elementary_Functions;
package body C390012_Geometry is

   function Distance (O : in Object) return Float is
   begin
      return Ada.Numerics.Elementary_Functions.Sqrt (
          O.X_Coord ** 2 + O.Y_Coord ** 2);
   end Distance;

   function X_Coord (O : in Object) return Float is begin
      return O.X_Coord;
   end X_Coord;

   function Y_Coord (O : in Object) return Float is
   begin
      return O.Y_Coord;
   end Y_Coord;

end C390012_Geometry;
