
     --==================================================================--


with B3A2012_0;
with B3A2012_1;
procedure B3A2012 is

   type Acc_to_Tag_L1 is access constant B3A2012_0.Tag_Desig; -- Level = 1.
   TObj_L1 : aliased B3A2012_0.Tag_Desig;                     -- Level = 1.
   Comp_L1 : B3A2012_0.Rec_With_Comp;                         -- Level = 1.
   Derf_L1 : B3A2012_0.Acc_To_Tag_L0;                         -- Level = 1.

   package Inst_L1_OK is
     new B3A2012_1 (B3A2012_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2012_0.TObj_L0,
                    Acc_to_Tag_L1,
                    Comp_L1.C,
                    Acc_to_Tag_L1,
                    B3A2012_0.Derf_L0.all);                  -- OK. {7:4;1}
   -- After the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- AComp : Acc_to_Tag_L1 := Comp_L1.C'Access;
   -- ADerf : Acc_to_Tag_L1 := Derf_L0'Access;

   package Inst_L1_Obj is
     new B3A2012_1 (B3A2012_0.Tag_Desig,
                    B3A2012_0.Acc_to_Tag_L0,
                    TObj_L1,
                               -- Accessibility level of TObj_L1 is deeper than
                               -- that of B3A2012_0.Acc_to_Tag_L0.
                    Acc_to_Tag_L1,
                    Comp_L1.C,
                    Acc_to_Tag_L1,
                    B3A2012_0.Derf_L0.all);                  -- ERROR: {9:4;1}
   -- After the above instantiation:
   -- GAcc1 : Acc_to_Tag_L0 := TObj_L1'Access;                      <= Illegal
   -- GAcc2 : Acc_to_Tag_L0 := TObj_L1'Access;                      <= Illegal
   -- AComp : Acc_to_Tag_L1 := Comp_L1.C'Access;
   -- ADerf : Acc_to_Tag_L1 := Derf_L0'Access;

   package Inst_L1_Comp is
     new B3A2012_1 (B3A2012_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2012_0.TObj_L0,
                    B3A2012_0.Acc_to_Tag_L0,
                    Comp_L1.C,
                             -- Accessibility level of Comp_L1.C is deeper than
                             -- that of B3A2012_0.Acc_to_Tag_L0.
                    Acc_to_Tag_L1,
                    B3A2012_0.Derf_L0.all);                  -- ERROR: {9:4;1}
   -- After the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- AComp : Acc_to_Tag_L0 := Comp_L1.C'Access;                    <= Illegal
   -- ADerf : Acc_to_Tag_L1 := Derf_L0'Access;

   package Inst_L1_Derf is
     new B3A2012_1 (B3A2012_0.Tag_Desig,
                    Acc_to_Tag_L1,
                    B3A2012_0.TObj_L0,
                    Acc_to_Tag_L1,
                    Comp_L1.C,
                    B3A2012_0.Acc_to_Tag_L0,
                    Derf_L1.all);                            -- ERROR: {7:4;1}
                               -- Accessibility level of Derf_L1 is deeper than
                               -- that of B3A2012_0.Acc_to_Tag_L0.
   -- After the above instantiation:
   -- GAcc1 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- GAcc2 : Acc_to_Tag_L1 := TObj_L0'Access;
   -- AComp : Acc_to_Tag_L1 := Comp_L1.C'Access;
   -- ADerf : Acc_to_Tag_L0 := Derf_L1'Access;                      <= Illegal


