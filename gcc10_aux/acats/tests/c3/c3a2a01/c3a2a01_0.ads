-- C3A2A01.A
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
--      Check that, for X'Access of a general access type A, Program_Error is
--      raised if the accessibility level of X is deeper than that of A.
--      Check for cases where X'Access occurs in an instance body, and A
--      is passed as an actual during instantiation.
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep nesting level than the
--      general access type A -- X must "live" as long as A. Nesting
--      levels are the run-time nestings of masters: block statements;
--      subprogram, task, and entry bodies; and accept statements. Packages
--      are invisible to accessibility rules.
--
--      This test declares three generic units, each of which has a formal
--      general access type:
--
--         (1) A generic package, in which X is declared in the specification,
--             and X'Access occurs within the declarative part of the body.
--
--         (2) A generic package, in which X is a formal in out object of a
--             tagged formal derived type, and X'Access occurs in the sequence
--             of statements of a nested subprogram.
--
--         (3) A generic procedure, in which X is a dereference of an access
--             parameter, and X'Access occurs in the sequence of statements.
--
--      The test verifies the following:
--
--         For (1), Program_Error is raised upon instantiation if the generic
--         package is instantiated at a deeper level than that of the general
--         access type passed as an actual. The exception is propagated to the
--         innermost enclosing master.
--
--         For (2), Program_Error is raised when the nested subprogram is
--         called if the object passed as an actual during instantiation of
--         the generic package has an accessibility level deeper than that of
--         the general access type passed as an actual. The exception is
--         handled within the nested subprogram. Also, check that
--         Program_Error is not raised if the level of the actual access type
--         is deeper than that of the actual object.
--
--         For (3), Program_Error is raised when the instance subprogram is
--         called if the object pointed to by the actual corresponding to
--         the access parameter has an accessibility level deeper than that of
--         the general access type passed as an actual during instantiation.
--         The exception is handled within the instance subprogram. Also,
--         check that Program_Error is not raised if the level of the actual
--         access type is deeper than that of the actual corresponding to the
--         access parameter.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F3A2A00.A
--      -> C3A2A01.A
--
--
-- CHANGE HISTORY:
--      12 May 95   SAIC    Initial prerelease version.
--      10 Jul 95   SAIC    Modified code to avoid dead variable optimization.
--
--!

with F3A2A00;
generic
   type FD  is new F3A2A00.Array_Type;
   type FAF is access all FD;
package C3A2A01_0 is
   X : aliased FD;

   procedure Dummy;  -- Needed to allow package body.
end C3A2A01_0;
