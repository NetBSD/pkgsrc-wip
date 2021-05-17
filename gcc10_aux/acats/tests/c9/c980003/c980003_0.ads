-- C980003.A
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
-- TEST OBJECTIVE:
--      Check that aborts are deferred during the execution of an 
--      Initialize procedure (as the last step of the default 
--      initialization of a controlled object), during the execution 
--      of a Finalize procedure (as part of the finalization of a 
--      controlled object), and during an assignment operation to an
--      object with a controlled part.
--
-- TEST DESCRIPTION:
--      A controlled type is created with Initialize, Adjust, and 
--      Finalize operations.  These operations note in a protected
--      object when the operation starts and completes.  This change
--      in state of the protected object will open the barrier for
--      the entry in the protected object.
--      The test contains declarations of objects of the controlled
--      type.  An asynchronous select is used to attempt to abort
--      the operations on the controlled type.  The asynchronous select
--      makes use of the state change to the protected object to 
--      trigger the abort.
--
--
-- CHANGE HISTORY:
--      11 Jan 96   SAIC    Initial Release for 2.1
--       5 May 96   SAIC    Incorporated Reviewer comments.
--      10 Oct 96   SAIC    Addressed issue where assignment statement
--                          can be 2 assignment operations.
--
--!

with Ada.Finalization;
package C980003_0 is
    Verbose : constant Boolean := False;

    -- the following flag is set true whenever the
    -- Initialize operation is called.
    Init_Occurred : Boolean;

    type Is_Controlled is new Ada.Finalization.Controlled with
         record
             Id : Integer;
         end record;

     procedure Initialize (Object : in out Is_Controlled);
     procedure Finalize   (Object : in out Is_Controlled);
     procedure Adjust     (Object : in out Is_Controlled);

     type States is (Unknown,
                     Start_Init,   Finished_Init, 
                     Start_Adjust, Finished_Adjust,
                     Start_Final,  Finished_Final);

     protected State_Manager is
        procedure Reset;
        procedure Set (New_State : States);
        function Current return States;
        entry Wait_For_Change;
     private
        Current_State : States := Unknown;
        Changed : Boolean := False;
     end State_Manager;

end C980003_0;
