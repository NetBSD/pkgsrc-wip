-- B354001.A
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
--      Check that the expression of a modular_type_definition must be
--      static and that the expected type of the expression can be of any
--      integer type.  Check that the modulus must be positive.
--      Check that moduli that are powers of two are allowed up to and
--      including, but not exceeding, System.Max_Binary_Modulus.
--      Check that non-power-of-two moduli are allowed as long as they do
--      not exceed System.Max_Nonbinary_Modulus.
--      Check that the value of a potentially static expression of a
--      modular type that appears in a nonstatic context must be within
--      the base range of its expected type.
--      Check that the predefined logical operators and membership tests
--      are available.
--
-- TEST DESCRIPTION:
--      Declarations using expressions of the form:
--      (System.Max_Binary_Modulus/2 and System.Max_Binary_Modulus*2)
--      test for bounding conditions.
--      This test declares modular types in contexts where Ada'83
--      would consider the "potentially static expression"s not-static,
--      where an Ada'9X compiler should consider the value static.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Dec 94   SAIC    Fix range misconception
--
--!

package B354001_0 is

  type Cents is mod 100;                                              -- OK
  Pennies     : Cents := 50;
  Half_Dollar : constant Cents := Pennies;  

  type Bight is mod 256;                                              -- OK

  Number : constant := 1.54321;

end B354001_0;
