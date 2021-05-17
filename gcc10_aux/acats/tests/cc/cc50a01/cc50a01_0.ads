-- CC50A01.A
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
--      Check that a formal parameter of a library-level generic unit may be
--      a formal tagged private type. Check that a nonlimited tagged type may
--      be passed as an actual. Check that if the formal type is indefinite,
--      both indefinite and definite types may be passed as actuals.
--
-- TEST DESCRIPTION:
--      The generic package declares a formal tagged private type (this can
--      be considered the parent "mixin" class). This type is extended in
--      the generic to provide support for stacks of items of any nonlimited
--      tagged type. Stacks are modeled as singly linked lists, with the list
--      nodes being objects of the extended type.
--
--      A generic testing procedure pushes items onto a stack, and pops them
--      back off, verifying the state of the stack at various points along the
--      way. The push and pop routines exercise functionality important to
--      tagged types, such as type conversion toward the root of the derivation
--      class and extension aggregates.
--
--      The formal tagged private type has an unknown discriminant part, and
--      is thus indefinite. This allows both definite and indefinite types
--      to be passed as actuals. For tagged types, definite implies
--      nondiscriminated, and indefinite implies discriminated (with known
--      or unknown discriminants). 
--
-- TEST FILES:
--      This test consists of the following files:
--
--         FC50A00.A
--      -> CC50A01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      21 Nov 95   SAIC    ACVC 2.0.1 fixes: Moved instantiations of
--                          BC50A01_0 to library level.
--      11 Aug 96   SAIC    ACVC 2.1: Updated prologue. Added pragma
--                          Elaborate to context clauses for CC50A01_2 & _3.
--
--!

with FC50A00;  -- Tagged (actual) type declarations.
generic        -- Generic stack abstraction.

   type Item (<>) is tagged private;            -- Formal tagged private type.
   TC_Default_Value : Item;                     -- Needed in View_Top (see
                                                -- below).
package CC50A01_0 is

   type Stack is private;

-- Note that because the actual type corresponding to Item may be
-- unconstrained, the functions of removing the top item from the stack and
-- returning the value of the top item of the stack have been separated into
-- Pop and View_Top, respectively. This is necessary because otherwise the
-- returned value would have to be an out parameter of Pop, which would
-- require the user (in the unconstrained case) to create an uninitialized
-- unconstrained object to serve as the actual, which is illegal.

   procedure Push     (I : in Item; S : in out Stack);
   procedure Pop      (S : in out Stack);
   function  View_Top (S : Stack) return Item;

   function Size_Of (S : Stack) return Natural;

private

   type Stack_Item;
   type Stack_Ptr is access Stack_Item;

   type Stack_Item is new Item with record      -- Extends formal type.
      Next : Stack_Ptr := null;
   end record;

   type Stack is record
      Top  : Stack_Ptr := null;
      Size : Natural   := 0;
   end record;

end CC50A01_0;
