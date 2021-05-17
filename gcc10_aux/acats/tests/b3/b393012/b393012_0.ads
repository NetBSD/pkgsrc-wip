-- B393012.A
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
--      For nonformal tagged abstract types, check that:
--      Aggregates may not be defined or allocated of an abstract type.
--      Generic in parameters may not be of an abstract type.
--      A function with an access result type that designates an abstract
--      result type must be declared abstract.
--      The result type of a generic function may not be abstract.
--      The designated type of the access result type of a generic function
--      may not be abstract. The target of an assignment statement may not
--      be abstract. The return subtype indication of an extended
--      return statement may not be abstract.
--
-- TEST DESCRIPTION:
--      This test declares abstract private types, abstract private
--      extensions, and abstract record types. It then uses them in various
--      contexts.
--
--      This test checks the rules of 3.9.3(8/3) as updated by AI05-0073-1 and
--      AI05-0203-1, that are not tested in B393001. The test is created in
--      part from tests B393001 and BC55001.
--
--      Note: The objective of test B393001 includes checking abstract
--      aggregates, but the test itself contains no such test cases. We fix
--      that here.
--
-- CHANGE HISTORY:
--      22 Nov 19   RLB     Created from existing tests.
--
--!

package B393012_0 is

   type Abstract_Private is abstract tagged private;

   type Abstract_Visible is abstract tagged record
      Component : String (1 .. 7);
   end record;

   type Abstract_Extension is abstract           -- An abstract private
     new Abstract_Visible with private;          -- extension.

   type Abstract_Ptr is access Abstract_Visible;

private
   type Abstract_Private is abstract tagged null record;

   type Abstract_Extension is
     new Abstract_Visible with null record;                  -- OK.    {1:4;1}

end B393012_0;
