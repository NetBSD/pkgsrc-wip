-- B3A2007.A
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
--      an instance and X is declared in the instance itself.
--
--      Check for cases where X is:
--         (a) a view defined by an object declaration.
--         (b) a renaming of an aliased view.
--         (c) a view conversion of an aliased view.
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
--      If X is a view of an object defined by a renaming declaration, its
--      accessibility level is that of the renamed view.
--
--      If X is a view conversion, its accessibility level is the same as that
--      of its operand.
--
--      This test declares a generic package which utilizes X'Access in its
--      visible part, where X is declared in the instance itself and the type
--      A of X'Access is a generic formal type.  The accessibility level of
--      X depends on the nesting depth of the instance.  The tests covers
--      cases where the actual corresponding to X is a view defined by an
--      object declaration, a renaming of an aliased view, and a view
--      conversion of an aliased view.
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
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Apr 95   SAIC    Modified header commentary.
--      16 Nov 95   SAIC    ACVC 2.0.1. Fixed problem where declarations in the
--                          generic declaration violated the accessibility
--                          rule of 3.9.1(3).
--      09 Feb 18   RLB     Added error location indicators to reflect common
--                          error reporting strategies.
--
--!

package B3A2007_0 is

   type Tag_Desig is tagged record
      I : Integer;
   end record;

   type AT1_L0 is access all Tag_Desig;                           -- Level = 0.
   type AT2_L0 is access all Tag_Desig;                           -- Level = 0.
   type AT3_L0 is access all Tag_Desig;                           -- Level = 0.

end B3A2007_0;
