-- C974011.A
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
--      of an asynchronous select statement is not executed if the triggering
--      statement is a task entry call and the entry is not accepted
--      before the abortable part completes. 
--      Check that the call queued on the entry is cancelled
--
-- TEST DESCRIPTION:
--      Declare a main procedure containing an asynchronous select with a task
--      entry call as triggering statement. Force the entry call to be
--      queued by having the task call a procedure, prior to the corresponding
--      accept statement, which simulates (with a delay) a routine waiting
--      for user input
--       
--      Once the call is known to be queued, complete the abortable part. 
--      Check that the rendezvous (and thus the trigger) does not complete. 
--      Then clear the barrier and check that the entry has been cancelled
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      28 Nov 95   SAIC    Eliminated shared global variable for ACVC 2.0.1
--
--!

with ImpDef;
--
package C974011_0 is  -- Automated teller machine abstraction.



   type Key_Enum is (None, Cancel, Deposit, Withdraw);

   protected Key_PO is
      procedure Set (K : Key_Enum);
      function  Value return Key_Enum;
   private
      Current : Key_Enum := None;
   end Key_PO;


   -- Flags for testing purposes
   TC_Abortable_Part_Completed : Boolean := False;
   TC_Rendezvous_Entered       : Boolean := False;
   TC_Delay_Time : constant duration := ImpDef.Switch_To_New_Task;


   Count  : Integer := 1234;  -- Global to defeat optimization.


   type Card_Number_Type is private;
   type Card_PIN_Type    is private;
   type ATM_Card_Type    is private;


   Transaction_Canceled : exception;


   task type ATM_Keyboard_Task is
      entry Cancel_Pressed;
   end ATM_Keyboard_Task;

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

end C974011_0;
