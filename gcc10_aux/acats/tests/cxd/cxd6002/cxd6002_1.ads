-- CXD6002.A
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
--      Check that in an asynchronous transfer of control an
--      aborted construct is completed immediately
--      at the first point that is outside the execution of an 
--      abort-deferred operation.
--
-- TEST DESCRIPTION:
--      This test uses asynchronous transfer of control as the
--      aborting mechanism and checks that the abort is performed
--      at the first point outside an abort-deferred operation.
--      This test relies upon the ability to unblock an interrupt
--      priority task that in turn aborts a normal priority task.
--      This is accomplished by having the interrupt priority task
--      blocked on a protected record entry which is released
--      at the point where an abort is desired.
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
--      26 SEP 95   SAIC    Initial version
--      22 FEB 96   SAIC    ImpDef Changes; Shared -> Atomic
--      02 DEC 97   EDS     For a non-uni-processor system, add call to
--                          CXD6002_1.Done to terminate the CXD6002_1.Weapon
--                          task.
--!

package CXD6002_1 is
  procedure Simple_Case;
  procedure In_Rendezvous;
  procedure In_Protected;
  procedure In_Protected_Requeue;
  procedure Done;
end CXD6002_1;
