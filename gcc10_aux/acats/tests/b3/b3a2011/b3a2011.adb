

     --==================================================================--


with B3A2011_0;
with B3A2011_1;
procedure B3A2011 is

   type Acc_to_Tag_L1 is access constant B3A2011_0.Tag_Desig; -- Level = 1.
   TObj1_L1 : aliased B3A2011_0.Tag_Desig;                    -- Level = 1.
   TObj2_L1 : aliased B3A2011_0.Tag_Desig;                    -- Level = 1.

   package Inst_L1_OK is
     new B3A2011_1 (B3A2011_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj1_L0,
                    Acc_to_Tag_L1,
                    TObj1_L1,
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj2_L0);                     -- OK. {7:4;1}
   -- In the private part of Inst_L1_OK, after the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- ARen  : Acc_to_Tag_L1 := TObj1_L1'Access;
   -- AConv : Acc_to_Tag_L1 := B3A2011_0.Tag_Desig(TObj2_L0)'Access;

   package Inst_L1_Obj is
     new B3A2011_1 (B3A2011_0.Tag_Desig,
                    B3A2011_0.Acc_to_Tag_L0,
                    TObj1_L1,
                             -- Accessibility level of TObj1_L1 is deeper than
                             -- that of B3A2011_0.Acc_to_Tag_L0.
                    Acc_to_Tag_L1,
                    TObj2_L1,
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj2_L0);                     -- ERROR: {9:4;1}
   -- In the private part of Inst_L1_Obj, after the above instantiation:
   -- GAcc1 : Acc_to_Tag_L0 := TObj1_L1'Access;                      <= Illegal
   -- GAcc2 : Acc_to_Tag_L0 := TObj1_L1'Access;                      <= Illegal
   -- ARen  : Acc_to_Tag_L1 := TObj2_L1'Access;
   -- AConv : Acc_to_Tag_L1 := B3A2011_0.Tag_Desig(TObj2_L0)'Access;


   package Inst_L1_Ren is
     new B3A2011_1 (B3A2011_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj1_L0,
                    B3A2011_0.Acc_to_Tag_L0,
                    TObj1_L1,
                             -- Accessibility level of TObj1_L1 is deeper than
                             -- that of B3A2011_0.Acc_to_Tag_L0.
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj2_L0);                     -- ERROR: {9:4;1}
   -- In the private part of Inst_L1_Ren, after the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- ARen  : Acc_to_Tag_L0 := TObj1_L1'Access;                      <= Illegal
   -- AConv : Acc_to_Tag_L1 := B3A2011_0.Tag_Desig(TObj2_L0)'Access;

   package Inst_L1_Conv is
     new B3A2011_1 (B3A2011_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2011_0.TObj1_L0,
                    Acc_to_Tag_L1,
                    TObj1_L1,
                    B3A2011_0.Acc_to_Tag_L0,
                    TObj2_L1);                               -- ERROR: {7:4;1}
                             -- Accessibility level of TObj2_L1 is deeper than
                             -- that of B3A2011_0.Acc_to_Tag_L0.
   -- In the private part of Inst_L1_Conv, after the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj1_L0'Access;
   -- ARen  : Acc_to_Tag_L1 := TObj1_L1'Access;
   -- AConv : Acc_to_Tag_L0 := B3A2011_0.Tag_Desig(TObj2_L1)'Access; <= Illegal



