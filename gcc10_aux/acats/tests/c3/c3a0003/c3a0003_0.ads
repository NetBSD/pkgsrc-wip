-- C3A0003.A
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
--      Check that a function in a generic instance can be called using
--      an access-to-subprogram value.
--
-- TEST DESCRIPTION:
--      Declare a numeric type in the visible part of a generic package.
--      Declare an access to function type.  Declare three different sine 
--      functions that can be referred to by the access to function type.  
--
--      In the main program, instantiate the generic.  Call each function 
--      indirectly by dereferencing the access value.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

generic
   type Real_Num is digits <>;

package C3A0003_0 is
   
   TC_Call_Tag : Natural := 0;

   -- Type accesses to any sine function
   type Sine_Function_Ptr is access function   
      (Angle : in Real_Num) return Real_Num;

   function Sine_Calc_Fast  (Angle : in Real_Num) return Real_Num;         

   function Sine_Calc_Acc   (Angle : in Real_Num) return Real_Num;        

   function Sine_Calc_Table (Angle : in Real_Num) return Real_Num;        

end C3A0003_0;
