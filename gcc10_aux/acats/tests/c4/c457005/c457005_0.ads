-- C457005.A
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
--     If the selecting expression of a case expression is a name with a static
--     nominal subtype and has a static predicate, the case statement does not
--     have an others choice, and the static predicate is disabled, then
--     Constraint_Error is raised if the value of the selecting expression
--     does not satisfy the predicate.
--
--     If the selecting expression of a case expression is a name with a static
--     nominal subtype and has a static predicate, the case statement has an
--     others choice, and the static predicate is disabled, then the statements
--     associated with the others choice are executed if the value of the
--     selecting expression does not satisfy the predicate.
--
-- TEST DESCRIPTION:
--     These objectives check 4.5.7(21/3); the first checks the last sentence,
--     and the second checks that 3.8.1(12) applies thus triggering the second
--     sentence of 4.5.7(21/3) when there is an others choice.
--     There are a number of other ways for this to happen in practice
--     (uninitialized objects, invalid values read from a stream,
--     invalid values created by Unchecked_Conversion), but all of those
--     ways involve evaluating an invalid value, which is a bounded error.
--     As such, this is the only reliable way to test this rule (otherwise,
--     the bounded error might prevent the actual test).
--
-- CHANGE HISTORY:
--     02 Dec 15   RLB     Created test; used some of the declarations and
--                         code from C540003 as a basis.
--!

with Ada.Assertions; use Ada.Assertions;
package C457005_0 is

   pragma Assertion_Policy (Ignore); -- Predicate checks are disabled for the
                                     -- the following declarations.

   type Small_Even is range 0 .. 10 with
     Static_Predicate => Small_Even in 0 | 2 | 4 | 6 | 8 | 10;

   type Prime is range 2 .. 20 with
     Static_Predicate => Prime in 2 | 3 | 5 | 7 | 11 | 13 | 17 | 19;

   type Color is
     (Red, Orange, Yellow, Green, Blue, Indigo, Violet);
   subtype RGB is Color with
     Static_Predicate => RGB = Red or RGB in Green .. Blue;
   subtype Other_Color is Color with
     Static_Predicate => Other_Color not in RGB;

end C457005_0;
