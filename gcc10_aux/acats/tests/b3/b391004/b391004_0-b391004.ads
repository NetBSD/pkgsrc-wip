

     --==================================================================--


with B391004_1;
package B391004_0.B391004 is   -- Public child unit.

--
-- (Non-extension) Tagged types - basic cases:
--

   type Tag1 is tagged record
      C : LimRec;                                                     -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
   end record;   

   type Tag2 is tagged record
      C : Tsk;                                                        -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
   end record;   

   type Tag3 is tagged record
      C : DerLimComp;                                                 -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
   end record;   

   type Tag4 is tagged record
      C : BecomesNL;                                                  -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
   end record;   


--
-- (Non-extension) Tagged types - generic cases:
--

   generic
      type FP is tagged limited private;
      type FD_LimRec    is new LimRec;
      type FD_LimComp   is new LimComp;
      type FD_LimFP     is new FP with private;
   package Tag_Generic_Cases is

      type TagA is tagged record
         C : FP;                                                      -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
      end record;   

      type TagB is tagged record
         C : FD_LimRec;                                               -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
      end record;   

      type TagC is tagged record
         C : FD_LimComp;                                              -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
      end record;   

      type TagD is tagged record
         C : FD_LimFP;                                                -- ERROR:
                                 -- Tagged type with limited components must be
                                 -- explicitly declared limited.
      end record;   

   end Tag_Generic_Cases;


--
-- Record extensions - generic cases:
--

   type LimTag    is tagged limited null record;
   type NonLimTag is tagged         null record;

   generic
      type FP is tagged private;
      type FD_NonLimFP is new FP with private;

      type FD_LimRec    is new LimRec;
      type FD_LimComp   is new LimComp;
      type FD_BecomesNL is new BecomesNL;
   package Ext_Generic_Cases is

      type DerA is new FP with record
         C : LimRec;                                                  -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   

      type DerB is new FD_NonLimFP with record
         C : Tsk;                                                     -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   

      type DerC is new FD_NonLimFP with record
         C : BecomesNL;                                               -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   

      type DerD is new FD_NonLimFP with record
         C : FD_LimComp;                                              -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   

      type DerE is new NonLimTag with record
         C : FD_LimRec;                                               -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   


   private

      type DerF is new NonLimTag with record
         C : FD_BecomesNL;                                            -- ERROR:
                          -- Parent of record extension with limited components
                          -- must be limited.
      end record;   

   end Ext_Generic_Cases;


--
-- Record extensions - instance cases:
--

   package Outer_LimFP is new B391004_1 (LimRec, LimComp);            -- OK.


   package Inst1 is new Outer_LimFP.GP_LimRec (NonLimTag);            -- ERROR:
                           -- Parent of record extension with limited component
                           -- must be declared limited.

   package Inst2 is new Outer_LimFP.GP_LimRec (LimTag);               -- OK.

   package Inst3 is new Outer_LimFP.GP_BecomesNL (NonLimTag);         -- ERROR:
                           -- Parent of record extension with limited component
                           -- must be declared limited.

   package Inst4 is new Outer_LimFP.GP_FP (NonLimTag);                -- ERROR:
                           -- Parent of record extension with limited component
                           -- must be declared limited.

   package Inst5 is new Outer_LimFP.GP_FD (NonLimTag);                -- ERROR:
                           -- Parent of record extension with limited component
                           -- must be declared limited.

   package Inst6 is new Outer_LimFP.GP_FD  (LimTag);                  -- OK.



   package Outer_NonLimFP is new B391004_1 (Boolean, LimComp);        -- OK.

   package Inst7 is new Outer_NonLimFP.GP_FP (NonLimTag);             -- OK.

private

--
-- (Non-extension) Tagged types - basic case:
--

   type Tag5 is tagged record
      C : BecomesNL;                                                  -- OK.
   end record;   


--
-- Record extensions - instance case:
--

   package Inst8 is new Outer_LimFP.GP_BecomesNL (NonLimTag);         -- OK.

end B391004_0.B391004;
