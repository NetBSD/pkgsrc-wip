
--=======================================================================--

package CA11001_0.CA11001_1 is    -- Polar_Complex
--  This public child provides a different view of the private type from its
--  parent.  It provides a polar view by the provision of subprograms which
--  construct and decompose a complex number.

   procedure Polar_Assign (R, Theta : in     Complex_Int; 
                           C        :    out Complex_Type);  
                                             -- Complex_Type is a 
                                             -- record of CA11001_0

   function Polar_Real_Part (C: Complex_Type) return Complex_Int;           

   function Polar_Imag_Part (C: Complex_Type) return Complex_Int;

   function Equals_Const (Num : Complex_Type) return Boolean;

end CA11001_0.CA11001_1;    -- Polar_Complex
