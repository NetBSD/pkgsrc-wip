

     --==================================================================--


package body FC51A00 is

   function "/" (Left, Right : Integer) return Fraction_Type is
      Result : Fraction_Type;
   begin
      Result.Numerator   := Left;
      Result.Denominator := Right;
      return Result;
   end "/";


   function "-" (Frac : Fraction_Type) return Fraction_Type is
      Result : Fraction_Type := Frac;
   begin
      Result.Numerator := -(Result.Numerator);
      return Result;
   end "-";


   function Numerator (Frac : Fraction_Type) return Integer is
   begin
      return (Frac.Numerator);
   end Numerator;


   function Denominator (Frac : Fraction_Type) return Integer is
   begin
      return (Frac.Denominator);
   end Denominator;


end FC51A00;
