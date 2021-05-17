-- C3A0010.A
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
--      Check that an access-to-subprogram type in a generic instance may be
--      used to declare access-to-subprogram objects which invoke subprograms
--      in the instance.
--
-- TEST DESCRIPTION:
--      Declare a numeric type in the visible part of a generic package.
--      Declare two different math procedures that can be referred to by 
--      the access to procedure type.  
--
--      In the main program, instantiate the generic.  Declare an access 
--      to procedure type.  Call each procedure indirectly by dereferencing 
--      the access value.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      05 APR 96   SAIC    Header correction for 2.1
--
--!

generic
   type Real_Num is digits <>;

package C3A0010_0 is

   -- Type accesses to any math procedure
   type Math_Procedure_Ptr is access procedure   
       (First_Num, Second_Num : in  Real_Num;
        Result_Num            : out Real_Num);

   procedure Add      (First_Num, Second_Num : in  Real_Num;
                       Result_Num            : out Real_Num);

   procedure Subtract (First_Num, Second_Num : in  Real_Num;
                       Result_Num            : out Real_Num);

end C3A0010_0;
