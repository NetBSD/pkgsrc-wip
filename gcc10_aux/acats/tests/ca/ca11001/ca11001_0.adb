
--=======================================================================--

package body CA11001_0 is  -- Cartesian_Complex

   procedure Cartesian_Assign (R, I : in     Complex_Int; 
                               C    :    out Complex_Type) is
   begin
      C.Real      := R;
      C.Imaginary := I;
   end Cartesian_Assign;
   -------------------------------------------------------------
   function Cartesian_Real_Part (C : Complex_Type) 
     return Complex_Int is
   begin
      return C.Real;
   end Cartesian_Real_Part;
   -------------------------------------------------------------
   function Cartesian_Imag_Part (C : Complex_Type) 
     return Complex_Int is
   begin
      return C.Imaginary;
   end Cartesian_Imag_Part;
   -------------------------------------------------------------
   function Complex (Real, Imaginary : Complex_Int)
     return Complex_Type is
   begin
      return (Real, Imaginary);
   end Complex;

end CA11001_0;      -- Cartesian_Complex
