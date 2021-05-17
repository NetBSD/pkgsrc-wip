-- CXC7004.A
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
--      Check that Ada.Task_Identification.Is_Callable returns the correct
--      results for the environment task. (The requirements of this test are
--      confirmed by AI-00206).
--      Check that Ada.Task_Identification.Current_Task and the Caller
--      attribute can return the environment task.
--
-- TEST DESCRIPTION:
--      This test attempts to mimic the form of a pre-packaged Ada subprogram
--      library implemented with an active task. While processing, the task
--      periodically checks to see if the main subprogram has completed.
--      If it has, the task terminates itself.
--
--      This structure is necessary for a task which cannot sit on a terminate
--      alternative and which should be terminated without user intervention.
--      To make a pre-packaged library bullet-proof, a termination subprogram
--      cannot be used as the only for of termination (a user might forget to
--      call the subprogram, or an exception may propagate beyond the call).
--      Unfortunately, finalization cannot be used for this purpose, since
--      tasks must terminate before objects are finalized.
--
--      At least one commercial subprogram library uses this structure.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Systems Programming Annex.
--
--
-- CHANGE HISTORY:
--      14 Sep 99   RLB     Created test.
--
--!

--------------------------------------------------------------------------

package CXC7004_0 is

    -- This package represents the pre-packaged subprogram library.

    procedure Operate_On_It (A : in out Integer);
        -- An operation requiring the use of the (internal) task.

end CXC7004_0;
