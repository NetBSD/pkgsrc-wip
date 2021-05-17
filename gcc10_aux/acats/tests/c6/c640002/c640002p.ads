-- C640002.A
--
--                             Grant of Unlimited Rights
--
--     AdaCore holds unlimited rights in the software and documentation
--     contained herein. Unlimited rights are the same as those granted
--     by the U.S. Government for older parts of the Ada Conformity
--     Assessment Test Suite, and are defined in DFAR 252.227-7013(a)(19).
--     By making this public release, AdaCore intends to confer upon all
--     recipients unlimited rights equal to those held by the Ada Conformity
--     Assessment Authority. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever,
--     and to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. ADACORE MAKES NO EXPRESS OR IMPLIED WARRANTY AS
--     TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE SOFTWARE,
--     DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE OR
--     DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
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
--
--     This test is based on one submitted by AdaCore; AdaCore retains
--     the copyright on the test.
--
--*
--  OBJECTIVE:
--     Check that an abstract nondispatching operator provides a way
--     to eliminate an unwanted predefined operator.
--
--  TEST DESCRIPTION:
--      Ada 2005 revised 6.4(8) to ignore abstract nondispatching operations
--      for resolution. (See AI95-00310-1). The motivation was to allow
--      type declarations for systems of units to "remove" predefined
--      operations that have the wrong type.
--
--      This test checks that such a use works as intended; it is similar to
--      the example in the question of the AI.
--
--  CHANGE HISTORY:
--     3 May 2004  JM   Initial Version.
--    19 Dec 2014  RLB  Minor changes for issuance (name changes, comments);
--                      added additional checks.
--    13 Mar 2015  RLB  Eliminated overlong lines.
--
--!
package C640002P is
   type Unit is new Float;
   function "*" (L, R : Unit) return Unit is abstract; -- (1)
   function Image     (L : Unit) return String;

   type Unit_Squared is new Unit;
   function "*" (L, R : Unit) return Unit_Squared;     -- (2)
   function Image (L : Unit_Squared) return String;
end C640002P;
