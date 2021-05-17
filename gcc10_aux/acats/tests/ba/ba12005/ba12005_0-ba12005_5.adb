
     --=================================================================--

with BA12005_0.BA12005_1.BA12005_2;                                  -- ERROR:
                                                   -- not a child of BA12005_0

package body BA12005_0.BA12005_5 is

   procedure Second_Proc   
     (Second_Child : in out Parent_Type) is
   begin
      Second_Child := Second_Child * Second_Child;

       -- Real body of procedure goes here.

   end Second_Proc;

end BA12005_0.BA12005_5;
