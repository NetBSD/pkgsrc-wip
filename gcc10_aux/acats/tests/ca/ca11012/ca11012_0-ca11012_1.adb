
     --==================================================================--

package body CA11012_0.CA11012_1 is

   function Real_Part (Complex_No : Complex_Type) return Int_Type is
   begin
      return (Complex_No.Real);
   end Real_Part;
   ---------------------------------------------------------------
   function Imag_Part (Complex_No : Complex_Type) return Int_Type is
   begin
      return (Complex_No.Imag);
   end Imag_Part;
   ---------------------------------------------------------------
   function "*" (Factor : Int_Type; 
                 C      : Complex_Type) return Complex_Type is
      Result : Complex_Type := Zero;   -- Zero is declared in parent,
                                       -- Complex_Number
   begin
      for I in 1 .. abs (Factor) loop
         Result := Result + C;         -- Complex_Number "+"
      end loop;

      if Factor < 0 then
         Result := - Result;           -- Complex_Number "-"
      end if;

      return Result;
   end "*";
   ---------------------------------------------------------------
   function Vector_Magnitude (Complex_No : Complex_Type)
     return Int_Type is                -- Not a real vector magnitude.
   begin
      return (Complex_No.Real + Complex_No.Imag);
   end Vector_Magnitude;  

end CA11012_0.CA11012_1;
