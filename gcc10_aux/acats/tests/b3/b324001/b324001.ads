-- B324001.A
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
--     Check that a predicate aspect must be of boolean type. Check that a
--     predicate may be given only on type and subtype declarations. Check
--     that a predicate may not be given on an incomplete subtype. Check
--     that a Static_Predicate must be predicate-static.
--
-- TEST DESCRIPTION:
--     Try various declarations that violate the rules. Detailed checks are
--     as follows:
--
--     (A) Non-boolean predicate expressions.
--     (B) Predicate aspect given on something other than a type or subtype
--         declaration.
--     (C) Predicate aspect given on a subtype of an incomplete type.
--     (D) Expression of a Static_Predicate containing a non-static function
--         call.
--     (E) Expression of a Static_Predicate containing a non-static call to
--         a arithmetic operator, including predefined operators operating
--         on the current instance.
--     (F) Expression of a Static_Predicate is a non-static membership whose
--         tested expression is not the current instance.
--     (G) Expression of a Static_Predicate is a membership where one or more
--	   choices is non-static even when the tested expression is the current
--	   instance.
--     (H) Expression of a Static_Predicate is a non-static case expression
--         whose tested expression is not the current instance.
--     (I) Expression of a Static_Predicate is a case expression where one or
--         more dependent_expressions is non-static even when the selecting
--         expression is the current instance.
--     (J) Expression of a Static_Predicate is a non-static call to a
--         predefined ordering or equality operator if neither operand is
--         the current instance.
--     (K) Expression of a Static_Predicate is a call to a predefined ordering
--         or equality operator where one operand is non-static even when the
--         other operand is the current instance.
--     (L) Expression of a Static_Predicate is a call to a predefined logical
--         operator if either operand is not predicate static.
--     (M) Expression of a Static_Predicate is a short circuit control form if
--         either operand is not predicate static.
--     (N) Expression of a Static_Predicate is a parenthesized expression if
--         the operand is not predicate static.
--     (Q) Expression of a Static_Predicate is non-static object.
--
--
-- CHANGE HISTORY:
--      14 Jan 12   RAD     Initial version.
--      26 May 14   RLB     Split test into two parts, added test cases.
--
--!

package B324001 is

   Named_Number: constant := 1;

   function Int_Func (X: Integer) return Integer;

   function Is_Good (X: String) return Boolean;
   function Is_Good (X: String) return Integer;

end B324001;
