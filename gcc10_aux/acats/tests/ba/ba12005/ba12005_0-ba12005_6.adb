
     --=================================================================--

with BA12005_0.BA12005_1.BA12005_2;                                  -- ERROR:
                                                   -- not a child of BA12005_0

package body BA12005_0.BA12005_6 is

   procedure Third_Proc is
      Private_Child_Var : Parent_Type := 136;
   begin

      Private_Child_Var := Private_Child_Var + Private_Child_Var;

       -- Real body of procedure goes here.

   end Third_Proc;

end BA12005_0.BA12005_6;
