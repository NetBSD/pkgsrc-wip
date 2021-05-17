-- B3A2012.A
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
--      Check that, for X'Access of a general access type A, the accessibility
--      level of the view denoted by X must not be statically deeper than that
--      of A.  Check for cases where X'Access occurs in the visible part of
--      an instance and X is passed as an actual during instantiation.
--
--      Check for cases where X is:
--         (a) a view defined by an object declaration.
--         (b) a view denoted by a component definition.
--         (c) a dereference of an access-to-object value.
--
--
-- TEST DESCRIPTION:
--      In order to satisfy accessibility requirements, the designated
--      object X must be at the same or a less deep nesting level than the
--      general access type A -- X must "live" as long as A. Nesting
--      levels are the run-time nestings of masters: block statements;
--      subprogram, task, and entry bodies; and accept statements. Packages
--      are invisible to accessibility rules.
--
--      If X is an object declared by an object declaration, its accessibility
--      level is that of the innermost enclosing master execution.
--
--      If X is a view of an object denoted by a dereference of an access
--      value, its accessibility level is that of the associated access type.
--
--      The accessibility level of the anonymous type of an access discriminant
--      is that of the containing object.
--
--      This test declares a generic package which utilizes X'Access in its
--      visible part, where X is a generic formal object and the type A of
--      X'Access is a generic formal type. The accessibility levels of X and
--      A in an instance are those of the corresponding actual parameters.
--      The test covers cases where the actual corresponding to X is a view
--      defined by an object declaration, a view denoted by a component, and
--      a dereference of an access-to-object value.
--
--      The test declares general access types and aliased objects in
--      packages, subprograms and nested blocks.  These types and objects are
--      passed as actuals to instantiations, which are attempted at various
--      nesting levels. The test verifies that X'Access is illegal when X is
--      declared at a nesting level deeper than that of the type of X'Access,
--      and legal otherwise.
--
--      The nesting structure is as follows:
--
--          - Library-level package
--         |                                                 (Level = 0)
--          - end package
--
--          - Main subprogram
--         |      *** testing here                           (Level = 1)
--         |
--         |     - Nested block statement
--         |    |     *** testing here                       (Level = 2)
--         |    |
--         |    |     - Doubly-nested block statement
--         |    |    |     *** testing here                  (Level = 3)
--         |    |    |
--         |    |    |  begin
--         |    |     - end doubly-nested block statement
--         |    |  begin
--         |     - end nested block statement
--         |
--          - end main subprogram
--
--
-- CHANGE HISTORY:
--      26 JAN 95   SAIC    Initial prerelease version.
--      24 MAY 95   SAIC    Changed test code to reflect the test objectives.
--                          Changed access-to-variable types to
--                          access-to-constant types.
--      09 Feb 18   RLB     Added error location indicators to reflect common
--                          error reporting strategies.
--
--!

package B3A2012_0 is

   type Tag_Desig is tagged record
      I : Integer;
   end record;

   type Rec_With_Comp is record
      C : aliased Tag_Desig;        -- Aliased component.
   end record;

   type Acc_to_Tag_L0 is access constant Tag_Desig;           -- Level = 0.
   TObj_L0 : aliased Tag_Desig;                               -- Level = 0.
   Comp_L0 : Rec_With_Comp;                                   -- Level = 0.
   Derf_L0 : Acc_to_Tag_L0;                                   -- Level = 0.

end B3A2012_0;
