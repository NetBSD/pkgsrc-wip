-- C3A2002.A
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
--      Check for the case where X denotes a view that is a dereference of an
--      access parameter, or a rename thereof.
--      
--      Check for cases where the actual corresponding to X is:
--         (a) An allocator.
--         (b) An expression of a named access type.
--         (c) Obj'Access.
--      
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep nesting level than the
--      general access type A -- X must "live" as long as A. Nesting
--      levels are the run-time nestings of masters: block statements;
--      subprogram, task, and entry bodies; and accept statements. Packages
--      are invisible to accessibility rules.
--
--      This test declares subprograms with access parameters, within which
--      'Access is attempted on a dereference of the access parameter, and
--      assigned to an access object whose type A is declared at some nesting
--      level. The test verifies that Program_Error is raised if the actual
--      corresponding to the access parameter is:
--
--         (1) an allocator, and the accessibility level of the execution
--             of the called subprogram is deeper than that of the access
--             type A. 
--
--         (2) an expression of a named access type, and the accessibility
--             level of the named access type is deeper than that of the
--             access type A. 
--
--         (3) a reference to the Access attribute (e.g., X'Access), and
--             the accessibility level of X is deeper than that of the
--             access type A. 
--
--      Note that the static nesting level of the actual corresponding to the
--      access parameter can be deeper than that of the type A -- it is
--      the run-time nesting that matters for accessibility rules. Consider
--      the case where the access type A is declared within the called
--      subprogram. The accessibility check will never fail, even if the
--      actual happens to have a deeper static nesting level:
--
--         procedure P (X: access T) is
--            type A is access all T;   -- Static level = 2, e.g.
--            Acc : A := X.all'Access;  -- Check should never fail.
--         begin null; end;
--         . . .
--         declare
--            Actual : aliased T;       -- Static level = 3, e.g.
--         begin
--            P (Actual'Access);
--         end;
--
--         For the execution of P, the accessibility level of type A will
--         always be deeper than that of Actual, so there is no danger of a
--         dangling reference arising from the assignment to Acc. Thus,
--         X.all'Access is safe, even though the static nesting level of
--         Actual is deeper than that of A.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C3A2002_0 is

   type Desig is array (1 .. 10) of Integer;

   X0 : aliased Desig;                                            -- Level = 0.

   type Acc_L0 is access all Desig;                               -- Level = 0.
   A0 : Acc_L0;

   type Result_Kind is (OK, P_E, O_E);

   procedure A_Is_Level_0 (X: access Desig; R : out Result_Kind);
   procedure Never_Fails  (X: access Desig; R : out Result_Kind);

end C3A2002_0;
