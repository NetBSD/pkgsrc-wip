-- B641001.A
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
--      Check that the actual parameter corresponding to a formal parameter of
--      mode in out or out must denote a variable; in particular, that it may
--      not be a dereference of an access-to-constant value. Check for the
--      cases where the value is of a generic formal access-to-constant type,
--      or of a non-formal access-to-constant type declared within a formal
--      package.
--
-- TEST DESCRIPTION:
--      A dereference of an access-to-constant value is a constant.
--
--      This test checks that implicit and explicit dereferences of a value of
--      a generic formal access-to-constant type may not be passed as actuals
--      to formal parameters of mode out or in out. Three scenarios are tested:
--
--         (1) The designated type is non-private (thus, the components of
--             the designated type are known to the generic), and the formal
--             access-to-constant type is part of the generic in which the
--             parameter passing is attempted.
--
--         (2) The designated type is private (the components of the designated
--             type are not known to the generic), and the formal access-to-
--             constant type is declared in a formal package.
--
--         (3) The designated type is non-private, and the (non-formal)
--             access-to-constant type is declared within a formal package.
--
--      As appropriate for access-to-constant objects in each of the above
--      scenarios, attempts are made to pass the access object (legal), a
--      dereference denoting the designated object (illegal), and a dereference
--      denoting a component of the designated object (illegal). The objects
--      passed result from both direct references to and dereferences of
--      stand-alone objects (allocated both dynamically and statically),
--      generic formal objects, and formal (subprogram) parameters.
--
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      14 Mar 14   RLB     Eliminated cases illegal by 6.4.1(6.15/3).
--
--!

package B641001_0 is

   type Component is range 0 .. 10;

   type Designated is record
      Item : Component := 0;
   end record;

   type Acc_Constant is access constant Designated;

   Rec : aliased Designated;

end B641001_0;
