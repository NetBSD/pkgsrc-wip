-- C324004.A
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
--     Check that a static or dynamic predicate specified directly for a
--     type or subtype is not checked when it is disabled (the applicable
--     assertion policy is Ignore). Case A: global assertion policy pragma.
--
--     Check that a static or dynamic predicate specified directly for a
--     type or subtype still is evaluated for a membership even if it is
--     disabled (the applicable assertion policy is Ignore).
--
--     Check that a static or dynamic predicate specified directly for a
--     type or subtype still is evaluated for a Valid attribute even if it is
--     disabled (the applicable assertion policy is Ignore).
--
--     Check that a static predicate specified directly for a
--     type or subtype still is determines the items iterated by a for loop
--     on the type or subtype even if it is disabled (the applicable assertion
--     policy is Ignore).
--
-- CHANGE HISTORY:
--     14 May 15   RLB     Created test; used some of the declarations and
--                         code from C324001 as a basis.
--
with Ada.Assertions; use Ada.Assertions;
package C324004_0 is

   pragma Assertion_Policy (Ignore); -- Predicate checks are disabled for the
                                     -- the following declarations.

   type Even is range 0 .. Integer'Last with
     Dynamic_Predicate => (Even mod 2) = 0;

   type Prime is range 2 .. 20 with
     Static_Predicate => Prime in 2 | 3 | 5 | 7 | 11 | 13 | 17 | 19;

   type Color is
     (Red, Orange, Yellow, Green, Blue, Indigo, Violet);
   subtype RGB is Color with
     Static_Predicate => RGB = Red or RGB in Green .. Blue;
   subtype Other_Color is Color with
     Static_Predicate => Other_Color not in RGB;

   type Priv_T is private;
   subtype Priv_T_P is Priv_T with
     Dynamic_Predicate => Is_Good (Priv_T_P);

   function Is_Good (X : Priv_T) return Boolean;
   function Good return Priv_T;
   function Bad return Priv_T;
   -- Is_Good(Good) is True; Is_Good(Bad) is False.

   type String_Ref is access all String;

private

   type Priv_T is
      record
         Comp : Integer := 0;
         Acc : String_Ref := null;
      end record;

end C324004_0;
