-- CDE0003.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that actuals for generic formal incomplete types and for formal
--      subprograms with formal untagged incomplete parameters do not need
--      to be frozen at instantiation.
--
-- TEST DESCRIPTION:
--      This test attempts to instantiate a signature package (CDE0003_0.G)
--      in the visible part of a package defining a private type (CDE0003_1)
--      which has primitive operations that are passed to the signature.
--      The signature package should not require freezing of either the
--      private type nor the primitive operations of the private type.
--      This is the motivating example for the formal incomplete type and
--      the associated freezing rules.
--
-- CHANGE HISTORY:
--      16 Nov 13   GRB     Initial version.
--      27 Nov 13   RLB     Added headers.
--      21 Apr 14   RLB     Simplified generic to make it legal, updated
--                          types and comments to make the test more realistic.
--
--!

package CDE0003_0 is

   generic
      type Incomplete;
      with function F (X : Incomplete) return Integer;
      with procedure P (X : Incomplete);
   package G is

      function Call_F (X : Incomplete) return Integer renames F;
      procedure Call_P (X : Incomplete) renames P;

   end G;

end CDE0003_0;
