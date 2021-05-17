
     --==================================================================--


with B3A2007_0;
with B3A2007_3;
procedure B3A2007 is

   type AT1_L1 is access all B3A2007_0.Tag_Desig;                 -- Level = 1.
   type AT2_L1 is access all B3A2007_0.Tag_Desig;                 -- Level = 1.
   type AT3_L1 is access all B3A2007_0.Tag_Desig;                 -- Level = 1.

   package Inst_L1_OK is
     new B3A2007_3 (B3A2007_0.Tag_Desig,
                    AT1_L1,
                    AT2_L1,
                    AT3_L1);                                 -- OK. {4:4;1}
       -- After the above instantiation of Inst_L1_OK:
       -- GAcc  : AT1_L1 := FObj'Access          (FObj level = 1)
       -- ARen  : AT2_L1 := Ren'Access           (Ren  level = 1)

   package Inst_L1_Obj is
     new B3A2007_3 (B3A2007_0.Tag_Desig,
                    B3A2007_0.AT1_L0,
                    AT2_L1,
                    AT3_L1);                                 -- ERROR: {4:4;1}
                          -- Accessibility level of FObj is deeper than that of
                          -- B3A2007_0.AT1_L0.
       -- After the above instantiation of Inst_L1_Obj:
       -- GAcc  : AT1_L0 := FObj'Access          (FObj level = 1)   <= Illegal
       -- ARen  : AT2_L1 := Ren'Access           (Ren  level = 1)


   package Inst_L1_Ren is
     new B3A2007_3 (B3A2007_0.Tag_Desig,
                    AT1_L1,
                    B3A2007_0.AT1_L0,
                    AT2_L1);                                 -- ERROR: {4:4;1}
                           -- Accessibility level of Ren is deeper than that of
                           -- B3A2007_0.AT1_L0.
       -- After the above instantiation of Inst_L1_Ren:
       -- GAcc  : AT1_L1 := FObj'Access          (FObj level = 1)
       -- ARen  : AT1_L0 := Ren'Access;          (Ren  level = 1)   <= Illegal


begin -- B3A2007

   First_Nested_Block:
   declare

      type AT1_L2 is access all B3A2007_0.Tag_Desig;              -- Level = 2.
      type AT2_L2 is access all B3A2007_0.Tag_Desig;              -- Level = 2.
      type AT3_L2 is access all B3A2007_0.Tag_Desig;              -- Level = 2.


      package Inst_L2_OK is
        new B3A2007_3 (B3A2007_0.Tag_Desig,
                       AT1_L2,
                       AT2_L2,
                       AT3_L2);                              -- OK. {4:7;1}
       -- After the above instantiation of Inst_L2_OK:
       -- GAcc  : AT1_L2 := FObj'Access          (FObj level = 2)
       -- ARen  : AT2_L2 := Ren'Access           (Ren  level = 2)

      package Inst_L2_Obj is
        new B3A2007_3 (B3A2007_0.Tag_Desig,
                       AT1_L1,
                       AT2_L2,
                       AT3_L2);                              -- ERROR: {4:7;1}
                  -- Accessibility level of FObj is deeper than that of AT1_L1.
       -- After the above instantiation of Inst_L2_Obj:
       -- GAcc  : AT1_L1 := FObj'Access          (FObj level = 2)   <= Illegal
       -- ARen  : AT2_L2 := Ren'Access           (Ren  level = 2)

      package Inst_L2_Ren is
        new B3A2007_3 (B3A2007_0.Tag_Desig,
                       AT1_L2,
                       B3A2007_0.AT1_L0,
                       AT3_L2);                              -- ERROR: {4:7;1}
                           -- Accessibility level of Ren is deeper than that of
                           -- B3A2007_0.AT1_L0.
       -- After the above instantiation of Inst_L2_Ren:
       -- GAcc  : AT1_L2 := FObj'Access          (FObj level = 2)
       -- ARen  : AT1_L0 := Ren'Access           (Ren  level = 2)   <= Illegal


   begin -- First_Nested.

      Doubly_Nested_Block:
      declare

         type AT1_L3 is access all B3A2007_0.Tag_Desig;           -- Level = 3.
         type AT2_L3 is access all B3A2007_0.Tag_Desig;           -- Level = 3.
         type AT3_L3 is access all B3A2007_0.Tag_Desig;           -- Level = 3.

         package Inst_L3_OK is
           new B3A2007_3 (B3A2007_0.Tag_Desig,
                          AT1_L3,
                          AT2_L3,
                          AT3_L3);                           -- OK. {4:10;1}
         -- After the above instantiation of Inst_L3_OK:
         -- GAcc  : AT1_L3 := FObj'Access          (FObj level = 3)
         -- ARen  : AT2_L3 := Ren'Access           (Ren  level = 3)

         package Inst_L3_Obj is
           new B3A2007_3 (B3A2007_0.Tag_Desig,
                          B3A2007_0.AT1_L0,
                          AT2_L3,
                          AT3_L3);                           -- ERROR: {4:10;1}
                         -- Accessibility level of TObj1 is deeper than that of
                         -- B3A2007_0.AT1_L0.
         -- After the above instantiation of Inst_L3_Obj:
         -- GAcc  : AT1_L0 := FObj'Access          (FObj level = 3) <= Illegal
         -- ARen  : AT2_L3 := Ren'Access           (Ren  level = 3)

         package Inst_L3_Ren is
           new B3A2007_3 (B3A2007_0.Tag_Desig,
                          AT1_L3,
                          AT2_L1,
                          AT3_L3);                           -- ERROR: {4:10;1}
                    -- Accessibility level of Ren is deeper than that of AT_L1.
         -- After the above instantiation of Inst_L3_Ren:
         -- GAcc  : AT1_L3 := FObj'Access          (FObj level = 3)
         -- ARen  : AT2_L1 := Ren'Access           (Ren  level = 3) <= Illegal


      begin -- Doubly_Nested_Block.
        null;
      end Doubly_Nested_Block;

   end First_Nested_Block;

end B3A2007;
