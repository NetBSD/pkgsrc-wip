-- B3A2008.A
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
--      of A.  Check for cases where X'Access occurs in the private part of
--      an instance and X is declared in the instance itself.
--
--      Check for cases where X is:
--         (a) a view defined by an object declaration.
--         (b) a view defined by a component definition.
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
--      private part, where X is declared in the instance itself and the type
--      A of X'Access is a generic formal type.  The accessibility levels of
--      X depends on the nesting depth of the instance.  The test covers
--      cases where X is a view defined by an object declaration, a view
--      defined by a component definition, and a dereference of an
--      access-to-object value.
--
--      The test declares general access types in packages, subprograms, and
--      a nested task body. These types are passed as actuals to
--      instantiations, which are attempted at various nesting levels. The
--      test verifies that X'Access is illegal when X is declared at a nesting
--      level deeper than that of the type of X'Access, and legal otherwise.
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
--         |     - Nested task
--         |    |     *** testing here                       (Level = 2)
--         |    |
--         |    |  begin
--         |     - end task
--         |  begin
--          - end main subprogram
--
--
-- CHANGE HISTORY:
--      18 JAN 95   SAIC    Initial prerelease version.
--      29 Mar 95   SAIC    Modified test description; Declared a general
--                          access type in the generic and made this the
--                          type of Gen_Deref.
--      09 Feb 18   RLB     Added error location indicators to reflect common
--                          error reporting strategies.
--
--!

package B3A2008_0 is

   type Rec is record
      C : Boolean;
   end record;

   type Tagged_Rec is tagged record
      C : aliased Rec;
   end record;

   type New_Tagged_Rec is new Tagged_Rec with private;

   type Acc_NTag_L0 is access all New_Tagged_Rec;                 -- Level = 0.
   type Acc1_Rec_L0 is access all Rec;                            -- Level = 0.
   type Acc2_Rec_L0 is access all Rec;                            -- Level = 0.

private
   type New_Tagged_Rec is new Tagged_Rec with record
      I : Integer;
   end record;

end B3A2008_0;
