
     --==================================================================--

separate (BA13B02_0.BA13B02_2)

function Public_Child_Func return Parent_Integer is

   Child_Var1 : FA13B00_0.Visible_Integer                            -- OK.
              := FA13B00_0.Visible_Num;   

   Child_Var2 : FA13B00_0.Visible_Integer                             
              := FA13B00_0.Private_Num;                              -- ERROR:
                             -- private var. of package with'ed by the subunit 
                             -- parent's body

   Child_Var3 : FA13B00_0.Private_Record                             
              := (VI => 3);                                          -- ERROR:
                             -- private record component of package with'ed by 
                             -- the subunit parent's body

   Child_Var4 : FA13B00_0.Private_Tagged;                            -- OK.

   Child_Var5 : FA13B00_0.Private_Tagged
              := FA13B00_0.Assign_Private_Tagged                     
                    (Child_Var4.VI);                                 -- ERROR:
                             -- private record component of package with'ed by
                             -- the subunit parent's body

   Child_Var6 : FA13B00_0.Visible_Tagged;                            -- OK.

   Child_Var7 : FA13B00_0.Visible_Tagged   
              := FA13B00_0.Assign_Visible_Tagged
                    (Child_Var6.PR.VI);                              -- ERROR:
                             -- private record component of package with'ed by
                             -- the subunit parent's body

   -------------------------------------------------------------------------

   Child_Var8 :  BA13B02_0.BA13B02_1.Child_Pri_Ext;                  -- OK.

   Child_Var9 :  BA13B02_0.BA13B02_1.Child_Private
              := BA13B02_0.BA13B02_1.Assign_Integer (Child_Var8.PI); -- ERROR:
                             -- private subprogram from public sibling of the
                             -- subunit parent's body
                                                          
   Child_Var10 : BA13B02_0.BA13B02_1.Child_Vis_Ext;                  -- OK.

   Child_Var11 : BA13B02_0.BA13B02_1.Child_Vis_Ext                 
               := BA13B02_0.BA13B02_1.Assign_Color 
                    (Child_Var10.CR.VC);                             -- ERROR:
                             -- private record component from public sibling 
                             -- of the subunit parent's body

begin
   return 29;
   -- Real body of function goes here.

end Public_Child_Func;
