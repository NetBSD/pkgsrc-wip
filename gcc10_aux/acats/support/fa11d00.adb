
--=======================================================================--

package body FA11D00 is  -- Complex_Definition_Pkg
   function Complex (Real, Imag : Int_Type) return Complex_Type is
   begin
      return (Real, Imag);
   end Complex;

end FA11D00;     -- Complex_Definition_Pkg
