
--=======================================================================--

with Report;

package body FA11D00.CA11D010 is     -- Add_Subtract_Complex

   procedure Add (Left, Right : in Complex_Type;
                  C           :    out Complex_Type) is
   begin
      -- Zero is declared in parent package.

      if Left.Real < Zero.Real or else Right.Real < Zero.Real
        or else Left.Imag < Zero.Imag or else Right.Imag < Zero.Imag then
          raise Add_Error;     -- Reference to exception in parent package.
          Report.Failed ("Program control not transferred by raise in " &
                         "procedure Add");
      else
         C.Real := (Left.Real + Right.Real);
         C.Imag := (Left.Imag + Right.Imag);
      end if;

   exception
      when Add_Error => 
         TC_Handled_In_Child_Pkg_Proc := true;
         C := Check_Value;           -- Reference to object in parent package.
         raise;     -- Reraise the Add_Error exception in the subtest.
         Report.Failed ("Exception not reraised in handler");

      when others    =>
         Report.Failed ("Unexpected exception raised in Add");

   end Add;
   -----------------------------------------------------------
   function Subtract (Left, Right : Complex_Type) 
     return Complex_Type is
   begin
      -- Zero is declared in parent package.
      if Left.Real < Zero.Real or Right.Real < Zero.Real
        or Left.Imag < Zero.Imag or Right.Imag < Zero.Imag then
          raise Subtract_Error;    -- Reference to exception in parent package. 
          Report.Failed ("Program control not transferred by raise in " &
                         "function Subtract");
      else
         return ( Real => (Left.Real - Right.Real),
                  Imag => (Left.Imag - Right.Imag) );
      end if;

   exception
      when Subtract_Error => 
         Report.Comment ("Exception is properly handled in Subtract");
         TC_Handled_In_Child_Pkg_Func := true;
         return Check_Value;

      when others         =>
         Report.Failed ("Unexpected exception raised in Subtract");

   end Subtract;

end FA11D00.CA11D010;     -- Add_Subtract_Complex
