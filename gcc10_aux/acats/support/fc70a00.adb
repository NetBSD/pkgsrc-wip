

     --==================================================================--


package body FC70A00 is  -- Complex integer abstraction.

   function Complex (Real, Imag : Int_Type) return Complex_Type is
   begin
      return ( (Real, Imag) );
   end Complex;

               --==============================================--

   function "-" (Right : Complex_Type) return Complex_Type is
   begin
      return ( (-Right.Real, -Right.Imag) );
   end "-";

               --==============================================--

   function "+" (Left, Right : Complex_Type) return Complex_Type is
   begin
      return ( (Left.Real + Right.Real, Left.Imag + Right.Imag) );
   end "+";

               --==============================================--

   function "*" (Left, Right : Complex_Type) return Complex_Type is
   begin
      return ( (Real => (Left.Real * Right.Real) - (Left.Imag * Right.Imag),
                Imag => (Left.Imag * Right.Real) + (Left.Real * Right.Imag)) );
   end "*";

               --==============================================--

   function Reciprocal (Right : Complex_Type) return Complex_Type is
      Denominator : Int_Type := Right.Real**2 + Right.Imag**2;
   begin  -- NOTE: Results are truncated.
      return ( (Right.Real/Denominator, -Right.Imag/Denominator) );
   end Reciprocal;

end FC70A00;
