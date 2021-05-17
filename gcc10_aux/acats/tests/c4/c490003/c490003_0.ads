-- C490003.A
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
--      Check that a static expression is legal if its evaluation fails
--      no language-defined check other than Overflow_Check. Check that such
--      a static expression is legal if it is part of a larger static
--      expression, even if its value is outside the base range of the
--      expected type.
--
--      Check that if a static expression is part of the right operand of a
--      short circuit control form whose value is determined by its left
--      operand, it is not evaluated.
--
--      Check that a static expression in a non-static context is evaluated
--      exactly.
--
-- TEST DESCRIPTION:
--      The first part of the objective is tested by constructing static
--      expressions which involve predefined operations of integer, floating
--      point, and fixed point subtypes. Intermediate expressions within the
--      static expressions have values outside the base range of the expected
--      type. In one case, the extended-range intermediates are compared as
--      part of a boolean expression. In the remaining two cases, further
--      predefined operations on the intermediates bring the final result
--      within the base range. An implementation which compiles these static
--      expressions satisfies this portion of the objective. A check is
--      performed at run-time to ensure that the static expressions evaluate
--      to values within the base range of their respective expected types.
--
--      The second part of the objective is tested by constructing
--      short-circuit control forms whose left operands have the values
--      shown below:
--
--         (TRUE)  or else  (...)
--         (FALSE) and then (...)
--    
--      In both cases the left operand determines the value of the condition.
--      In the test each right operand involves a division by zero, which will
--      raise Constraint_Error if evaluated. A check is made that no exception
--      is raised when each short-circuit control form is evaluated, and that
--      the value of the condition is that of the left operand.
--    
--      The third part of the objective is tested by evaluating static
--      expressions involving many operations in contexts which do not
--      require a static expression, and verifying that the exact
--      mathematical results are calculated.
--    
--
-- CHANGE HISTORY:
--      15 Sep 95   SAIC    Initial prerelease version for ACVC 2.1.
--      20 Oct 96   SAIC    Modified expressions in C490003_0 to avoid
--                          the use of universal operands.
--
--!

with System;
package C490003_0 is

   type My_Flt is digits System.Max_Digits;

   Flt_Range_Diff : My_Flt := (My_Flt'Base'Last - My_Flt'Base'First) -
                              (My_Flt'Last - My_Flt'First);           -- OK.


   type My_Fix is delta 0.125 range -128.0 .. 128.0;

   Symmetric : Boolean := (My_Fix'Base'Last - My_Fix'Base'First) = 
                          (My_Fix'Base'Last + My_Fix'Base'Last);      -- OK.


   Center : constant Integer := Integer'Base'Last -
                                 (Integer'Base'Last -
                                  Integer'Base'First) / 2;            -- OK.

end C490003_0;
