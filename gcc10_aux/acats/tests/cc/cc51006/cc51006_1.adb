

     --==================================================================--


package body CC51006_1 is


   -- The implementation of this procedure is purely artificial, and contains
   -- an artificial parameter for testing purposes: the procedure returns the
   -- weight string to the caller.

   procedure Output_Weight (Wt : in Weight; TC_Return : out String) is
   begin
      TC_Return := Weight_To_String (Wt);   -- Should always call root type's
   end Output_Weight;                       -- implementation.


end CC51006_1;
