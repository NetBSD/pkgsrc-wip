
     --=================================================================--

with BA12007_14;                  -- rename declaration of parent package.

with BA12007_0.BA12007_1.BA12007_2;     -- public grandchild package
                                        -- implicit with BA12007_0.
                                        
package BA12007_18 is

   Test_Var9 : BA12007_0.Parent_Type                            -- OK.
             := BA12007_14.BA12007_2.Grand_Child_Var1; 

end BA12007_18;

-- No body provided for BA12007_18.
