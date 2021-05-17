-- C940014.A
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
--      Check that as part of the finalization of a protected object
--      each call remaining on an entry queue of the objet is removed
--      from its queue and Program_Error is raised at the place of
--      the corresponding entry_call_statement.
--
-- TEST DESCRIPTION:
--      The example in 9.4(20a-20f);6.0 demonstrates how to cause a
--      protected object to finalize while tasks are still waiting
--      on its entry queues.  The first part of this test mirrors
--      that example.  The second part of the test expands upon
--      the example code to add an object with finalization code
--      to the protected object.  The finalization code should be
--      executed after Program_Error is raised in the callers left
--      on the entry queues.
--
--
-- CHANGE HISTORY:
--      08 Jan 96   SAIC    Initial Release for 2.1
--      10 Jul 96   SAIC    Incorporated Reviewer comments to fix race 
--                          condition.
--
--!


with Ada.Finalization;
package C940014_0 is
    Verbose : constant Boolean := False;
    Finalization_Occurred : Boolean := False;

    type Has_Finalization is new Ada.Finalization.Limited_Controlled with
          record
             Placeholder : Integer;
          end record;
    procedure Finalize (Object : in out Has_Finalization);
end C940014_0;
