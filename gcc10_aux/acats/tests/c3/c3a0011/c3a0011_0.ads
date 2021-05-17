-- C3A0011.A
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
--      Check that an access-to-subprogram object whose type is declared in a
--      parent package, may be used to invoke subprograms in a child package.
--      Check that such access objects may be stored in a data structure and
--      that subprograms may be called by walking the data structure.
-- 
-- TEST DESCRIPTION:
--      In the package, declare an access to procedure type.  Declare an 
--      array of the access type.  Declare three different procedures that 
--      can be referred to by the access to procedure type.           
--
--      In the visible child package, declare two procedures that can be 
--      referred to by the access to procedure type of the parent.  Build 
--      the array by calling each procedure indirectly through the access 
--      value.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Dec 94   SAIC    Improved visibility of "/=" in main body
--
--!

package C3A0011_0 is -- Interpreter
   
   type Compass_Point is mod 360;

   function Heading return Compass_Point;

   -- Type accesses to any procedure
   type Action_Ptr is access procedure;
   
   -- Array of access to procedure
   type Action_Array is array (Natural range <>) of Action_Ptr;

   procedure Rotate_Left;

   procedure Rotate_Right;

   procedure Center;

private
   The_Heading : Compass_Point := Compass_Point'First;

end C3A0011_0;
