-- C460007.A
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
--      Check that, in a numeric type conversion, if the target type is an
--      integer type and the operand type is real, the result is rounded
--      to the nearest integer, and away from zero if the result is exactly
--      halfway between two integers. Check for static and non-static type
--      conversions.
--
-- TEST DESCRIPTION:
--      The following cases are considered:
--
--          X.5    X.5 + delta   -X.5 + delta
--         -X.5    X.5 - delta   -X.5 - delta
--
--      Both zero and non-zero values are used for X. The value of delta is
--      chosen to be a very small increment (on the order of 1.0E-10). For
--      fixed and floating point cases, the value of delta is chosen such that
--      "(-)X.5 +(-) delta" is a multiple of the small, or a machine number,
--      respectively.
--
--      The following type conversions are performed:
--
--      ID   Real operand            Cases          Target integer subtype
--      ------------------------------------------------------------------
--       1   Real named number        X.5           Nonstatic
--       2                            X.5 - delta   Nonstatic
--       3                           -X.5 - delta   Static
--       4   Real literal            -X.5           Static
--       5                            X.5 + delta   Static
--       6                           -X.5 + delta   Nonstatic
--       7   Floating point object   -X.5 - delta   Nonstatic
--       8                            X.5 - delta   Static
--       9   Fixed point object       X.5           Static
--      10                            X.5 + delta   Static
--      11                           -X.5 + delta   Nonstatic
--      The conversion is either assigned to a variable of the target subtype
--      or passed as a parameter to a subprogram (both nonstatic contexts).
--
--      The subprogram Equal is used to circumvent potential optimizations.
--
--
-- CHANGE HISTORY:
--      03 Oct 95   SAIC    Initial prerelease version.
--
--!

with System;
package C460007_0 is

--
-- Target integer subtype (static):
--

   type Static_Integer_Subtype is range -32_000 .. 32_000;

   Static_Target : Static_Integer_Subtype;

   function Equal (L, R: Static_Integer_Subtype) return Boolean;


--
-- Named numbers:
--

   NN_Half      : constant := 0.5000000000;
   NN_Less_Half : constant := 126.4999999999;
   NN_More_Half : constant := -NN_Half - 0.0000000001;


--
-- Floating point:
--

   type My_Float is digits System.Max_Digits;

   Flt_Rnd_Toward_Zero :          My_Float := My_Float'Pred(NN_Half);
   Flt_Rnd_Away_Zero   : constant My_Float := My_Float'Pred(-113.5);


--
-- Fixed point:
--

   type My_Fixed is delta 0.1 range -5.0 .. 5.0;

   Fix_Half            :          My_Fixed := 0.5;
   Fix_Rnd_Away_Zero   :          My_Fixed := Fix_Half + My_Fixed'Small;
   Fix_Rnd_Toward_Zero : constant My_Fixed := -3.5 + My_Fixed'Small;

end C460007_0;
