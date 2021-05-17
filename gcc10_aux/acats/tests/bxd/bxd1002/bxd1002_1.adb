-- BXD1002.A
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
--      Check that the pragma priority expression must be static when 
--      the pragma is located within the declarative_part of a 
--      subprogram_body.
--      Check that the expression in a Priority and Interrupt_Priority
--      pragma is required to be of type Integer.
--      Check that the pragma priority expression need not be static 
--      when the pragma is located within a task_definition or 
--      protected_definition.
--
-- TEST DESCRIPTION:
--      This test contains 3 compilation units, each containing both
--      legal and illegal pragma Priority or pragma Interrupt_Priority
--      declarations.  
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Real-Time Systems Annex.
--
--
-- CHANGE HISTORY:
--      04 AUG 95   SAIC    Initial version
--      08 MAY 96   SAIC    Incorporated Reviewer comments.
--
--!



with System;
with Report;
procedure BXD1002_1 is
  pragma Priority (Report.Ident_Int(System.Default_Priority));     -- ERROR:
                                  -- priority for a procedure must be static
begin 
  null; 
end BXD1002_1;
