-- CXF2005.A
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
--      Check that the multiplying operators for a decimal fixed point type
--      return values that are integral multiples of the small of the type.
--      Check the case where one operand is of the predefined type Integer.
--
-- TEST DESCRIPTION:
--      Two decimal fixed point types A and B are declared, one with a
--      Machine_Radix value of 2, and one with a value of 10. A variable of
--      each type is multiplied repeatedly by a series of different Integer
--      values. A cumulative result is kept and compared to an expected
--      final result. Similar checks are performed for division.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Information Systems Annex.
--
--
-- CHANGE HISTORY:
--      28 Mar 96   SAIC    Prerelease version for ACVC 2.1.
--
--!

generic
   type Decimal_Fixed  is delta <> digits <>;
package CXF2005_0 is

   function Multiply (Operand  : Decimal_Fixed;
                      Interval : Integer) return Decimal_Fixed;

   function Divide   (Operand  : Decimal_Fixed;
                      Interval : Integer) return Decimal_Fixed;

end CXF2005_0;
