-- CB20004.A
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
--      Check that exceptions propagate correctly from objects of 
--      protected types. Check propagation from protected entry bodies.
--
-- TEST DESCRIPTION:
--      Declare a package with a protected type, including entries and private
--      data, simulating a bounded buffer abstraction.  In the main procedure,
--      perform entry calls on an object of the protected type that raises
--      exceptions.
--      Ensure that the exceptions are: 
--         1) raised and handled locally in the entry body
--         2) raised in the entry body and handled/reraised to be handled 
--            by the caller.
--         3) raised in the entry body and propagated directly to the calling 
--            procedure. 
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CB20004_0 is               -- Package Buffer.

   Max_Buffer_Size       : constant := 2;

   Handled_In_Body,
   Propagated_To_Caller,
   Handled_In_Caller     : Boolean := False;

   Data_Over_5,
   Data_Degradation      : exception;

   type Data_Item is range 0 .. 100;

   type Item_Array_Type is array (1 .. Max_Buffer_Size) of Data_Item;

   protected type Bounded_Buffer is
      entry Put (Item : in     Data_Item);
      entry Get (Item :    out Data_Item);
   private
      Item_Array : Item_Array_Type;
      I, J       : Integer range 1 .. Max_Buffer_Size := 1;
      Count      : Integer range 0 .. Max_Buffer_Size := 0;
   end Bounded_Buffer;

end CB20004_0;
