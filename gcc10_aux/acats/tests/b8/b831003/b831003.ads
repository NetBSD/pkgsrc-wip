-- B8310030
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
--
--    Check that an operation with an indicator of "overriding" is illegal if
--    it does not override a homograph at the place of the declaration or body
--    even though the operation is overridden later.
--
--    Check that an operation with an indicator of "not overriding" is illegal
--    if it overrides a homograph even if the operation is overridden later.
--
-- TEST DESCRIPTION
--    This test checks cases where overridings happen later. (Simple cases
--    are tested in B831002.)
--
-- TEST FILES:
--      This test consists of the following files:
--      -> B8310030.A
--         B8310031.A
--         B8310032.A
--         B8310033.A
--
-- PASS/FAIL CRITERIA:
--      Files B8310031.A, B8310032.A, and B8310033.A contain errors. All
--      errors in these files must be detected to pass the test.
--
-- CHANGE HISTORY:
--      22 Aug 2007   RLB   Created test from submitted test. Added child
--                          private part cases. Added interesting not
--                          overriding cases.
--
--!
package B831003 is

    type T is private;

    overriding
    function "=" (X, Y : T) return Boolean; -- OK

    function "or" (X, Y : T) return T;

private

    function "xor" (X, Y : T) return T;

    type T is new Boolean;

    overriding
    function "and" (X, Y : T) return T; -- OK

end B831003;
