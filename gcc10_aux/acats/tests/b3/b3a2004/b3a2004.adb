

     --==================================================================--


with B3A2004_0;
procedure B3A2004 is

   type AccObj_L1 is access all B3A2004_0.Obj_Type;               -- Level = 1.
   Obj_L1 : aliased B3A2004_0.Obj_Type;                           -- Level = 1.
   GAT1   : AccObj_L1;                                            -- Level = 1.

   -- The accessibility of a renaming declaration is that of the object
   -- being renamed. 
   Ren_L0 : B3A2004_0.Obj_Type renames B3A2004_0.Obj_L0;          -- Level = 0.

   type AccTag_L1 is access all B3A2004_0.Tag_Type;               -- Level = 1.
   Der_L1 : aliased B3A2004_0.Der_Type;                           -- Level = 1.

   procedure NonTagCall_L1 (X: AccObj_L1) is     -- Subprogram with parameter
   begin                                         -- of a general access type:
      null;                                      -- non-tagged designated type.
   end NonTagCall_L1;


begin -- B3A2004_0


--
-- Block statement: an inner master, creating a new accessibility level.
--

   declare
                                                                          
      type AccObj_L2 is access all B3A2004_0.Obj_Type;            -- Level = 2.
      Obj_L2 : aliased B3A2004_0.Obj_Type;                        -- Level = 2.
      GAT2 : AccObj_L2;
      AAT2 : array (1 .. 4) of aliased B3A2004_0.Obj_Type;        -- Level = 2.

      -- Pool-specific access type:
      type PoolObj_L2 is access    B3A2004_0.Obj_Type;            -- Level = 2.


      -- Composite object with aliased component:
      Comp_L2 : B3A2004_0.Rec_With_Comp;                          -- Level = 2.

      -- The accessibility of a renaming declaration is that of the object
      -- being renamed. 
      Ren_L1 : B3A2004_0.Obj_Type renames Obj_L1;                 -- Level = 1.

      Ren_GAT1_L1 : AccObj_L1 renames GAT1;                       -- Level = 1.


      ATT1 : AccTag_L1;       -- Declared at deeper level than type.
                              -- (Have no effect on accessibility level).

      type AccTag_L2 is access all B3A2004_0.Tag_Type;            -- Level = 2.
      Der_L2 : aliased B3A2004_0.Der_Type;                        -- Level = 2.

      procedure TagCall_L2 (X: AccTag_L2) is     -- Subprogram with parameter
      begin                                      -- of a general access type:
         null;                                   -- tagged designated type.
      end TagCall_L2;


   --
   -- Nested task:  an inner master, creating a new accessibility level.
   --

      task Tsk is
         entry Class_Entry (FP_L4: B3A2004_0.Tag_Type'Class);
      end Tsk;

      task body Tsk is

         PAT2 : PoolObj_L2;   -- Level 3 variable, type is level 2.
                              -- (Have no effect on accessibility level).

         type AccObj_L3 is access all B3A2004_0.Obj_Type;         -- Level = 3.
         GAT3   : AccObj_L3;
         Obj_L3 : aliased B3A2004_0.Obj_Type;                     -- Level = 3.
         AAT3   : array (1 .. 4) of aliased B3A2004_0.Obj_Type;   -- Level = 3.

         -- Renaming of an aliased component:
         Ren_L2 : B3A2004_0.Obj_Type renames Comp_L2.C;           -- Level = 2.

         type AccTag_L3 is access constant B3A2004_0.Tag_Type;    -- Level = 3.
         ATT3   : AccTag_L3;
         Der_L3 : aliased B3A2004_0.Der_Type;                     -- Level = 3.

      begin -- Tsk.

         -- 'Access applied to a view denoted by a renaming:

         B3A2004_0.GAT0 := Ren_L2'Access;                             -- ERROR:
                        -- Accessibility level of Ren_L2 is deeper than that of
                        -- B3A2004_0.AccObj_L0.

         NonTagCall_L1 (Ren_L2'Access);                               -- ERROR:
             -- Accessibility level of Ren_L2 is deeper than that of AccObj_L1.

         GAT1 := Ren_L2'Access;                                       -- ERROR:
             -- Accessibility level of Ren_L2 is deeper than that of AccObj_L1.

         GAT2 := Ren_L2'Access;                                       -- OK.

         GAT3 := Ren_L0'Access;                                       -- OK.
         GAT3 := Ren_L2'Access;                                       -- OK.

         Ren_GAT1_L1 := Obj_L2'Access;                                -- ERROR:
             -- Accessibility level of Obj_L2 is deeper than that of AccObj_L1.

         Ren_GAT1_L1 := Obj_L1'Access;                                -- OK.


         -- 'Access applied to a dereference:

         GAT3 := B3A2004_0.GAT0.all'Access;                           -- OK.

         GAT3 := B3A2004_0.AAT0(1)'Access;                            -- OK.

         NonTagCall_L1 (GAT3.all'Access);                             -- ERROR:
          -- Accessibility level of AccObj_L3 is deeper than that of AccObj_L1.

         NonTagCall_L1 (AAT3(2)'Access);                             -- ERROR:
           -- Accessibility level of AAT3(2) is deeper than that of AccObj_L1.
    
         NonTagCall_L1 (PAT2.all'Access);                            -- ERROR:
                   -- Accessibility level of PoolObj_L2 is deeper than that of 
                   -- AccObj_L1.

         NonTagCall_L1 (AAT2(3)'Access);                             -- ERROR:
            -- Accessibility level of ATT2(3) is deeper than that of AccObj_L1.

         GAT1 := PAT2.all'Access;                                     -- ERROR:
         -- Accessibility level of PoolObj_L2 is deeper than that of AccObj_L1.

         GAT1 := AAT2(4)'Access;                                      -- ERROR:
            -- Accessibility level of ATT2(4) is deeper than that of AccObj_L1.

         GAT2 := PAT2.all'Access;                                     -- OK.

         GAT2 := AAT2(1)'Access;                                      -- OK.
 

        -- 'Access applied to a view conversion:

         ATT1 := B3A2004_0.Tag_Type(Der_L3)'Access;                   -- ERROR:
             -- Accessibility level of Der_L3 is deeper than that of AccTag_L1.

         TagCall_L2 (B3A2004_0.Tag_Type(Der_L3)'Access);              -- ERROR:
             -- Accessibility level of Der_L3 is deeper than that of AccTag_L2.


         accept Class_Entry (FP_L4: B3A2004_0.Tag_Type'Class) do  
                                                    -- Inner master, level = 4.

            -- 'Access applied to a view conversion:

            ATT3 := B3A2004_0.Tag_Type(FP_L4)'Access;                 -- ERROR:
              -- Accessibility level of FP_L4 is deeper than that of AccTag_L3.

         end Class_Entry;

      end Tsk;



   begin -- Block statement.

      -- 'Access applied to a view denoted by a renaming:

      NonTagCall_L1 (Ren_L1'Access);                                  -- OK.

      -- 'Access applied to a dereference:

      B3A2004_0.GAT0 := GAT2.all'Access;                              -- ERROR:
                     -- Accessibility level of AccObj_L2 is deeper than that of
                     -- B3A2004_0.AccObj_L0.

      B3A2004_0.GAT0 := AAT2(2)'Access;                               -- ERROR:
                     -- Accessibility level of ATT2(2) is deeper than that of
                     -- B3A2004_0.AccObj_L0.

      NonTagCall_L1 (B3A2004_0.GAT0.all'Access);                      -- OK.

      NonTagCall_L1 (B3A2004_0.AAT0(4)'Access);                       -- OK.


      -- 'Access applied to a view conversion:

      ATT1 := B3A2004_0.Tag_Type(Der_L1)'Access;                      -- OK.

      TagCall_L2 (B3A2004_0.Tag_Type(Der_L1)'Access);                 -- OK.

      ATT1 := B3A2004_0.Tag_Type(Der_L2)'Access;                      -- ERROR:
             -- Accessibility level of Der_L2 is deeper than that of AccTag_L1.

      TagCall_L2 (B3A2004_0.Tag_Type(Der_L2)'Access);                 -- OK.


   end; -- Block statement.



   -- 'Access applied to a view denoted by a renaming:

   B3A2004_0.GAT0 := Ren_L0'Access;                                   -- OK.


   -- 'Access applied to a view conversion:

   B3A2004_0.ATT0 := B3A2004_0.Tag_Type(B3A2004_0.Der_L0)'Access;     -- OK.

   B3A2004_0.ATT0 := B3A2004_0.Tag_Type(Der_L1)'Access;               -- ERROR:
                        -- Accessibility level of Der_L1 is deeper than that of
                        -- B3A2004_0.AccTag_L0.

end B3A2004;
