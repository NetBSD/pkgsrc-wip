-- C761007.A
--
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
--      Check that if a finalize procedure invoked by a transfer of control
--      due to selection of a terminate alternative attempts to propagate an
--      exception, the exception is ignored, but any other finalizations due
--      to be performed are performed.
--
--
-- TEST DESCRIPTION:
--      This test declares a nested controlled data type, and embeds an object
--      of that type within a protected type.  Objects of the protected type
--      are created and destroyed, and the actions of the embedded controlled
--      object are checked.  The container controlled type causes an exception
--      as the last part of it's finalization operation.
--
--      This test utilizes several tasks to accomplish the objective.  The
--      tasks contain delays to ensure that the expected order of processing
--      is indeed accomplished.
--
--      Subtest 1:
--        local task object runs to normal completion
--
--      Subtest 2:
--        local task aborts a nested task to cause finalization
--
--      Subtest 3: 
--        local task sleeps long enough to allow procedure started
--        asynchronously to go into infinite loop.  Procedure is then aborted
--        via ATC, causing finalization of objects.
--
--      Subtest 4:
--        local task object takes terminate alternative, causing finalization
--
--
-- CHANGE HISTORY:
--      06 JUN 95   SAIC    Initial version
--      05 APR 96   SAIC    Documentation changes
--      03 MAR 97   PWB.CTA Allowed two finalization orders for ATC test
--      02 DEC 97   EDS     Remove duplicate characters from check string.
--!

---------------------------------------------------------------- C761007_0

with Ada.Finalization;
package C761007_0 is

  type Internal is new Ada.Finalization.Controlled
    with record
      Effect : Character;
    end record;

  procedure Finalize( I: in out Internal );

  Side_Effect : String(1..80);  -- way bigger than needed
  Side_Effect_Finger : Natural := 0;

end C761007_0;
