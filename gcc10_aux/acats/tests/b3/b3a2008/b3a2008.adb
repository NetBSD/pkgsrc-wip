


     --==================================================================--


with B3A2008_0;
with B3A2008_1;
procedure B3A2008 is

   type Acc_NTag_L1  is access all B3A2008_0.New_Tagged_Rec;      -- Level = 1.
   type Acc1_Rec_L1  is access all B3A2008_0.Rec;                 -- Level = 1.
   type Acc2_Rec_L1  is access all B3A2008_0.Rec;                 -- Level = 1.

   package Inst_L1_OK is
     new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                    Acc_NTag_L1,
                    B3A2008_0.Rec,
                    Acc1_Rec_L1,
                    Acc2_Rec_L1);                            -- OK. {5:4;1}
   -- In the private part of Inst_L1_OK, after the above instantiation:
   -- AObj  : Acc_NTag_L1 := Gen_Obj'Access   (Gen_Obj level = 1)
   -- AComp : Acc1_Rec_L1 := Gen_Rec.C'Access (Gen_Rec.C level = 1)
   -- ADeref: Acc2_Rec_L1 := Gen_Deref.all'Access (Gen_Deref.all level = 1)


   package Inst_L1_Obj is
     new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                    B3A2008_0.Acc_NTag_L0,
                               -- Accessibility level of Gen_Obj is deeper than
                               -- that of B3A2008_0.Acc_NTag_L0.
                    B3A2008_0.Rec,
                    Acc1_Rec_L1,
                    Acc2_Rec_L1);                            -- ERROR: {7:4;1}
   -- In the private part of Inst_L1_Obj, after the above instantiation:
   -- AObj  : Acc_NTag_L0 := Gen_Obj'Access   (Gen_Obj level = 1)   <= Illegal
   -- AComp : Acc1_Rec_L1 := Gen_Rec.C'Access (Gen_Rec.C level = 1)
   -- ADeref: Acc2_Rec_L1 := Gen_Deref.all'Access (Gen_Deref.all level = 1)


   package Inst_L1_Comp is
     new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                    Acc_NTag_L1,
                    B3A2008_0.Rec,
                    B3A2008_0.Acc1_Rec_L0,
                             -- Accessibility level of Gen_Rec.C is deeper than
                             -- that of B3A2008_0.Acc1_Rec_L0.
                    Acc2_Rec_L1);                            -- ERROR: {7:4;1}
   -- In the private part of Inst_L1_Comp, after the above instantiation:
   -- AObj  : Acc_NTag_L1 := Gen_Obj'Access   (Gen_Obj level = 1)
   -- AComp : Acc1_Rec_L0 := Gen_Rec.C'Access (Gen_Rec.C level = 1) <= Illegal
   -- ADeref: Acc2_Rec_L1 := Gen_Deref.all'Access (Gen_Deref.all level = 1)


   package Inst_L1_Deref is
     new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                    Acc_NTag_L1,
                    B3A2008_0.Rec,
                    Acc1_Rec_L1,
                    B3A2008_0.Acc2_Rec_L0);                  -- ERROR: {5:4;1}
                              -- Accessibility level of Gen_Deref.all is deeper
                              -- than that of B3A2008_0.Acc2_Rec_L0.
   -- In the private part of Inst_L1_Deref, after the above instantiation:
   -- AObj  : Acc_NTag_L1 := Gen_Obj'Access   (Gen_Obj level = 1)
   -- AComp : Acc1_Rec_L1 := Gen_Rec.C'Access (Gen_Rec.C level = 1)
   -- ADeref: Acc2_Rec_L0 := Gen_Deref.all'Access
   --                                   (Gen_Deref.all level = 1)   <= Illegal

   --
   -- Nested task:
   --

   task Tsk;

   task body Tsk is

      type Acc_NTag_L2  is access all B3A2008_0.New_Tagged_Rec;   -- Level = 2.
      type Acc1_Rec_L2  is access all B3A2008_0.Rec;              -- Level = 2.
      type Acc2_Rec_L2  is access all B3A2008_0.Rec;              -- Level = 2.

      package Inst_L2_OK is
        new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                       Acc_NTag_L2,
                       B3A2008_0.Rec,
                       Acc1_Rec_L2,
                       Acc2_Rec_L2);                         -- OK. {5:7;1}
      -- In the private part of Inst_L2_OK, after the above instantiation:
      -- AObj  : Acc_NTag_L2 := Gen_Obj'Access   (Gen_Obj level = 2)
      -- AComp : Acc1_Rec_L2 := Gen_Rec.C'Access (Gen_Rec.C level = 2)
      -- ADeref: Acc2_Rec_L2 := Gen_Deref.all'Access (Gen_Deref.all level = 2)


      package Inst_L2_Obj is
        new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                       Acc_NTag_L1,
                               -- Accessibility level of Gen_Obj is deeper than
                               -- that of Acc_NTag_L1.
                       B3A2008_0.Rec,
                       Acc1_Rec_L2,
                       Acc2_Rec_L2);                         -- ERROR: {7:7;1}
      -- In the private part of Inst_L2_Obj, after the above instantiation:
      -- AObj  : Acc_NTag_L1 := Gen_Obj'Access   (Gen_Obj level = 2) <= Illegal
      -- AComp : Acc1_Rec_L2 := Gen_Rec.C'Access (Gen_Rec.C level = 2)
      -- ADeref: Acc2_Rec_L2 := Gen_Deref.all'Access (Gen_Deref.all level = 2)


      package Inst_L2_Comp is
        new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                       Acc_NTag_L2,
                       B3A2008_0.Rec,
                       B3A2008_0.Acc1_Rec_L0,
                             -- Accessibility level of Gen_Rec.C is deeper than
                             -- that of B3A2008_0.Acc1_Rec_L0.
                       Acc2_Rec_L2);                         -- ERROR: {7:7;1}
      -- In the private part of Inst_L2_Comp, after the above instantiation:
      -- AObj  : Acc_NTag_L2 := Gen_Obj'Access (Gen_Obj level = 2)
      -- AComp : Acc1_Rec_L0 := Gen_Rec.C'Access
      --                                   (Gen_Rec.C level = 2)     <= Illegal
      -- ADeref: Acc2_Rec_L2 := Gen_Deref.all'Access (Gen_Deref.all level = 2)


      package Inst_L2_Deref is
        new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                       Acc_NTag_L2,
                       B3A2008_0.Rec,
                       Acc1_Rec_L2,
                       Acc1_Rec_L1);                         -- ERROR: {5:7;1}
                              -- Accessibility level of Gen_Deref.all is deeper
                              -- than that of B3A2008_0.Acc1_Rec_L1.
      -- In the private part of Inst_L2_Deref, after the above instantiation:
      -- AObj  : Acc_NTag_L2:= Gen_Obj'Access   (Gen_Obj level = 2)
      -- AComp : Acc1_Rec_L2:= Gen_Rec.C'Access (Gen_Rec.C level = 2)
      -- ADeref: Acc1_Rec_L1:= Gen_Deref.all'Access
      --                                 (Gen_Deref.all level = 2)   <= Illegal

    begin -- Tsk.
      null;
    end Tsk;


begin -- B3A2008
   null;
end B3A2008;
