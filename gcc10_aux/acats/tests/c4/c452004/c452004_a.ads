-- C452004.A
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
--     Check that for a membership test with multiple choices, the tested
--     expression is evaluated first, and then the choices are evaluated
--     in order.
--
--     Check that for a membership test with multiple choices, choices after
--     the first individual membership test that evaluates True are not
--     evaluated.
--
--     Check that an individual membership test that is an expression of an
--     untagged record yields True if the primitive equals for the type yields
--     True, and False otherwise.
--
-- TEST DESCRIPTION:
--     A user application uses a rational arithmetic package, and wishes to
--     use membership tests on values of that package.
--
--     We create a skeleton rational arithmetic package, with each subprogram
--     in the package using TCTouch to record when it is called.
--
--     We then write various membership tests and check both that the result
--     is correct and that the rational subprograms are called in the expected
--     order.
--
--     RM 4.5.2(27.1/4) and 4.5.2(28.1/4) are the primary paragraphs tested
--     herein.
--
--     Note: We don't try to describe a use case for the use of the
--     memberships, since these are an alternative to using "=", and we
--     wouldn't try to justify the use of "=" as it is so common that we expect
--     that every possible case will appear eventually.
--
-- CHANGE HISTORY:
--    27 Mar 2019   RLB   Created test.
--    06 Feb 2020   RLB   Corrected types of LTemp and RTemp.
--
--!

package C452004_A is
   -- A skeleton rational arithmetic package.
   -- Note: Because the values are integers (which could be as small as
   -- 16-bits), and because we don't try to reduce demoninators, the values
   -- of numerators and denominators given to this packages should be less
   -- than 100.

   type Rat is private;

   function Zero return Rat;

   function One return Rat;

   function Val (Num : Integer; Dem : Positive) return Rat;

   function "/" (Num : Integer; Dem : Positive) return Rat renames Val;

   function "=" (Left, Right : Rat) return Boolean;

   function "+" (Right : Rat) return Rat;

   function "-" (Right : Rat) return Rat;

   function "+" (Left, Right : Rat) return Rat;

   function "-" (Left, Right : Rat) return Rat;

private

   type Rat is record
      Num : Integer;
      Dem : Positive;
   end record;

end C452004_A;
