

     --===================================================================--


package body B393004_0 is

   procedure Process (A: in out Child; B: in Field) is
   begin
      A.C := B;
   end Process;


   function Fetch (A: Child) return Field is
   begin
      return A.C;
   end Fetch;

end B393004_0;
