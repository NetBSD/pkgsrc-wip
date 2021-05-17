-- B392005.A
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
--      Check that a subprogram may not be a dispatching operation for two
--      different tagged types (in a child unit package).
--
-- TEST DESCRIPTION:
--      Declare a package which defines two tagged types, two type
--      extensions, and two private tagged types.  Declare a child package
--      with two type extensions of the tagged type in the parent package.
--      Declare another two tagged types and two private extensions in the
--      child package. Declare two tagged types in the private part of the
--      child package. Verify that compiler generates errors for all
--      subprograms declarations that are primitive operations for more than
--      one tagged type.
--
-- PASS/FAIL CRITERIA:
--     This test contains several lines marked POSSIBLE ERROR: [Setnn].
--     For each value of n, the implementation must detect one or more of
--     these possible errors. For instance, an error must be detected on
--     at least one of the lines labeled POSSIBLE ERROR: [Set1] for an
--     implementation to pass.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      23 Dec 94   SAIC    Changed parameter to avoid freezing rule conflict.
--                          Minor spelling corrections.
--      14 Feb 97   PWB.CTA Deleted declaration of illegal function
--                          Child_Primitive_Of_Both_Func2.
--      07 Feb 18   RLB     Added error location indicators and "Possible
--                          Error" to reflect common error reporting
--                          strategies.
--!

package B392005_0 is

   type Parent_Tagged_T is tagged null record;
   type Parent_Tagged_R is tagged null record;
   type New_Parent_Tagged_T1 is new Parent_Tagged_T with null record;
   type New_Parent_Tagged_T2 is new Parent_Tagged_T with null record;
   type Parent_Tagged_Private is tagged private;
   type Parent_Private_Tagged is private;

private
   type Parent_Tagged_Private is tagged
     record
        Field_1 : String (1..10);
     end record;

   type Parent_Private_Tagged is tagged null record;

end B392005_0;
