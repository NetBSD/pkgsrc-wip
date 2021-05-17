-- C954A01.A
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
--      Check that if a task requeued without abort on a protected entry queue
--      is aborted, the abort is deferred until the entry call completes,
--      after which the task becomes completed.
--
-- TEST DESCRIPTION:
--      Declare a protected type which simulates a printer device driver
--      (foundation code).
--
--      Declare a task which simulates a printer server for multiple printers.
--
--      For the protected type, declare an entry with a barrier that is set
--      false by a protected procedure (which simulates starting a print job
--      on the printer), and is set true by a second protected procedure (which
--      simulates a handler called when the printer interrupts, indicating
--      that printing is done).
--
--      For the task, declare an entry whose corresponding accept statement
--      contains a call to first protected procedure of the protected type
--      (which sets the barrier of the protected entry to false), followed by
--      a requeue with abort to the protected entry. Declare a second entry
--      which does nothing.
--
--      Declare a "requesting" task which calls the printer server task entry
--      (and thus executes the requeue). Attempt to abort the requesting
--      task. Verify that it is not aborted. Call the second protected
--      procedure of the protected type (the interrupt handler) and verify that
--      the protected entry completes for the requesting task. Verify that
--      the requesting task is then aborted.
--
-- TEST FILES:
--      This test depends on the following foundation code:
--
--         F954A00.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Oct 96   SAIC    Added pragma elaborate.
--
--!

package C954A01_0 is  -- Printer server abstraction.

   -- Simulate a system with multiple printers. The entry Print requests
   -- that data be printed on the next available printer. The entry call
   -- is accepted when a printer is available, and completes when printing
   -- is done.


   task Printer_Server is
      entry Print (File_Name : String);        -- Test the requeue statement.
      entry Verify_Results;                    -- Artifice for test purposes.
   end Printer_Server;

end C954A01_0;
