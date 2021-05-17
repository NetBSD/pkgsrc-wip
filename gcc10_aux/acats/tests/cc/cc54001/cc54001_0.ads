-- CC54001.A
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
--      Check that a general access-to-constant type may be passed as an
--      actual to a generic formal access-to-constant type.
--
-- TEST DESCRIPTION:
--      The generic implements a stack of access objects as an array. The
--      designated type of the formal access type is itself a formal private
--      type declared in the same generic formal part.
--      
--      The generic is instantiated with an unconstrained subtype of String,
--      which results in a stack which can accommodate strings of varying
--      lengths (ragged array). Furthermore, the access objects to be pushed
--      onto the stack are created both statically and dynamically, utilizing
--      allocators and the 'Access attribute.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate to context clause
--                          preceding CC54001_1.
--
--!

generic
   Size : in Positive;
   type Element_Type (<>) is private;
   type Element_Ptr       is access constant Element_Type;
package CC54001_0 is -- Generic stack of pointers.

   type Stack_Type is private;

   procedure Push (Stack    : in out Stack_Type;
                   Elem_Ptr : in     Element_Ptr);

   procedure Pop  (Stack    : in out Stack_Type;
                   Elem_Ptr :    out Element_Ptr);

   -- ... Other operations.

private

   subtype Index is Positive range 1 .. (Size + 1);
   type Stack_Type is array (Index) of Element_Ptr;  -- Last element unused.

   Top : Index := 1;

end CC54001_0;
