

     --==================================================================--


with B460001_0;
procedure B460001 is

   AD_1 : B460001_0.Acc_Disc;

   type GAccObj_L1 is access all B460001_0.Obj_Type;            -- Level = 1.
   type PAccObj_L1 is access     B460001_0.Obj_Type;            -- Level = 1.

   GSA_1 : GAccObj_L1;

   type GAccTag_L1 is access all B460001_0.Tag_Type;            -- Level = 1.
   type PAccDer_L1 is access     B460001_0.Der_Type;            -- Level = 1.

   PSAD_1 : PAccDer_L1;


   procedure TagCall_L1 (X : GAccTag_L1) is     -- Subprogram with parameter
   begin                                        -- of a general access type:
      null;                                     -- tagged designated type.
   end TagCall_L1;


   --
   -- Nested subprogram:
   --

   procedure Nested (GFP_1 : GAccObj_L1;         -- Parameter type level = 1.
                     PFP_1 : PAccObj_L1) is      -- Parameter type level = 1.

      AD_2 : B460001_0.Acc_Disc;

      type GAccObj_L2 is access all B460001_0.Obj_Type;         -- Level = 2.

      GSA_2 : GAccObj_L2;

      type GAccDer_L2 is access all B460001_0.Der_Type;         -- Level = 2.
      type GAccCls_L2 is access all B460001_0.Tag_Type'Class;   -- Level = 2.

      GSAC_2 : GAccCls_L2;


      procedure TagCall_L2 (X : GAccDer_L2) is  -- Subprogram with parameter
      begin                                     -- of a general access type:
         null;                                  -- tagged designated type.
      end TagCall_L2;


      --
      -- Doubly-nested subprogram:
      --

      procedure Doubly_Nested 
                 (GFPC_0 : B460001_0.GAccCls_L0;    -- Param. type level = 0.
                  PFPD_1 : PAccDer_L1;              -- Param. type level = 1.
                  GFPC_2 : GAccCls_L2) is           -- Param. type level = 2.

         type GAccDer_L3 is access all B460001_0.Der_Type;      -- Level = 3.
         type PAccCls_L3 is access     B460001_0.Der_Type;      -- Level = 3.

         GSAD_3 : GAccDer_L3;
         PSAC_3 : PAccCls_L3;

      begin -- Doubly_Nested.

         -- Operand is a formal parameter:

         TagCall_L1 (GAccTag_L1(GFPC_0));                           -- OK.
         TagCall_L1 (GAccTag_L1(PFPD_1));                           -- OK.
         TagCall_L1 (GAccTag_L1(GFPC_2));                           -- ERROR:
                                        -- Accessibility level of GAccCls_L2 
                                        -- is deeper than that of GAccTag_L1.


         -- Operand is a stand-alone object:

         TagCall_L1 (GAccTag_L1(GSAD_3));                           -- ERROR:
                                     -- Accessibility level of GAccDer_L3 is 
                                     -- deeper than that of GAccTag_L1.

         TagCall_L2 (GAccDer_L2(B460001_0.GSAC_0));                 -- OK.
         TagCall_L2 (GAccDer_L2(PSAD_1));                           -- OK.
         TagCall_L2 (GAccDer_L2(GSAC_2));                           -- OK.
         TagCall_L2 (GAccDer_L2(PSAC_3));                           -- ERROR:
                                     -- Accessibility level of PAccCls_L3 is 
                                     -- deeper than that of GAccDer_L2.

      end Doubly_Nested;


   begin -- Nested.

      -- Operand is a formal parameter:

      B460001_0.GSA_0 := B460001_0.GAccObj_L0(GFP_1);               -- ERROR:
                                 -- Accessibility level of GAccObj_L1 is 
                                 -- deeper than that of B460001_0.GAccObj_L0.

      GSA_1 := GAccObj_L1(PFP_1);                                   -- OK.


      -- Operand is an access discriminant:

      B460001_0.GSA_0 := B460001_0.GAccObj_L0(AD_2.D);              -- ERROR:
                                   -- Accessibility level of AD_2.D is deeper
                                   --than that of B460001_0.GAccObj_L0.

      GSA_2 := GAccObj_L2(B460001_0.AD_0.D);                        -- OK.

   end Nested;



begin -- B460001

   -- Operand is a stand-alone object:

   B460001_0.GSA_0 := B460001_0.GAccObj_L0(B460001_0.PSA_0);        -- OK.
   GSA_1 := GAccObj_L1(B460001_0.GSA_0);                            -- OK.


   -- Operand is an access discriminant:

   B460001_0.GSA_0 := B460001_0.GAccObj_L0(B460001_0.AD_0.D);       -- OK.
   B460001_0.GSA_0 := B460001_0.GAccObj_L0(AD_1.D);                 -- ERROR:
                                    -- Accessibility level of AD_1 is deeper 
                                    --than that of B460001_0.GAccObj_L0.

   GSA_1 := GAccObj_L1(B460001_0.AD_0.D);                           -- OK.
   GSA_1 := GAccObj_L1(AD_1.D);                                     -- OK.

end B460001;
