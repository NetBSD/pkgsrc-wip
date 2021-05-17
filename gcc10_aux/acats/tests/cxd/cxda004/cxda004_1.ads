-- CXDA004.A
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
--      Check that Set_False and Set_True can be called from an
--      interrupt handler.
--      Check that a Suspension_Object is a by reference type.
--      Check that Current_State returns the current state of
--      a suspension object.
--      Check that Program_Error is raised upon calling Suspend_Until_True
--      if another task is waiting on that suspension object.
--
-- TEST DESCRIPTION: 
--      A task is blocked waiting on a suspension object to become true.
--      The task is unblocked by an interrupt handler.
--      The check that a Suspension_Object is a by reference type
--      is accomplished by passing a global SO to a procedure where
--      the procedure manipulates the parameter and checks that the
--      global variable is changed.
--
-- SPECIAL REQUIREMENTS
--      This test requires that an interrupt be generated while the
--      test is running.  The method is implementation dependent.
--      See ImpDef.Annex_C for further details about the
--      requirements for this interrupt.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to 
--          implementations supporting the Real-Time Systems Annex, and
--          having a non-reserved interrupt available that can be 
--          triggered while the test is running.
--
--
-- CHANGE HISTORY:
--      28 Sep 95   SAIC    ACVC 2.1
--
--!

with Ada.Synchronous_Task_Control;
package CXDA004_1 is
    Verbose : constant Boolean := False;

    SO : Ada.Synchronous_Task_Control.Suspension_Object;
    Interrupt_Count : Integer := 0;
    pragma Volatile (Interrupt_Count);
    procedure Make_Body_Legal;
end CXDA004_1;
