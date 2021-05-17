-- CXD1007.A
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
--      Check that a priority pragma has no effect if it occurs in the 
--      declarative_part of a subprogram_body other than the main 
--      subprogram.
--      Check that the priority specified for the main subprogram sets 
--      the priority of the environment task.
--      Check that dynamic values can be specified in the interrupt_priority
--      and priority pragmas.
--
-- TEST DESCRIPTION:
--      This test declares two subprograms, both of which contain pragma
--      priority declarations.  A check is made that only the real main
--      procedure's priority is used for the environment task.
--      Note that the check is performed in the non-main subprogram
--      so the priority expected is not the priority specified in the
--      pragma priority declaration in that subprogram.
--      Tasks are declared where the priorities for the tasks are dynamic
--      values.  Each task's priority is checked.
--      The package Ada.Dynamic_Priorities is used to query the priority 
--      of the tasks (including the environment task).
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Real-Time Systems Annex.
--
--
-- CHANGE HISTORY:
--      18 SEP 95   SAIC    Initial version
--
--!

-- not the main procedure
with System;
with Report;
with Ada.Dynamic_Priorities;
procedure CXD1007_1 is
  Verbose : constant Boolean := False;
  This_Procedure_Priority : constant System.Priority 
        := System.Default_Priority - 2;
  Real_Main_Priority : constant System.Priority
        := System.Default_Priority + 3;
  pragma Priority (This_Procedure_Priority);
  P : System.Any_Priority;
begin
  P := Ada.Dynamic_Priorities.Get_Priority;
  if P = This_Procedure_Priority then
    Report.Failed ("pragma priority for non-main procedure" &
                   " was not ignored");
  elsif P /= Real_Main_Priority then
    Report.Failed ("expected main priority to be" &
           System.Any_Priority'Image (Real_Main_Priority) &
           " but the priority was" &
           System.Any_Priority'Image (P) );
  else
    if Verbose then
      Report.Comment ("main priority is" &
                      System.Any_Priority'Image (P));
    end if;
  end if;
end CXD1007_1;
