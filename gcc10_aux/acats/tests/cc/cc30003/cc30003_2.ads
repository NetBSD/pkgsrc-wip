

with CC30003_Root;
package CC30003_2 is
   type Right_Triangle is new CC30003_Root.Object with
      record
         A, B : Float;    -- Lengths of sides
      end record;

   function Area (T : Right_Triangle) return Float;

   function Hypotenuse (T : Right_Triangle) return Float;

   procedure Clear (T : in out Right_Triangle);

end CC30003_2;
