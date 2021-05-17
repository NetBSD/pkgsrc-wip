-- CXD6001.A
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
--      Check that an aborted construct is completed immediately
--      at the first point that is outside the execution of an
--      abort-deferred operation.
--
-- TEST DESCRIPTION:
--      This test relies upon the ability to unblock an interrupt
--      priority task that in turn aborts a normal priority task.
--      This is accomplished by having the interrupt priority task
--      waiting for a Set_True on a Suspension_Object.
--      The normal priority tasks that are aborted note their state
--      in global variables.  These variables are named starting
--      with Check_Point_.  This state allows us to determine if
--      the abort occurred at the right time.  In particular, one
--      of the state variables is set while in an abort-deferred
--      region that should be executing when the abort occurs and
--      is used to check that abort deferral is properly performed.
--      The setting of the final state variable occurs outside
--      the abort-deferred area and should not occur since aborts
--      are supposed to be immediate.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Real-Time Systems Annex.
--      This test is not applicable to multi-processor systems.
--
--
-- CHANGE HISTORY:
--      25 SEP 95   SAIC    Initial version for 2.1
--      22 FEB 96   SAIC    Incorporated Reviewer Comments
--                          New ImpDef
--      01 DEC 97   EDS     Added "with Impdef;"  Added delay statements to
--                          block the main subprogram's execution and thus
--                          free the Victim tasks to complete their execution
--                          (to the point where they are aborted) before the
--                          main subprgram continues and calls procedure
--                          Check_Results to check various state variables.
--      25 NOV 98   RLB     Added multi-processor Not_Applicable check
--                          and comments.
--!

with System;
with Report;
with Ada.Task_Identification;
with Ada.Synchronous_Task_Control;
package CXD6001_1 is
  Verbose : constant Boolean := False;

  package TID renames Ada.Task_Identification;
  package STC renames Ada.Synchronous_Task_Control;

  -- Killer_Task takes a task_id of a task to abort.  Once it receives
  -- the task_id it will suspend on Kill_Now awaiting notification
  -- that it is time for it to do its dastardly deed.  Once it has
  -- aborted its prey it will go back to waiting for another mission.
  Kill_Now : STC.Suspension_Object;
  task Killer_Task is
    -- high enough to preempt any non-interrupt level item
    pragma Interrupt_Priority (System.Interrupt_Priority'First);

    entry Task_To_Abort (T : in TID.Task_ID);
  end Killer_Task;
end CXD6001_1;
