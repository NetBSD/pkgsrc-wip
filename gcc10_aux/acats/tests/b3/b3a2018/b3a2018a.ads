-- B3A2018.A
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
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--*
-- OBJECTIVE:
--      Check that an explicitly aliased parameter has the same
--      static accessibility level as a normal parameter unless it used to
--      compare with the level of the return object.
--
--      Check that "the master of the call" is correctly statically determined
--      for a call on a function containing explicitly aliased parameters.
--
-- TEST DESCRIPTION:
--      The rule for the first objective was clarified in AI05-0235-1, thus
--      it applies mainly to Ada 2012 and later. (As a correction, it could be
--      considered to apply to older versions of Ada, but we generally do not
--      enforce that in the ACATS. This rule was then confirmed by AI12-0277-1
--      as issues had arisen in practice.
--
--      We used examples like the ones in both of those AIs, as well as
--      various legal cases to check that the rule is enforced correctly.
--
--      For the second objective, we only concern ourselves with cases where
--      it is clear that the master determined as "the master of the call"
--      is statically nested insider of the master that is being tested.
--      If this is not true, there would be no static check, but a dynamic
--      check might be necessary. Only 3.10.2(10.2/3, 10.3/3, and 10.6/3) are
--      testable here.

-- CHANGE HISTORY:
--      11 May 18   RLB     Initial version.
--!
package B3A2018A is

   type Int is range -100 .. 100;

   type P_AC_Int is access constant Int;

   PVA1 : aliased Int := 90;

end B3A2018A;
