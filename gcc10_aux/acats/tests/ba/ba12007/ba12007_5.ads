

-- No body provided for BA12007_0.BA12007_1.BA12007_4.


     --=================================================================--

with BA12007_0.BA12007_1.BA12007_2;     -- public grandchild package
                                        -- implicit with BA12007_0,     
                                        -- BA12007_0.BA12007_1
package BA12007_5 is

   Client_Var1 : BA12007_0.Parent_Type                            -- OK.
               := BA12007_0.BA12007_1.BA12007_2.Grand_Child_Var1;  

   Client_Var2 : BA12007_0.BA12007_1.Child_Type                   -- OK.
               := BA12007_0.BA12007_1.BA12007_2.Grand_Child_Var2;  

end BA12007_5;
