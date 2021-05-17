
     --==================================================================--

package body CA11021_0.CA11021_1 is

   function "+" (Left, Right : Complex_Type)              
     return Complex_Type is

   begin
      return ( (Left.Real + Right.Real, Left.Imag + Right.Imag) );
   end "+";

               --------------------------------------------------

   function "-" (Right : Complex_Type) return Complex_Type is
   begin
      return (-Right.Real, -Right.Imag);
   end "-";

end CA11021_0.CA11021_1;
