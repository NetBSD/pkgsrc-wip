-- B324002.A
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
--     Check that array index subtypes and entry family subtypes can't have
--     predicates. Check that 'First and the like are not allowed for
--     scalar subtypes with predicates. Check that for loops are not allowed
--     for dynamic predicates. Check that a nonstatic subtype named in
--     an aggregate choice of a named array aggregate cannot have a predicate.
--     Check that a subtype with a dynamic predicate is not static.
--
-- TEST DESCRIPTION:
--     Declare miscellaneous entities that violate the rules. Specifically:
--
--     (A) Unconstrained array index subtypes with a predicate.
--     (B) Index constraints that is a subtype with a predicate.
--     (C) Slice indexing that is a subtype with a predicate.
--     (D) Constrained array index subtypes with a predicate.
--     (E) Entry family subtype with a predicate.
--     (F) Entry body subtype with a predicate.
--     (G) Prefix of 'First, 'Last, or 'Range with a predicate.
--     (H) Subtype of a for loop with a dynamic predicate.
--     (I) Aggregate choice that is a nonstatic subtype with a predicate.
--
--
-- CHANGE HISTORY:
--      14 Jan 12   RAD     Initial version.
--      26 May 14   RLB     Split test into two parts, added test cases.
--
--!

package B324002 is

   Named_Number: constant := 1;

   function Is_Good(X: String) return Boolean;
   function Is_Good(X: String) return Integer;

end B324002;
