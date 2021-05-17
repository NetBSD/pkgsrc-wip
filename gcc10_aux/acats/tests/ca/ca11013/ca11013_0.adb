
     --==================================================================--

package body CA11013_0 is

   function Make (Real, Imag : Real_Type) return Complex_Type is
   begin
      return (Real, Imag);
   end Make;
   -------------------------------------------------------------
   procedure Components (Complex_No           : in Complex_Type;
                         Real_Part, Imag_Part : out Real_Type) is
   begin
      Real_Part := Complex_No.Real;
      Imag_Part := Complex_No.Imag;
   end Components;

end CA11013_0;
