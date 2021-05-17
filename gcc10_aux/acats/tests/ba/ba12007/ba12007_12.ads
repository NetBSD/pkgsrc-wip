

-- No body provided for BA12007_11.

     --=================================================================--

with BA12007_9;                         -- rename declaration of public
                                        -- grandchild function.
                                        -- BA12007_0, BA12007_0.BA12007_1
                                        -- CANNOT be referenced.

package BA12007_12 is

   Test_Var3 : BA12007_0.Parent_Type;                             -- ERROR:
                                                  -- BA12007_0 not visible.

   Test_Var4 : BA12007_0.BA12007_1.Child_Type;                    -- ERROR:
                                        -- BA12007_0.BA12007_1 not visible.
end BA12007_12;
