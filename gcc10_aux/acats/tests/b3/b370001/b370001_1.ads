

     --==================================================================--


with B370001_0;
use  B370001_0;
package B370001_1 is

--
-- Basic cases:
--

   type LocalNonLimRec (D: access Disc := A_Disc) is record           -- ERROR:
                            -- Non-task/protected type with access discriminant
                            -- must be explicitly declared limited.
      C: TaggedLimRec;
   end record;

   type DerDerLimRec (D: access Disc := A_Disc) is new DerLimRec(D);  -- OK.
      -- Parent of DerLimRec is explicitly limited.

--
-- Generic cases:
--

   generic
      type FP    (DD: access Disc) is private;
   package Generic_Cases is

      type Der_FP (D: access Disc := A_Disc) is new FP(D);            -- ERROR:
                                     -- Parent type is not limited.

      -- Can't test untagged derived cases, because we can't add discriminants
      -- when deriving an untagged type and we can't have known discriminants
      -- for formal derived types.
   end Generic_Cases;

   -- Generic body cases tested by Some_Generic_Cases.

--
-- Instance cases:
--

   generic
      type FP (DD: access Disc) is limited private;
   package GenLP is
      type DFP (D: access Disc := A_Disc) is new FP(D);  -- Checked in instance.
   end GenLP;

   package Instance_Tsk       is new GenLP (Tsk);                     -- OK.
   package Instance_PT        is new GenLP (PT);                      -- OK.
   package Instance_LimRec    is new GenLP (LimRec);                  -- OK.
   package Instance_NonLimRec is new GenLP (NonLimRec);               -- ERROR:


end B370001_1;
