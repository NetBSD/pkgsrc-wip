-- CXC7001.A
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
--      In the package Ada.Task_Identification, check that Current_Task
--      returns the Task_ID of the calling task; Abort_Task aborts the task
--      corresponding to the Task_ID parameter; Is_Terminated and
--      Is_Callable return the corresponding attribute values for the task
--      corresponding to the Task_ID parameter.
--
--      Check that an object of type Task_ID is default initialized to
--      Null_Task_ID.
--
--      Check that the attribute T'Identity returns a Task_ID that
--      identifies task T and the C'Caller returns a Task_ID that
--      identifies the caller of entry E.
--
-- TEST DESCRIPTION:
--      This test declares several task types and task objects in various
--      contexts, and uses them to verify the operation of the package
--      Ada.Task_Identification.  This test declares objects of the type
--      Task_ID in various contexts and checks that each is correctly
--      initialized to the Null_Task_Id value.  The interfaces in
--      Ada.Task_Identification are checked for appropriate action when
--      called with values equal to Null_Task_Id.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      23 Nov 98   RLB     Revised TC_Match_States to work on a
--                          multiprocessor implementation.
--      29 Mar 07   RLB     Corrected TC_Match_States.
--
--!

--------------------------------------------------------------------------

with Ada.Task_Identification;
package CXC7001_0 is

  task type Task_Type is
    entry My_ID (ID   : out Ada.Task_Identification.Task_ID);
    entry Check_Caller(ID: in Ada.Task_Identification.Task_ID);
    entry Shutdown;
  end Task_Type;

  type Task_Ref is access Task_Type;

end CXC7001_0;
