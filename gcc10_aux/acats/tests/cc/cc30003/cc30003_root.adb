

with Ada.Numerics.Elementary_Functions;
package body CC30003_Root is
   function Distance (Obj : Object) return Float is
   begin
      return Ada.Numerics.Elementary_Functions.Sqrt(
              Obj.X_Coord ** 2 + Obj.Y_Coord ** 2);
   end Distance;
end CC30003_Root;
