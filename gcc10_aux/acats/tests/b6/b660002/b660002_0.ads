-- B660002.A
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
--      Check that the "=" operator may be overloaded for non-limited types.
--      Check that explicit overloadings of "/=" may not have a Boolean
--      result.
--      Check that the result of an explicitly declared "=" operator may be
--      other than Boolean.  Check that an equality operator may rename a
--      function other than an equality operator.  Check that a declaration of
--      "=" whose result type is not Boolean does not implicitly declare a
--      "/=" operation that gives the complementary result.
--
-- TEST DESCRIPTION:
--      Define "/=" operations on non-limited types, returning Boolean
--      and other type results.  Define tri-state logic with "=" and
--      "/=" operators that return values NL_True, NL_False and Unknown.
--      Define an "=" operation on an array type, returning an array of
--      Booleans.
--
--      In another package, verify that errors are issued for an explicit
--      declaration of "/=" that returns a Boolean result.  Verify that errors
--      are issued for rename of "/= that returns a Boolean result.
--      Also verify that errors are issued for statements which attempt to
--      use an implicit operator "/=" that was from a declaration of "="
--      whose result type is not boolean.
--
--
-- CHANGE HISTORY:
--      06 Oct 95   SAIC    Initial prerelease version.
--      19 Nov 19   RLB     Added error location indicators.
--!

package B660002_0 is

   type NonLimited is range 1 .. 10;
   type Enumeration_Type is (Unknown, NL_True, NL_False);
   type Arr_Of_Booleans is array (1 .. 2) of Boolean;

   type Record_Type is
     record
        C : Integer;
     end record;

   type Access_To_Proc is access procedure (I1, I2 : in NonLimited);
   Do_Something_Access : Access_To_Proc;

   procedure Do_Something (I1, I2 : in NonLimited);

   function Not_Equal_AccToProc (I1 : NonLimited;
                                 I2 : Arr_Of_Booleans) return Access_To_Proc;

   function Not_Equal_Boolean   (I1, I2 : NonLimited) return Boolean;

   function Equal_Integer       (I1, I2 : NonLimited) return Integer;

end B660002_0;
