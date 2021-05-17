

-- No body provided for BA12007_12.

     --=================================================================--

with BA12007_10;                        -- rename declaration of public
                                        -- generic package.
                                        -- BA12007_0, BA12007_0.BA12007_1
                                        -- CANNOT be referenced.

package BA12007_13 is

   -- Instantiate the public grandchild.

   package Grandchild_Pkg is new BA12007_10;

   Test_Var5 : BA12007_0.Parent_Type                              -- ERROR:
                                                  -- BA12007_0 not visible.
               := Grandchild_Pkg.Generic_Grandchild_Var1;  

   Test_Var6 : BA12007_0.BA12007_1.Child_Type                    -- ERROR:
                                       -- BA12007_0.BA12007_1 not visible.
               := Grandchild_Pkg.Generic_Grandchild_Var2;  

end BA12007_13;
