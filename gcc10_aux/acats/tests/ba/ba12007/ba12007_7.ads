

-- No body provided for BA12007_6.

     --=================================================================--

with BA12007_0.BA12007_1.BA12007_4;     -- generic grandchild package
                                        -- implicit with BA12007_0,     
                                        -- BA12007_0.BA12007_1
package BA12007_7 is

   -- Instantiate the public grandchild.

   package Grandchild_Pkg is new BA12007_0.BA12007_1.BA12007_4;  

   Client_Var6 : BA12007_0.Parent_Type                            -- OK.
               := Grandchild_Pkg.Generic_Grandchild_Var1;  

   Client_Var7 : BA12007_0.BA12007_1.Child_Type                   -- OK.
               := Grandchild_Pkg.Generic_Grandchild_Var2;       

end BA12007_7;
