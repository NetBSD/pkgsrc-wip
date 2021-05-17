
--=======================================================================--

package body CA11001_0.CA11001_1 is   -- Polar_Complex

   function Cos (Angle : Complex_Int) return Complex_Int is
      Num : constant Complex_Int := 2;
   begin
      return (Angle * Num);   -- not true Cosine function
   end Cos;
   -------------------------------------------------------------
   function Sine (Angle : Complex_Int) return Complex_Int is
   begin
      return 1;     -- not true Sine function
   end Sine;
   -------------------------------------------------------------
   function Sqrt (Num : Complex_Int) 
     return Complex_Int is
   begin
     return (Num);     -- not true Square root function
   end Sqrt;
   -------------------------------------------------------------
   function Tan  (Angle : Complex_Int) return Complex_Int is
   begin
     return Angle;     -- not true Tangent function
   end Tan;
   -------------------------------------------------------------
   procedure Polar_Assign (R, Theta : in     Complex_Int;  
                           C        :    out Complex_Type) is 
   begin
      if R = 0 and Theta = 0 then
         raise Complex_Error;
      end if;
      C.Real := R * Cos (Theta);
      C.Imaginary := R * Sine (Theta);
   end Polar_Assign;
   -------------------------------------------------------------
   function Polar_Real_Part (C: Complex_Type) return Complex_Int is
   begin
      return Sqrt ((Cartesian_Imag_Part (C)) ** 2 + 
                   (Cartesian_Real_Part (C)) ** 2);
   end Polar_Real_Part;
   -------------------------------------------------------------
   function Polar_Imag_Part (C: Complex_Type) return Complex_Int is
   begin
      return (Tan (Cartesian_Imag_Part (C) / 
              Cartesian_Real_Part (C)));
   end Polar_Imag_Part;
   -------------------------------------------------------------
   function Equals_Const (Num : Complex_Type) return Boolean is
   begin
      return Num.Real = Constant_Complex.Real and
         Num.Imaginary = Constant_Complex.Imaginary;
   end Equals_Const;

end CA11001_0.CA11001_1;     -- Polar_Complex
