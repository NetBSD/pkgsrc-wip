
     --=================================================================--

with BA12005_0.BA12005_1.BA12005_2;             -- OK

with BA12005_0.BA12005_1.BA12005_2.BA12005_3;   -- OK

package body BA12005_0.BA12005_1.BA12005_4 is

   procedure First_Proc (Grandchild : out Parent_Type) is
                        -- reference to parent

      A, B : BA12005_0.BA12005_1.BA12005_2.Grandchild_Type;
                        -- reference to private sibling
   begin

      Grandchild := BA12005_0.BA12005_1.BA12005_2.BA12005_3 (A, B);
                       -- reference to public niece

       -- Real body of procedure goes here.

   end First_Proc;

end BA12005_0.BA12005_1.BA12005_4;
