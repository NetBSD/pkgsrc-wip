
package C390012_Geometry.Triangles is

   type Triangle is new Object with private;
      -- This is a bit of a misnomer; we only support right triangles here
      -- with the two right sides the same length.

   -- Concrete versions of abstract routines:
   function Make_Object (P : not null access Params) return Triangle;
      -- For a Triangle, the size is the (right) side of the Triangle.
   function Area (T : in Triangle) return Float;
   function Name (T : in Triangle) return String;
   function Size_Param (T : in Triangle) return Float;

private

   type Triangle is new Object with
      record
         Right_Side : Float;
      end record;

end C390012_Geometry.Triangles;
