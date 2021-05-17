-- C35A001.A
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
-- OBJECTIVES:
--     Check that Small can be specified with an aspect specification.
--
-- TEST DESCRIPTION:
--     This test was created using parts of existing tests CD10001,
--     CD1C03F, CD2D11A, and CD2D13A.
--
--     Note: We use only Smalls that are powers of two in this test,
--     as 3.5.9(21) does not require other values to be supported. This is
--     NOT a Recommended Level of Support, so the requirements don't change
--     because Annex C is or is not supported.
--
-- CHANGE HISTORY:
--     28 Mar 17   RLB     Created test.
--
--!
package C35A001_0 is

   Zero  : constant := 0;                                         -- Static
   One   : constant := 1;                                         -- Static
   Two   : constant := 2;                                         -- Static
   Three : constant := 3;                                         -- Static
   Four  : constant := 4;                                         -- Static
   Five  : constant := 5;                                         -- Static

   type Tenths is delta 0.1 range 0.0 .. 10.0
      with Small => 1.0 / (Two ** Five);

   type Specified is delta 2.0 ** (-4) range -4.0 .. 4.0;

   type Check_Type is delta 1.0 range -4.0 .. 4.0
      with Small => Specified_Small;

   type Derived_Type is new Tenths; -- Inherits Small value from parent.

   Specified_Small : constant := Specified'Small;
      -- We declare this late to check that the aspect specification isn't
      -- evaluated until the freezing point.

   procedure TC_Check_Values;

end C35A001_0;
