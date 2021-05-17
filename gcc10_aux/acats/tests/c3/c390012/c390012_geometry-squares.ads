
package C390012_Geometry.Squares is

   type Square is new Object with private;

   -- Concrete versions of abstract routines:
   function Make_Object (P : not null access Params) return Square;
      -- For a Square, the size is the side of the Square.
   function Area (S : in Square) return Float;
   function Name (S : in Square) return String;
   function Size_Param (S : in Square) return Float;

private

   type Square is new Object with
      record
         Side : Float;
      end record;

end C390012_Geometry.Squares;
