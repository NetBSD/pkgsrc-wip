-- CC54003.A
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
--      Check that a general access-to-subprogram type may be passed as an
--      actual to a generic formal access-to-subprogram type. Check that
--      designated subprograms may be called by dereferencing the access
--      values.
--
-- TEST DESCRIPTION:
--      The generic implements a stack of access-to-subprogram objects as an
--      array. The profile of the access-to-subprogram formal corresponds to
--      a function which accepts a parameter of some type and returns an
--      object of the same type.
--      
--      For this test, the functions for which access values will be pushed
--      onto the stack accept a parameter of type access-to-string, lengthen
--      the pointed-to string, then return an access object pointing to this
--      lengthened string.
--      
--      The instance declares a function Execute_Stack which executes each
--      subprogram on the stack in sequence. This function accepts some initial
--      access-to-string, then returns an access object pointing to the
--      lengthened string resulting from the execution of the stacked
--      subprograms. Access-to-string objects are used rather than strings
--      themselves because the initial string "grows" during each iteration.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate to context clause
--                          preceding CC54003_2.
--
--!

generic

   Size : in Positive;

   type Item_Type (<>) is private;
   type Item_Ptr is access Item_Type;

   type Function_Ptr is access function (Item : Item_Ptr) 
     return Item_Ptr;

package CC54003_0 is -- Generic stack of pointers.

   type Stack_Type is private;

   procedure Push (Stack    : in out Stack_Type;
                   Func_Ptr : in     Function_Ptr);

   function Execute_Stack (Stack         : Stack_Type;
                           Initial_Input : Item_Ptr) return Item_Ptr;

   -- ... Other operations.

private

   subtype Index is Positive range 1 .. (Size + 1);
   type Stack_Type is array (Index) of Function_Ptr;       -- Last slot unused.

   Top : Index := 1;                  -- Top refers to the next available slot.

end CC54003_0;
