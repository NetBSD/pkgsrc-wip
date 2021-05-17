

     --==================================================================--


package body CC51A01_1 is

   -- This body should never be called.
   --
   -- The test sends the function Numerator a fraction with a negative
   -- numerator, and expects this negative numerator to be returned. This
   -- version of the function returns the absolute value of the numerator.
   -- Thus, a call to this version is detectable by examining the sign
   -- of the return value.

   function Numerator (Frac : Pos_Fraction) return Integer is
      Converted_Frac : FC51A00.Fraction_Type := FC51A00.Fraction_Type (Frac);
      Orig_Numerator : Integer := FC51A00.Numerator (Converted_Frac);
   begin
      return abs (Orig_Numerator);
   end Numerator;

end CC51A01_1;
