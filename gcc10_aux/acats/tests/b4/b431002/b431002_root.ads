-- B431002
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
--    Check that syntax rules for the record component association list are
--    enforced for an extension aggregate. Specifically:
--      (A) A positional component association cannot have a <> rather than
--          an expression;
--      (B) Named components cannot precede any positional components;
--      (C) An others component association cannot appear anywhere other
--          than last.
--
-- TEST DESCRIPTION:
--    This objective is testing syntax errors. However, these errors is
--    much more likely to occur in practice than most syntax errors, so we
--    test for them. Moreover, the complex grammar of aggregates and the fact
--    that some of these rules are described in text rather than BNF suggests
--    that it is likely that many implementations will implement them as
--    legality checks, rather than as part of the syntax.
--
--    Illegal aggregates have been surrounded by correct code to ease
--    error recovery.
--
--    This test may appear to belong to 4.3.2 (which defines extension
--    aggregates), but the rules being tested are for record component
--    association list, and those are given in 4.3.1. Thus the test is
--    named as part of 4.3.1.
--
-- CHANGE HISTORY:
--    26 Apr 2007   RLB   Created test from outline of existing ACATS test.
--!

package B431002_Root is

   type Base is tagged record
      A : Integer := 11;
      C : Character := 'C';
   end record;

end B431002_Root;
