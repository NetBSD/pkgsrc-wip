

with CC30003_Root;
package CC30003_1 is
   type Rectangle is new CC30003_Root.Object with
      record
         Height, Width : Float;
      end record;

   function Area (R : Rectangle) return Float;

end CC30003_1;
