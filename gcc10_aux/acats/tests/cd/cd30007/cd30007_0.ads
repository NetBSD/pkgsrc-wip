-- CD30007.A
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
--
-- OBJECTIVE:
--      Check that the implementation supports specifying Sizes for
--      types, including full types for private types, using aspect
--      specifications.
--
-- TEST DESCRIPTION:
--      This test is loosely based on existing tests CD2A21C, CD2A22E,
--      and CD2A31C, as our primary purpose is to test aspect specifications
--      rather than the aspect Size. We make the some of the
--      same requirements as in those tests in order to ensure that the aspect
--      is actually implemented rather than ignored.
--
--      The test tries using constants declared after the aspect
--      specifications as the aspects are not supposed to be evaluated
--      until the freezing point of the entities. Note that in this
--      case, there is no need for declaring these constants later,
--      but in real programs this feature can be critical.
--
--      The test defines several types in package specifications and
--      attempts to specify aspect Size for all of them. It then uses
--      instances of Length_Check to ensure that the aspect Size is
--      actually as specified.
--
--      Note that we assign this test to 13.3 (where the Size attribute is
--      defined) rather than 13.1.1(31/3) which states that we can specify
--      representation attributes this way. Since 13.1.1(31/3) is a blanket
--      applying to a large number of attributes, it is less interesting
--      than the details of the aspect itself.
--
-- APPLICABILITY CRITERIA:
--      All implementations must attempt to compile this test.
--
--      For implementations validating against Systems Programming Annex (C):
--        this test must execute and report PASSED.
--
--      For implementations not validating against Annex C:
--        this test may report compile time errors at one or more points
--        indicated by "-- ANX-C RQMT", in which case it may be graded as
--        inapplicable. Otherwise, the test must execute and report PASSED.
--
-- CHANGE HISTORY:
--      27 Sep 13   RLB    Created test from CD2A21C, CD2A22E, and CD2A31C.
--      27 Nov 13   RLB    Added missing applicability criteria and messages.
--      20 Mar 14   RLB    Readied to issue; minor changes to comments.
--      13 Mar 15   RLB    Eliminated overlong lines.
--!

----------------------------------------------------------------- CD30007_0

package CD30007_0 is

   -- Contains basic declarations.

   type Basic_Enum is (A, B, C, D, E);
   Specified_Enum_Size : constant := Basic_Enum'Size;

   type Basic_Int is range -60 .. 80;
   Specified_Int_Size : constant := 9;

end CD30007_0;
