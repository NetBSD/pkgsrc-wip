

package body C640002P is

   function Image (L : Unit) return String is
   begin
      return Float'Image (Float (L)) (1 .. 4) & " (Unit)";
   end Image;

   function "*" (L, R : Unit) return Unit_Squared is    -- (2)
   begin
      return Unit_Squared (Float (L) * Float (R));
   end "*";

   function Image (L : Unit_Squared) return String is
   begin
      return Float'Image (Float (L)) (1 .. 4) & " (Unit_Squared)";
   end Image;
end C640002P;
