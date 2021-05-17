
--=======================================================================--

package body FA11D00.CA11D03_0 is     -- Basic_Complex

   function "+" (Left, Right : Complex_Type) return Complex_Type is
   begin
      return ( (Left.Real + Right.Real, Left.Imag + Right.Imag) );
   end "+";
   --------------------------------------------------------------
   function "*" (Left, Right : Complex_Type) return Complex_Type is
   begin
      return ( Real => (Left.Real * Right.Real),
               Imag => (Left.Imag * Right.Imag) );
   end "*";

end FA11D00.CA11D03_0;     -- Basic_Complex