begin -- B3A2012

   First_Nested_Block:
   declare

      type Acc_to_Tag_L2 is access constant B3A2012_0.Tag_Desig;
                                                              -- Level = 2.
      TObj_L2 : aliased B3A2012_0.Tag_Desig;                  -- Level = 2.
      Comp_L2 : B3A2012_0.Rec_With_Comp;                      -- Level = 2.
      Derf_L2 : B3A2012_0.Acc_To_Tag_L0;                      -- Level = 2.

      package Inst_L2_OK is
        new B3A2012_1 (B3A2012_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj_L2,
                       Acc_to_Tag_L2,
                       B3A2012_0.Comp_L0.C,
                       Acc_to_Tag_L2,
                       Derf_L1.all);                         -- OK. {7:7;1}
      -- After the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- AComp : Acc_to_Tag_L2 := Comp_L0.C'Access;
      -- ADerf : Acc_to_Tag_L2 := Derf_L1'Access;

      package Inst_L2_Obj is
        new B3A2012_1 (B3A2012_0.Tag_Desig,
                       Acc_to_Tag_L1,
                       TObj_L2,
                              -- Accessibility level of TObj_L2 is deeper than
                              -- that of Acc_to_Tag_L1.
                       Acc_to_Tag_L2,
                       B3A2012_0.Comp_L0.C,
                       Acc_to_Tag_L2,
                       Derf_L1.all);                         -- ERROR: {9:7;1}
      -- After the above instantiation:
      -- GAcc1 : Acc_to_Tag_L1 := TObj_L2'Access;                   <= Illegal
      -- GAcc2 : Acc_to_Tag_L1 := TObj_L2'Access;                   <= Illegal
      -- AComp : Acc_to_Tag_L2 := Comp_L0.C'Access;
      -- ADerf : Acc_to_Tag_L2 := Derf_L1'Access;

      package Inst_L2_Comp is
        new B3A2012_1 (B3A2012_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj_L2,
                       B3A2012_0.Acc_to_Tag_L0,
                       Comp_L2.C,
                             -- Accessibility level of Comp_L2.C is deeper than
                             -- that of B3A2012_0.Acc_to_Tag_L0.
                       Acc_to_Tag_L2,
                       Derf_L1.all);                         -- ERROR: {9:7;1}
      -- After the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- AComp : Acc_to_Tag_L0 := Comp_L2.C'Access;                 <= Illegal
      -- ADerf : Acc_to_Tag_L2 := Derf_L1'Access;

      package Inst_L2_Derf is
        new B3A2012_1 (B3A2012_0.Tag_Desig,
                       Acc_to_Tag_L2,
                       TObj_L2,
                       Acc_to_Tag_L2,
                       B3A2012_0.Comp_L0.C,
                       Acc_to_Tag_L1,
                       Derf_L2.all);                         -- ERROR: {7:7;1}
                               -- Accessibility level of Derf_L2 is deeper than
                               -- that of Acc_to_Tag_L1.
      -- After the above instantiation:
      -- GAcc1 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- GAcc2 : Acc_to_Tag_L2 := TObj_L2'Access;
      -- AComp : Acc_to_Tag_L2 := Comp_L0.C'Access;
      -- ADerf : Acc_to_Tag_L1 := Derf_L2'Access;                   <= Illegal

   begin -- First_Nested.

      Doubly_Nested_Block:
      declare

         type Acc_to_Tag_L3 is access constant B3A2012_0.Tag_Desig;
                                                              -- Level = 3.
         TObj_L3 : aliased B3A2012_0.Tag_Desig;               -- Level = 3.
         Comp_L3 : B3A2012_0.Rec_With_Comp;                   -- Level = 3.
         Derf_L3 : B3A2012_0.Acc_To_Tag_L0;                   -- Level = 3.

         package Inst_L3_OK is
           new B3A2012_1 (B3A2012_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj_L1,
                          Acc_to_Tag_L3,
                          Comp_L2.C,
                          Acc_to_Tag_L3,
                          B3A2012_0.Derf_L0.all);            -- OK. {7:10;1}
         -- After the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- AComp : Acc_to_Tag_L3 := Comp_L2.C'Access;
         -- ADerf : Acc_to_Tag_L3 := Derf_L0'Access;

         package Inst_L3_Obj is
           new B3A2012_1 (B3A2012_0.Tag_Desig,
                          B3A2012_0.Acc_to_Tag_L0,
                          TObj_L3,
                              -- Accessibility level of TObj_L3 is deeper than
                              -- that of B3A2012_0.Acc_to_Tag_L0.
                          Acc_to_Tag_L3,
                          Comp_L2.C,
                          Acc_to_Tag_L3,
                          B3A2012_0.Derf_L0.all);            -- ERROR: {9:10;1}
         -- After the above instantiation:
         -- GAcc1 : Acc_to_Tag_L0 := TObj_L3'Access;                <= Illegal
         -- GAcc2 : Acc_to_Tag_L0 := TObj_L3'Access;                <= Illegal
         -- AComp : Acc_to_Tag_L3 := Comp_L2.C'Access;
         -- ADerf : Acc_to_Tag_L3 := Derf_L0'Access;

         package Inst_L3_Comp is
           new B3A2012_1 (B3A2012_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj_L1,
                          Acc_to_Tag_L1,
                          Comp_L3.C,
                            -- Accessibility level of Comp_L3.C is deeper than
                            -- that of Acc_to_Tag_L1.
                          Acc_to_Tag_L3,
                          B3A2012_0.Derf_L0.all);            -- ERROR: {9:10;1}
         -- After the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- AComp : Acc_to_Tag_L1 := Comp_L3.C'Access;              <= Illegal
         -- ADerf : Acc_to_Tag_L3 := Derf_L0'Access;

         package Inst_L3_Derf is
           new B3A2012_1 (B3A2012_0.Tag_Desig,
                          Acc_to_Tag_L3,
                          TObj_L1,
                          Acc_to_Tag_L3,
                          Comp_L2.C,
                          Acc_to_Tag_L2,
                          Derf_L3.all);                      -- ERROR: {7:10;1}
                               -- Accessibility level of Derf_L3 is deeper than
                               -- that of Acc_to_Tag_L2.
         -- After the above instantiation:
         -- GAcc1 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- GAcc2 : Acc_to_Tag_L3 := TObj_L1'Access;
         -- AComp : Acc_to_Tag_L3 := Comp_L2.C'Access;
         -- ADerf : Acc_to_Tag_L2 := Derf_L3'Access;                <= Illegal


      begin -- Doubly_Nested_Block.
        null;
      end Doubly_Nested_Block;

   end First_Nested_Block;

end B3A2012;
