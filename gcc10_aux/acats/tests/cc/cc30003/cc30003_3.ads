

with CC30003_0;
with CC30003_1;
package CC30003_3 is

   package Counted_Rectangle_Inst is new CC30003_0 (CC30003_1.Rectangle);

   type Counted_Square is new Counted_Rectangle_Inst.Counted_Type
      with null record;

   procedure Make_Square (S : in out Counted_Square; Side : in Float);

   function Area (S : Counted_Square) return Float;

   procedure Bump (S : in out Counted_Square);

end CC30003_3;