begin -- B3A2011

   First_Nested_Block:
   declare

      type Acc_to_Tag_L2 is access constant B3A2011_0.Tag_Desig;  -- Level = 2.
      TObj1_L2 : aliased B3A2011_0.Tag_Desig;                     -- Level = 2.
      TObj2_L2 : aliased B3A2011_0.Tag_Desig;                     -- Level = 2.


      package Inst_L2_OK is
        new B3A2011_1 (B3A2011_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj1_L2,
                       Acc_to_Tag_L2,
                       B3A2011_0.TObj1_L0,
                       Acc_to_Tag_L2,
                       TObj1_L1);                            -- OK. {7:7;1}
      -- In the private part of Inst_L2_OK, after the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- ARen  : Acc_to_Tag_L2 := TObj1_L0'Access;
      -- AConv : Acc_to_Tag_L2 := B3A2011_0.Tag_Desig(TObj1_L1)'Access;

      package Inst_L2_Obj is
        new B3A2011_1 (B3A2011_0.Tag_Desig,
                       Acc_to_Tag_L1,
                       TObj1_L2,
                             -- Accessibility level of TObj1_L2 is deeper than
                             -- that of Acc_to_Tag_L1.
                       Acc_to_Tag_L2,
                       B3A2011_0.TObj1_L0,
                       Acc_to_Tag_L2,
                       TObj1_L1);                            -- ERROR: {9:7;1}
      -- In the private part of Inst_L2_Obj, after the above instantiation:
      -- GAcc1 : Acc_to_Tag_L1 := TObj1_L2'Access;                   <= Illegal
      -- GAcc2 : Acc_to_Tag_L1 := TObj1_L2'Access;                   <= Illegal
      -- ARen  : Acc_to_Tag_L2 := TObj1_L0'Access;
      -- AConv : Acc_to_Tag_L2 := B3A2011_0.Tag_Desig(TObj1_L1)'Access;

      package Inst_L2_Ren is
        new B3A2011_1 (B3A2011_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj1_L2,
                       B3A2011_0.Acc_to_Tag_L0,
                       TObj2_L2,
                             -- Accessibility level of TObj2_L2 is deeper than
                             -- that of B3A2011_0.Acc_to_Tag_L0.
                       Acc_to_Tag_L2,
                       TObj1_L1);                            -- ERROR: {9:7;1}
      -- In the private part of Inst_L2_Ren, after the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- ARen  : Acc_to_Tag_L0 := TObj2_L2'Access;                   <= Illegal
      -- AConv : Acc_to_Tag_L2 := B3A2011_0.Tag_Desig(TObj1_L1)'Access;

      package Inst_L2_Conv is
        new B3A2011_1 (B3A2011_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj1_L2,
                       Acc_to_Tag_L2,
                       B3A2011_0.TObj1_L0,
                       Acc_to_Tag_L1,
                       TObj2_L2);                            -- ERROR: {7:7;1}
                             -- Accessibility level of TObj2_L2 is deeper than
                             -- that of Acc_to_Tag_L1.
      -- In the private part of Inst_L2_Conv, after the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj1_L2'Access;
      -- ARen  : Acc_to_Tag_L2 := TObj1_L0'Access;
      -- AConv : Acc_to_Tag_L1 := B3A2011_0.Tag_Desig
      --                                      (TObj2_L2)'Access;     <= Illegal


   begin -- First_Nested.

      Doubly_Nested_Block:
      declare

         type Acc_to_Tag_L3 is access constant B3A2011_0.Tag_Desig;
                                                                -- Level = 3.
         TObj1_L3 : aliased B3A2011_0.Tag_Desig;                -- Level = 3.

         package Inst_L3_OK is
           new B3A2011_1 (B3A2011_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj1_L1,
                          Acc_to_Tag_L3,
                          TObj1_L2,
                          Acc_to_Tag_L3,
                          B3A2011_0.TObj1_L0);               -- OK. {7:10;1}
         -- In the private part of Inst_L3_OK, after the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- ARen  : Acc_to_Tag_L3 := TObj1_L2'Access;
         -- AConv : Acc_to_Tag_L3 := B3A2011_0.Tag_Desig(TObj1_L0)'Access;

         package Inst_L3_Obj is
           new B3A2011_1 (B3A2011_0.Tag_Desig,
                          B3A2011_0.Acc_to_Tag_L0,
                          TObj1_L3,
                             -- Accessibility level of TObj1_L3 is deeper than
                             -- that of B3A2011_0.Acc_to_Tag_L0.
                          Acc_to_Tag_L3,
                          TObj1_L2,
                          Acc_to_Tag_L3,
                          B3A2011_0.TObj1_L0);               -- ERROR: {9:10;1}
         -- In the private part of Inst_L3_Obj, after the above instantiation:
         -- GAcc1 : Acc_to_Tag_L0 := TObj1_L3'Access;                <= Illegal
         -- GAcc2 : Acc_to_Tag_L0 := TObj1_L3'Access;                <= Illegal
         -- ARen  : Acc_to_Tag_L3 := TObj1_L2'Access;
         -- AConv : Acc_to_Tag_L3 := B3A2011_0.Tag_Desig(TObj1_L0)'Access;

         package Inst_L3_Ren is
           new B3A2011_1 (B3A2011_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj1_L1,
                          Acc_to_Tag_L1,
                          TObj1_L3,
                             -- Accessibility level of TObj1_L3 is deeper than
                             -- that of Acc_to_Tag_L1.
                          Acc_to_Tag_L3,
                          B3A2011_0.TObj1_L0);               -- ERROR: {9:10;1}
         -- In the private part of Inst_L3_Ren, after the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- ARen  : Acc_to_Tag_L1 := TObj1_L3'Access;                <= Illegal
         -- AConv : Acc_to_Tag_L3 := B3A2011_0.Tag_Desig(TObj1_L0)'Access;

         package Inst_L3_Conv is
           new B3A2011_1 (B3A2011_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj1_L1,
                          Acc_to_Tag_L3,
                          TObj1_L2,
                          Acc_to_Tag_L2,
                          TObj1_L3);                         -- ERROR: {7:10;1}
                             -- Accessibility level of TObj1_L3 is deeper than
                             -- that of Acc_to_Tag_L2.
         -- In the private part of Inst_L3_Conv, after the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj1_L1'Access;
         -- ARen  : Acc_to_Tag_L3 := TObj1_L2'Access;
         -- AConv : Acc_to_Tag_L2 := B3A2011_0.Tag_Desig
         --                               (TObj1_L3)'Access;         <= Illegal


      begin -- Doubly_Nested_Block.
        null;
      end Doubly_Nested_Block;

   end First_Nested_Block;

end B3A2011;
