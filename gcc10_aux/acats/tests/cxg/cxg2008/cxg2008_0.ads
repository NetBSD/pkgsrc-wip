-- CXG2008.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making
--     this public release, the Government intends to confer upon all
--     recipients unlimited rights  equal to those held by the Government.
--     These rights include rights to use, duplicate, release or disclose the
--     released technical data and computer software in whole or in part, in
--     any manner and for any purpose whatsoever, and to have or permit others
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check that the complex multiplication and division
--      operations return results that are within the allowed
--      error bound.
--      Check that all the required pure Numerics packages are pure.
--
-- TEST DESCRIPTION:
--      This test contains three test packages that are almost
--      identical.  The first two packages differ only in the
--      floating point type that is being tested.  The first
--      and third package differ only in whether the generic
--      complex types package or the pre-instantiated
--      package is used.
--      The test package is not generic so that the arguments
--      and expected results for some of the test values
--      can be expressed as universal real instead of being
--      computed at runtime.
--
-- SPECIAL REQUIREMENTS
--      The Strict Mode for the numerical accuracy must be
--      selected.  The method by which this mode is selected
--      is implementation dependent.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Numerics Annex.
--      This test only applies to the Strict Mode for numerical
--      accuracy.
--
--
-- CHANGE HISTORY:
--      24 FEB 96   SAIC    Initial release for 2.1
--      03 JUN 98   EDS     Correct the test program's incorrect assumption
--                          that Constraint_Error must be raised by complex
--                          division by zero, which is contrary to the
--                          allowance given by the Ada 95 standard G.1.1(40).
--      13 MAR 01   RLB     Replaced commented out Pure check on non-generic
--                          packages, as required by Defect Report
--                          8652/0020 and as reflected in Technical
--                          Corrigendum 1.
--!

------------------------------------------------------------------------------
-- Check that the required pure packages are pure by withing them from a
-- pure package. The non-generic versions of those packages are required to
-- be pure by Defect Report 8652/0020, Technical Corrigendum 1 [A.5.1(9/1) and
-- G.1.1(25/1)].
with Ada.Numerics.Generic_Elementary_Functions;
with Ada.Numerics.Elementary_Functions;
with Ada.Numerics.Generic_Complex_Types;
with Ada.Numerics.Complex_Types;
with Ada.Numerics.Generic_Complex_Elementary_Functions;
with Ada.Numerics.Complex_Elementary_Functions;
package CXG2008_0 is
  pragma Pure;
   -- CRC Standard Mathematical Tables;  23rd Edition; pg 738
   Sqrt2 : constant :=
        1.41421_35623_73095_04880_16887_24209_69807_85696_71875_37695;
   Sqrt3 : constant :=
        1.73205_08075_68877_29352_74463_41505_87236_69428_05253_81039;
end CXG2008_0;
