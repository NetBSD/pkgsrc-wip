

     --==================================================================--


package body B3A2015 is

--
-- Tagged type subtests:
--

   RNew_Tag_Type : String renames XNew_Tag_Type.C;                    -- OK.
                 -- Nominal subtype of variable XNew_Tag_Type is indefinite.


   procedure Op (P : in out Tag_Type) is  -- Formal parameter of a tagged type
      Ptr : AccStr;                       -- is aliased.  -- LM 3.10(9);6.0

      Ren : Tag_Type renames P;                                       -- OK.
                         -- Variable view P is indefinite.
   begin

      Ptr := P.Not_Aliased'Access;                                    -- ERROR:
                                 -- Component of aliased object is not aliased.
   end Op;


--
-- Record type subtests:
--

   PR_Indef    : AccTag_Type := XR_Indef.C'Access;                    -- OK.
                      -- Nominal subtype of variable XR_Indef is indefinite.

   ----------------------------------------------------------------------
   -- XNDef_RIndef.C depends on discriminants of XNDef_RIndef (old discriminant
   -- defined in terms of new discriminant), whose subtype is unconstrained but
   -- definite; XNDef_RIndef is not aliased.

   PNDef_RIndef : AccTag_Type := XNDef_RIndef.C'Access;               -- ERROR:
            -- Subtype of XNDef_RIndef is unconstrained, definite.

   ----------------------------------------------------------------------
   -- XR_Def.C1 and XR_Def.C2 depend on discriminants of XR_Def, whose
   -- subtype is unconstrained but definite; XR_Def is not aliased.

   PR_Def1     : AccStr      := XR_Def.C1'Access;                     -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   PR_Def2     : AccR_Indef  := XR_Def.C2'Access;                     -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   ----------------------------------------------------------------------
   -- XR_Def.C3.C depends on discriminants of XR_Def.C3, whose subtype is
   -- indefinite. But XR_Def.C3 depends on discriminants of XR_Def, whose
   -- subtype is unconstrained but definite; XR_Def is not aliased.

   PR_Def3     : AccTag_Type := XR_Def.C3.C'Access;                   -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   ----------------------------------------------------------------------
   -- ANewR_Def.C1 and AnewR_Def.C2 depend on discriminants of AnewR_Def,
   -- whose subtype is unconstrained but definite; ANewR_Def is aliased.

   PNewR_Def2  : AccR_Indef  := ANewR_Def.C2'Access;                  -- ERROR:
       -- Subtype of ANewR_Def is unconstrained, definite. Change from Ada 95.

   ----------------------------------------------------------------------
   -- XVar_Rec.CT depends on discriminants of XVar_Rec, whose subtype is
   -- unconstrained but definite; XVar_Rec is not aliased.

   PVar_Rec    : AccStr      := XVar_Rec.CT'Access;                   -- ERROR:
                -- Subtype of XVar_Rec is unconstrained, definite.

   ----------------------------------------------------------------------
   -- Implicit dereference:

   PR_Def4    : AccR_Indef  := XAccRP_Def.C2'Access;                  -- OK.
          -- Nominal subtype of XAccRP_Def.all is unconstrained and definite,
          -- but XAccRP_Def.all is a dereference of a pool-specific access type.

   PR_Def5    : AccR_Indef  := XAccRG_Def.C2'Access;                  -- ERROR:
          -- Nominal subtype of XAccRG_Def.all is unconstrained and definite,
          -- and XAccRG_Def.all is not a dereference of a pool-specific
          -- access type. Change from Ada 95.

   RPoolR_Def : String renames XAccRP_Def.C1;                         -- OK.
          -- Nominal subtype of XAccRP_Def.all is unconstrained and definite,
          -- but XAccRP_Def.all is a dereference of a pool-specific access type.

   RGenR_Def : String renames XAccRG_Def.C1;                          -- ERROR:
          -- Nominal subtype of XAccRG_Def.all is unconstrained and definite,
          -- and XAccRG_Def.all is not a dereference of a pool-specific
          -- access type. Change from Ada 95.

   ----------------------------------------------------------------------

   RR_Indef    : Tag_Type renames XR_Indef.C;                         -- OK.
                      -- Nominal subtype of variable XR_Indef is indefinite.

   ----------------------------------------------------------------------
   -- XNDef_RIndef.C depends on discriminants of XNDef_RIndef (old discriminant
   -- defined in terms of new discriminant), whose subtype is unconstrained
   -- but definite; XNewR_Idef is not aliased.

   RNDef_RIndef : Tag_Type renames XNDef_RIndef.C;                    -- ERROR:
            -- Subtype of XNDef_RIndef is unconstrained, definite.

   ----------------------------------------------------------------------
   -- XR_Def.C1 and XR_Def.C2 depend on discriminants of XR_Def, whose
   -- subtype is unconstrained but definite; XR_Def is not aliased.

   RR_Def1     : String renames XR_Def.C1;                            -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   RR_Def2     : NDef_RIndef renames XR_Def.C2;                       -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   ----------------------------------------------------------------------
   -- XR_Def.C3.C depends on discriminants of XR_Def.C3, whose subtype is
   -- indefinite. But XR_Def.C3 depends on discriminants of XR_Def, whose
   -- subtype is unconstrained but definite; XR_Def is not aliased.

   RR_Def3     : Tag_Type renames XR_Def.C3.C;                        -- ERROR:
                  -- Subtype of XR_Def is unconstrained, definite.

   ----------------------------------------------------------------------
   -- ANewR_Def.C1 and AnewR_Def.C2 depend on discriminants of AnewR_Def,
   -- whose subtype is unconstrained but definite; ANewR_Def is aliased.

   RNewR_Def1  : String renames ANewR_Def.C1;                         -- ERROR:
       -- Subtype of ANewR_Def is unconstrained, definite. Change from Ada 95.

   RNewR_Def2  : NDef_RIndef renames ANewR_Def.C2;                    -- ERROR:
       -- Subtype of ANewR_Def is unconstrained, definite. Change from Ada 95.

   ----------------------------------------------------------------------
   -- XVar_Rec.CT depends on discriminants of XVar_Rec, whose subtype is
   -- unconstrained but definite; XVar_Rec is not aliased.

   RVar_Rec    : String renames XVar_Rec.CT;                          -- ERROR:
                -- Subtype of XVar_Rec is unconstrained, definite.

   ----------------------------------------------------------------------
   PAVar_Rec   : AccTag_Type := AVar_Rec.Not_Aliased'Access;          -- ERROR:
                                 -- Component of aliased object is not aliased.


--
-- Array type subtests:
--

   -- Implicit deference:
   PTag_Arr    : AccTag_Type := XTag_Arr(1)'Access;                   -- ERROR:
                                 -- Component of aliased object is not aliased.

end B3A2015;
