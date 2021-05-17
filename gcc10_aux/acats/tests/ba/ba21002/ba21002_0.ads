-- BA21002.A
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
--      Check that each of the following constructs is illegal within the body
--      of a library package to which a pragma Pure applies:
--
--         (a) A statement other than a null statement.
--         (b) A primary that is a name of an object, if the name is
--             not a static expression and does not statically denote a
--             discriminant of an enclosing type.
--         (c) A declaration of an object that is initialized by default
--             of a type that does not have preelaborable initialization.
--         (d) A declaration of a variable, with or without an initialization
--             expression, outside of a subprogram, generic subprogram, task
--             unit, or protected unit.
--         (e) A declaration of a named access-to-object type whose
--             Storage_Size is not zero outside of a subprogram, generic
--             subprogram, task unit, or protected unit.
--         (f) An extension aggregate with an ancestor subtype mark denoting
--             a subtype of a private extension.
--         (g) A declaration of a (constant) object which causes the
--             evaluation of a default expression that will call a
--             user-defined function.
--
--
--      Check that each of the following constructs is legal within the body of
--      a library package to which a pragma Pure applies:
--
--         (h) A call to a static function.
--         (i) A primary that is a name of an object, if the name is a static
--             expression.
--         (j) A declaration of a constant object outside of a subprogram,
--             generic subprogram, task unit, or protected unit.
--         (k) A declaration of a (constant) object which would cause the
--             evaluation of a default expression that will call a
--             user-defined function, except that the component with the
--             default expression is explicitly initialized.
--         (l) A declaration of a variable, with or without an initialization
--             expression, inside a subprogram.
--         (m) A declaration of a named access type inside a subprogram.
--         (n) A declaration of an anonymous access type.
--         (o) A declaration of a constant object of a descendant of a private
--             type (within the scope of the full view).
--
-- TEST DESCRIPTION:
--      Declare various supporting types, objects, and subprograms in a
--      preelaborated package declaration. Verify the legality of the
--      constructs (h)-(o) above in the corresponding package body. Verify
--      the illegality of the constructs (a)-(g) above in both the visible
--      and private part of a preelaborated package declaration which names
--      the first package in a with clause.
--
--
-- CHANGE HISTORY:
--      05 Apr 95   SAIC    Initial prerelease version.
--      22 Mar 07   RLB     Updated objective for Amendment 1 changes.
--
--!

package BA21002_0 is

   pragma Pure (BA21002_0);


   type My_Int is new Integer range 0 .. 100;
   function Func return My_Int;                     -- Non-static function.

   Three : constant My_Int :=  3;

   type Int_Array is array (1 .. 5) of My_Int;

   Arr   : constant Int_Array := (others => Three); -- Non-static.

   type RecWithDisc (D: My_Int) is record
      Table: Int_Array := (others => D);
   end record;

   type Tag is tagged record
      C : My_Int := Func;
      D : Integer;
   end record;

   type Pri_Ext is new Tag with private;

private

   type Pri_Ext is new Tag with record
      N: String (1 .. 5);
   end record;

end BA21002_0;
