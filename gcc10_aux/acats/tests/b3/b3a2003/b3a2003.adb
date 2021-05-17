

     --==================================================================--


with B3A2003_0;
procedure B3A2003 is

   type AccObj_L1 is access all B3A2003_0.Obj_Type;               -- Level = 1.
   Obj_L1 : aliased B3A2003_0.Obj_Type;                           -- Level = 1.
   AOT1 : AccObj_L1;                                              -- Level = 1.

   type AccTag_L1 is access constant B3A2003_0.Tag_Type;          -- Level = 1.
   ATT1 : AccTag_L1;

   procedure NonTagCall_L1 (X: AccObj_L1) is     -- Subprogram with parameter
   begin                                         -- of a general access type:
      null;                                      -- non-tagged designated type.
   end NonTagCall_L1;


--
-- Nested subprogram:
--
                                                                          
   procedure Proc_L2 (FP_L2: in out B3A2003_0.Tag_Type) -- Parameter level = 2.
    is 
      type AccObj_L2 is access all B3A2003_0.Obj_Type;            -- Level = 2.

                                    -- Composite object with aliased component.
      Comp_L2 : B3A2003_0.Rec_With_Comp;                          -- Level = 2.

      type AccTag_L2 is access all B3A2003_0.Tag_Type;            -- Level = 2.

      procedure TagCall_L2 (X: AccTag_L2) is     -- Subprogram with parameter
      begin                                      -- of a general access type:
         null;                                   -- tagged designated type.
      end TagCall_L2;


   --
   -- Doubly-nested subprogram:
   --

      procedure Proc_L3 
        (FP_L3: in out B3A2003_0.Tag_Type) is    -- Parameter level = 3.

         AOT2 : AccObj_L2;    -- Level 3 variable, type is level 2.
                              -- Accessibility level determined by declaration
                              -- of object, not of type.

         type AccObj_L3 is access all B3A2003_0.Obj_Type;         -- Level = 3.
         AOT3   : AccObj_L3;
         Obj_L3 : aliased B3A2003_0.Obj_Type;                     -- Level = 3.

         type AccTag_L3 is access constant B3A2003_0.Tag_Type;    -- Level = 3.
         ATT3 : AccTag_L3;

      begin -- Proc_L3.

         -- 'Access applied to an object:

         B3A2003_0.AOT0 := Obj_L3'Access;                             -- ERROR:
                        -- Accessibility level of Obj_L3 is deeper than that of
                        -- B3A2003_0.AccObj_L0.

         NonTagCall_L1 (Obj_L3'Access);                               -- ERROR:
             -- Accessibility level of Obj_L3 is deeper than that of AccObj_L1.

         AOT2 := Obj_L1'Access;                                       -- OK.
         AOT2 := Obj_L3'Access;                                       -- ERROR:
             -- Accessibility level of Obj_L3 is deeper than that of AccObj_L2.

         AOT3 := Obj_L1'Access;                                       -- OK.
         AOT3 := Obj_L3'Access;                                       -- OK.


         -- 'Access applied to a component:

         AOT1 := Comp_L2.C'Access;                                    -- ERROR:
                     -- Accessibility level of Comp_L2.C is deeper than that of
                     -- AccObj_L1.
         AOT2 := Comp_L2.C'Access;                                    -- OK.
         AOT3 := Comp_L2.C'Access;                                    -- OK.


         -- 'Access applied to a tagged formal parameter:

         B3A2003_0.ATT0 := FP_L3'Access;                              -- ERROR:
                         -- Accessibility level of FP_L3 is deeper than that of
                         -- B3A2003_0.AccTag_L0.

         TagCall_L2 (FP_L3'Access);                                   -- ERROR:
              -- Accessibility level of FP_L3 is deeper than that of AccTag_L2.

         ATT3 := FP_L2'Access;                                        -- OK.
         ATT3 := FP_L3'Access;                                        -- OK.

      end Proc_L3;


   begin -- Proc_L2.

      -- 'Access applied to a component:

      B3A2003_0.AOT0 := Comp_L2.C'Access;                             -- ERROR:
                     -- Accessibility level of Comp_L2.C is deeper than that of
                     -- B3A2003_0.AccObj_L0.

      NonTagCall_L1 (Comp_L2.C'Access);                               -- ERROR:
             -- Accessibility level of Obj_L2 is deeper than that of AccObj_L1.



      -- 'Access applied to a tagged formal parameter:

      ATT1 := FP_L2'Access;                                           -- ERROR:
              -- Accessibility level of FP_L2 is deeper than that of AccTag_L1.

      TagCall_L2 (FP_L2'Access);                                      -- OK.

   end Proc_L2;



begin -- B3A2003

   -- 'Access applied to an object:

   B3A2003_0.AOT0 := Obj_L1'Access;                                   -- ERROR:
                        -- Accessibility level of Obj_L1 is deeper than that of
                        -- B3A2003_0.AccObj_L0.

   NonTagCall_L1 (Obj_L1'Access);                                     -- OK.


end B3A2003;
