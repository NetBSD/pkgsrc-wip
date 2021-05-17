

-- No body provided for BA12007_5.


     --=================================================================--

with BA12007_0.BA12007_1.BA12007_3;     -- public grandchild function
                                        -- implicit with BA12007_0,     
                                        -- BA12007_0.BA12007_1
package BA12007_6 is

   Client_Var3 : BA12007_0.Parent_Type;                           -- OK.

   Client_Var4 : BA12007_0.BA12007_1.Child_Type;                  -- OK.

   Client_Var5 : BA12007_0.BA12007_1.Child_Type
               := BA12007_0.BA12007_1.BA12007_3 (Client_Var4);    -- OK.

end BA12007_6;
