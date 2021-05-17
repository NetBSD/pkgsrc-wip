-- BC50004.A
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
--      Check that the actual corresponding to a formal ordinary fixed point
--      type may not be a decimal fixed point type.
--
--      Check that the actual corresponding to a formal decimal fixed point
--      type may not be a ordinary fixed point type.
--
-- TEST DESCRIPTION:
--      Declare formal ordinary and decimal fixed point types. Verify that the
--      actual type passed to each formal must be in the class of types
--      implied by the syntactic category of the formal type definition (e.g.,
--      the actual for a formal decimal fixed point type must be a decimal
--      fixed point type).
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable to implementations which support smalls
--      that are powers of 10 (as is required by decimal fixed point types),
--      and to implementations which allow decimal fixed point type 
--      declarations.
--
-- PASS/FAIL CRITERIA:
--      For implementations which do not support smalls that are powers of
--      10, the declarations of types BC50004_0.Ordinary_Fixed and
--      BC50004_0.Decimal_Fixed must be flagged as illegal.
--
--
-- CHANGE HISTORY:
--      01 Feb 95   SAIC    Initial version.
--      10 Apr 96   SAIC    Corrected digits value for BC50004_0.Decimal_Fixed.
--
--!


package BC50004_0 is

   type Ordinary_Fixed is delta 0.01 range -10.0 .. 10.0;
   for Ordinary_Fixed'Small use 0.01;

   type Decimal_Fixed is delta 0.01 digits 4 range -10.0 .. 10.0;

end BC50004_0;
