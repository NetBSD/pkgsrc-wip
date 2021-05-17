-- CXF2A01.A
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
--      Check that the binary adding operators for a decimal fixed point type
--      return values that are integral multiples of the small of the type.
--    
-- TEST DESCRIPTION:
--      The test verifies that decimal addition and subtraction behave as
--      expected for types with various digits, delta, and Machine_Radix
--      values. Types with the minimum values for Decimal.Max_Digits and
--      Decimal.Max_Scale (18) are included.
--
--      Two kinds of checks are performed for each type. In the first check,
--      the iteration, operation, and operand counts in the foundation and
--      the operation tables in this test are given values such that, when the
--      operations loop is complete, each operand will have been added to and
--      subtracted from the loop's cumulator variable the same number of times,
--      albeit in varying order. Thus, the result returned by the operations
--      loop should have the same value as that used to initialize the
--      cumulator (in this test, zero).
--
--      In the second check, the same operation (addition for some types and
--      subtraction for others) is performed during each loop iteration,
--      resulting in a cumulative total which is checked against an expected
--      value.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FXF2A00.A
--      -> CXF2A01.A
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Information Systems Annex.
--
--
-- CHANGE HISTORY:
--      08 Apr 96   SAIC    Prerelease version for ACVC 2.1.
--
--!

package CXF2A01_0 is

               ---=---=---=---=---=---=---=---=---=---=---

   type Micro is delta 10.0**(-18) digits 18; -- range -0.999999999999999999 ..
   for Micro'Machine_Radix use 10;     --              +0.999999999999999999

   function Add      (Left, Right : Micro) return Micro;
   function Subtract (Left, Right : Micro) return Micro;


   type Micro_Optr_Ptr is access function (Left, Right : Micro) return Micro;

   Micro_Add : Micro_Optr_Ptr := Add'Access;
   Micro_Sub : Micro_Optr_Ptr := Subtract'Access;

               ---=---=---=---=---=---=---=---=---=---=---

   type Money is delta 0.01 digits 11; -- range -999,999,999.99 ..
   for Money'Machine_Radix use 2;      --       +999,999,999.99

   function Add      (Left, Right : Money) return Money;
   function Subtract (Left, Right : Money) return Money;


   type Money_Optr_Ptr is access function (Left, Right : Money) return Money;

   Money_Add : Money_Optr_Ptr := Add'Access;
   Money_Sub : Money_Optr_Ptr := Subtract'Access;

               ---=---=---=---=---=---=---=---=---=---=---

   -- Same as Money, but with Radix 10:

   type Cash is delta 0.01 digits 11; -- range -999,999,999.99 ..
   for Cash'Machine_Radix use 10;     --       +999,999,999.99

   function Add      (Left, Right : Cash) return Cash;
   function Subtract (Left, Right : Cash) return Cash;


   type Cash_Optr_Ptr is access function (Left, Right : Cash) return Cash;

   Cash_Add : Cash_Optr_Ptr := Add'Access;
   Cash_Sub : Cash_Optr_Ptr := Subtract'Access;

               ---=---=---=---=---=---=---=---=---=---=---

   type Broad is delta 10.0**(-9) digits 18; -- range -999,999,999.999999999 ..
   for Broad'Machine_Radix use 10;           --       +999,999,999.999999999

   function Add      (Left, Right : Broad) return Broad;
   function Subtract (Left, Right : Broad) return Broad;


   type Broad_Optr_Ptr is access function (Left, Right : Broad) return Broad;

   Broad_Add : Broad_Optr_Ptr := Add'Access;
   Broad_Sub : Broad_Optr_Ptr := Subtract'Access;

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2A01_0;
