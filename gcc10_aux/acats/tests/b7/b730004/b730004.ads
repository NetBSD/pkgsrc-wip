
-- No bodies provided for B730004_0.B730004_1.

     --=================================================================--

with B730004_0.B730004_1;     -- public child package
                              -- implicit with parent package (B730004_0).

package B730004 is

   Client_Var1 : B730004_0.Visible_Integer 
               := B730004_0.B730004_1.Visible_Integer_Num; -- OK
                                                    -- parent's visible type
   Client_Var2 : B730004_0.Visible_Integer 
               := B730004_0.Private_Integer_Num;                   -- ERROR:
                                                  -- parent's private object
   Client_Var3 : B730004_0.Private_Record
               := (VI => 3);                                       -- ERROR:
                                                    -- parent's private type

   Client_Var4 : B730004_0.Private_Tagged;                 -- OK

   Client_Var5 : B730004_0.Private_Tagged
               := B730004_0.B730004_1.Assign_Private_Tagged
                    (Client_Var4.VI);                              -- ERROR:
                                        -- parent's private record component

   Client_Var6 : B730004_0.Private_Extension;              -- OK

   Client_Var7 : B730004_0.Private_Extension
               := B730004_0.B730004_1.Assign_Private_Extension
                    (Client_Var6.VI);                              -- ERROR:
                                        -- parent's private record component

   Client_Var8 : B730004_0.Visible_Tagged;                 -- OK

   Client_Var9 : B730004_0.Visible_Tagged   
               := B730004_0.B730004_1.Assign_Visible_Tagged
                    (Client_Var8.PR.VI);                           -- ERROR:
                                        -- parent's private record component

   Client_Var10 : B730004_0.B730004_1.Child_Extension1;    -- OK

   Client_Var11 : B730004_0.B730004_1.Child_Extension1
                := B730004_0.B730004_1.Assign_Integer
                    (Client_Var10.VI);                     -- OK

   Client_Var12 : B730004_0.B730004_1.Child_Extension1
                := B730004_0.B730004_1.Assign_Child_Extension1
                    (Client_Var10.PR.VI);                          -- ERROR:
    -- child's extension from parent vis. tagged type with private component

   Client_Var13 : B730004_0.B730004_1.Child_Extension2;    -- OK

   Client_Var14 : B730004_0.B730004_1.Child_Extension2
                := B730004_0.B730004_1.Assign_Color 
                    (Client_Var13.C);                      -- OK

   Client_Var15 : B730004_0.B730004_1.Child_Extension2
                := B730004_0.B730004_1.Assign_Child_Extension2
                    (Client_Var13.VI);                             -- ERROR:
                        -- child's extension from parent private tagged type

end B730004;

-- No bodies provided for B730004.
