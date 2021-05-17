
-- No body for B3A2005_0.

     --==================================================================--

with B3A2005_0;
procedure B3A2005 is

   X_L1 : aliased B3A2005_0.Tag_Desig;                                

   type AccDef_L1 is access B3A2005_0.Default_Lim_Disc;           -- Level = 1.

   type Lim_Disc_L1 (D: access B3A2005_0.Tag_Desig:= B3A2005_0.X_L0'Access) 
     is limited record
        I : Integer;
   end record;

   type AccLim_L1 is access Lim_Disc_L1;                          -- Level = 1.

   Default_Allocator_Obj_L1 : AccDef_L1 
     := new B3A2005_0.Default_Lim_Disc;                               -- OK.

   -- No allocator involved:
   NoAllocator_Obj_L1 : B3A2005_0.Default_Lim_Disc (X_L1'Access);     -- OK.

   Default_Allocator_Obj_L0 : B3A2005_0.AccDef_L0 
     := new B3A2005_0.Default_Lim_Disc;                               -- OK.

   Allocator_DefObj_L0  :  B3A2005_0.AccDef_L0
     := new B3A2005_0.Default_Lim_Disc (X_L1'Access);                 -- ERROR:
                        -- Accessibility level of X_L1 is deeper than the level
                        -- of the type of the allocator, AccDef_L0.

   Allocator_DefObj_L1  :  AccDef_L1
     := new B3A2005_0.Default_Lim_Disc (X_L1'Access);                 -- OK.

   Allocator_LimObj_L1 :  AccLim_L1
     := new Lim_Disc_L1 (X_L1'Access);                                -- OK.


--
-- Nested subprogram:
--

   procedure Proc1 (FP_L2 : in out B3A2005_0.Tag_Desig) is        -- Level = 2.

      X_L2 : aliased B3A2005_0.Tag_Desig;                         -- Level = 2.
      type AccDef_L2 is access B3A2005_0.Default_Lim_Disc;        -- Level = 2.

      type Lim_Disc_L2 (D: access B3A2005_0.Tag_Desig:= B3A2005_0.X_L0'Access) 
        is limited record
           I : Integer;
      end record;

      type AccLim_L2 is access Lim_Disc_L2;                       -- Level = 2.

      -- Formal parameters of tagged type are aliased by definition.
      Allocator_DefObj2_L0 :  B3A2005_0.AccDef_L0
        := new B3A2005_0.Default_Lim_Disc (FP_L2'Access);             -- ERROR:
                       -- Accessibility level of FP_L2 is deeper than the level
                       -- of the type of the allocator, AccDef_L0.

      Allocator_DefObj2_L1 :  AccDef_L1
        := new B3A2005_0.Default_Lim_Disc (FP_L2'Access);             -- ERROR:
                       -- Accessibility level of FP_L2 is deeper than the level
                       -- of the type of the allocator, AccDef_L1.

      Allocator_DefObj2_L2 :  AccDef_L2
        := new B3A2005_0.Default_Lim_Disc (X_L1'Access);              -- OK.

      Allocator_DefObj3_L1 :  AccDef_L1
        := new B3A2005_0.Default_Lim_Disc (X_L2'Access);              -- ERROR:
                        -- Accessibility level of X_L2 is deeper than the level
                        -- of the type of the allocator, AccDef_L1.

      Allocator_LimObj2_L2 :  AccLim_L2
        := new Lim_Disc_L2 (X_L1'Access);                             -- OK.

      procedure SubprogCall_L1 (FP : AccDef_L1) is
      begin
         null;
      end SubprogCall_L1;

      procedure SubprogCall_L2 (FP : AccDef_L2) is
      begin
         null;
      end SubprogCall_L2;

   begin -- Proc1.
      SubprogCall_L1 (new B3A2005_0.Default_Lim_Disc (X_L2'Access));  -- ERROR:
                        -- Accessibility level of X_L2 is deeper than the level
                        -- of the type of the allocator, AccDef_L1.

      SubprogCall_L2 (new B3A2005_0.Default_Lim_Disc (X_L2'Access));  -- OK.

   end Proc1;

begin -- B3A2005
   null;
end B3A2005;
