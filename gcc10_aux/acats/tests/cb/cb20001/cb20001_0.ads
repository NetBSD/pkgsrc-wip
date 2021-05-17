-- CB20001.A
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
--      Check that exceptions can be handled in accept bodies, and that a
--      task object that has an exception handled in an accept body is still
--      viable for future use.
--
-- TEST DESCRIPTION:
--      Declare a task that has exception handlers within an accept
--      statement in the task body.  Declare a task object, and make entry
--      calls with data that will cause various exceptions to be raised
--      by the accept statement.  Ensure that the exceptions are: 
--         1) raised and handled locally in the accept body
--         2) raised in the accept body and handled/reraised to be handled 
--            by the task body
--         3) raised in the accept body and propagated to the calling 
--            procedure. 
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with Report;

package CB20001_0 is               

   Incorrect_Data,
   Location_Error,
   Off_Screen_Data           : exception;

   TC_Handled_In_Accept,
   TC_Reraised_In_Accept,
   TC_Handled_In_Task_Block,
   TC_Handled_In_Caller      : boolean := False;

   type Location_Type is range 0 .. 2000;

   task type Submarine_Type is
      entry Contact (Location : in Location_Type);
   end Submarine_Type;

   Current_Position : Location_Type := 0;

end CB20001_0;
