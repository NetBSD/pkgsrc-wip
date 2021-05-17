

     --=================================================================--

with BA12007_8;                         -- rename declaration of public
                                        -- grandchild package.
                                        -- BA12007_0, BA12007_0.BA12007_1
                                        -- CANNOT be referenced.

package BA12007_11 is

   Test_Var1 : BA12007_0.Parent_Type                              -- ERROR:
                                                  -- BA12007_0 not visible.
             := BA12007_8.Grand_Child_Var1;  

   Test_Var2 : BA12007_0.BA12007_1.Child_Type                     -- ERROR:
                                        -- BA12007_0.BA12007_1 not visible.
             := BA12007_8.Grand_Child_Var2;  

end BA12007_11;
