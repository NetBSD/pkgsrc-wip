
     --==================================================================--

package body CA11012_0 is

   function Complex (Real, Imag : Int_Type) return Complex_Type is
   begin
      return (Real, Imag);
   end Complex;
   ---------------------------------------------------------------
   function "-" (Right : Complex_Type) return Complex_Type is
   begin
      return (-Right.Real, -Right.Imag);
   end "-";
   ---------------------------------------------------------------
   function "+" (Left, Right : Complex_Type) return Complex_Type is
   begin
      return ( (Left.Real + Right.Real, Left.Imag + Right.Imag) );
   end "+";

end CA11012_0;
