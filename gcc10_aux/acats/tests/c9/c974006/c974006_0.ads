-- C974006.A
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
--      Check that the sequence of statements of the triggering alternative
--      of an asynchronous select statement is executed if the triggering
--      statement is a protected entry call, and the entry is accepted
--      immediately. Check that the corresponding entry body is executed
--      before the sequence of statements of the triggering alternative.
--      Check that the abortable part is not executed.
--
-- TEST DESCRIPTION:
--      Declare a main procedure containing an asynchronous select with a
--      protected entry call as triggering statement. Declare a protected
--      procedure which sets the protected entry's barrier true. Force the
--      entry call to be accepted immediately by calling this protected
--      procedure prior to the asynchronous select. Since the entry call
--      is accepted immediately, the abortable part should never start. When
--      entry call completes, the sequence of statements of the triggering
--      alternative should execute.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!


package C974006_0 is  -- Automated teller machine abstraction.


   -- Flag for testing purposes:

   Entry_Body_Executed : Boolean := False;


   type Key_Enum is (None, Cancel, Deposit, Withdraw);

   type Card_Number_Type is private;
   type Card_PIN_Type    is private;
   type ATM_Card_Type    is private;


   Transaction_Canceled : exception;


   protected type ATM_Keyboard_Protected is
      entry Cancel_Pressed;
      procedure Read_Key;
   private
      Last_Key_Pressed : Key_Enum := None;
   end ATM_Keyboard_Protected;


   procedure Read_Card (Card : in out ATM_Card_Type);

   procedure Validate_Card (Card : in ATM_Card_Type);

   procedure Perform_Transaction (Card : in ATM_Card_Type);

private

   type Card_Number_Type is range   1 .. 9999;
   type Card_PIN_Type    is range 100 ..  999;

   type ATM_Card_Type is record
      Number : Card_Number_Type;
      PIN    : Card_PIN_Type;
   end record;

end C974006_0;
