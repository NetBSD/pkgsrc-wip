-- CC50A02.A
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
--      Check that a nonlimited tagged type may be passed as an actual to a
--      formal (non-tagged) private type. Check that if the formal type has
--      an unknown discriminant part, a class-wide type may also be passed as
--      an actual.
--
-- TEST DESCRIPTION:
--      A generic package declares a formal private type and defines a
--      stack abstraction. Stacks are modeled as singly linked lists of
--      pointers to elements. Pointers are used because the elements may
--      be unconstrained.
--
--      A generic testing procedure pushes an item onto a stack, then views
--      the item on top of the stack.
--
--      The formal private type has an unknown discriminant part, and
--      is thus indefinite. This allows both definite and indefinite types
--      (including class-wide types) to be passed as actuals. For tagged types,
--      definite implies nondiscriminated, and indefinite implies discriminated
--      (with known/unknown discriminants). 
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC50A00.A
--      -> CC50A02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Nov 95   SAIC    ACVC 2.0.1 fixes: Removed use of formal package
--                          exception name in exception choice.
--
--!

generic        -- Generic stack abstraction.
   type Item (<>) is private;                   -- Formal private type.
package CC50A02_0 is

   type Stack is private;

   procedure Push     (I : in Item; S : in out Stack);
   function  View_Top (S : Stack) return Item;

   -- ...Other stack operations...

   Stack_Empty : exception;

private

   type Item_Ptr is access Item;

   type Stack_Item;
   type Stack_Ptr is access Stack_Item;

   type Stack_Item is record
      Item : Item_Ptr;
      Next : Stack_Ptr;
   end record;

   type Stack is record
      Top  : Stack_Ptr := null;
      Size : Natural   := 0;
   end record;

end CC50A02_0;
