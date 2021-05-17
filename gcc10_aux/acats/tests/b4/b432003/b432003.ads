-- B432003.A
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
--     Check that the subtype_mark of an extension aggregate cannot denote a
--     view of a type that has unknown discriminants.
--
-- TEST DESCRIPTION:
--
--     The test declares a root private type, and then various extensions
--     of that type in a child package and an unrelated package. Finally,
--     extensions of the extensions are declared in a child package. The
--     tests are then carried out in the body of the root package, where the
--     full root type is visible, but the it is not visible for the extensions
--     which derive from the partial view of the root type. Note that the
--     full type for these tests does not have any discriminants; the purpose
--     of the unknown discriminants is just to prevent the creation of default
--     initialized objects.
--
--     This objective comes from a rule added by AI05-0115-1. Since the purpose
--     of unknown discriminants is to prevent the creation of default
--     initialized objects, it doesn't make sense to allow the ancestor of an
--     an extension aggregate to be a subtype with unknown discriminants (as
--     that created a default-initialized parent part).
--
-- CHANGE HISTORY:
--      30 Dec 19   RLB     Created test.
--!

package B432003 is

   type Root (<>) is tagged private;

   procedure Force_Body;

private

   type Root is tagged record
      C1 : Integer := 0;
   end record;

end B432003;
