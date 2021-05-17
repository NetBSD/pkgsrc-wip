
--=======================================================================--

function FA11D00.CA11D012 (Left, Right : Complex_Type)
  return Complex_Type is                       -- Divide_Complex

begin
   -- Zero is declared in parent package.

   if Right.Real = Zero.Real or Right.Imag = Zero.Imag then
      raise Divide_Error;  -- Reference to exception in parent package. 
      Report.Failed ("Program control not transferred by raise in " &
                     "child function FA11D00.CA11D012");
   else
      return ( Real => (Left.Real / Right.Real),
               Imag => (Left.Imag / Right.Imag) );
   end if;

end FA11D00.CA11D012;     -- Divide_Complex
