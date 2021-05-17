-- B431004
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
--    Check that legality rules for record component associations are
--    enforced for an extension aggregate. Specifically:
--      (A) The selector names can only name components and discriminants
--          of the record extension, and cannot name components of
--          other variants or of the type of the ancestor part;
--      (B) A component association (other than others => <>) is illegal
--          if it does not have an associated component;
--      (C) The aggregate is illegal if it has needed components that are
--          not associated with any component associations;
--      (D) The aggregate is illegal if it has a needed component that is
--          associated with more than one component association;
--      (E) A component association with an expression cannot have two or
--          more associated components of different types.
--
--    This test may appear to belong to 4.3.2 (which defines extension
--    aggregates), but the rules being tested are for record component
--    associations, and those are given in 4.3.1. Thus the test is
--    named as part of 4.3.1.
--
-- CHANGE HISTORY:
--    26 Apr 2007   RLB   Created test from outline of existing ACATS test.
--!

package B431004_Root is

   type Base is tagged record
      A : Integer := 11;
      C : Character := 'C';
   end record;

end B431004_Root;
