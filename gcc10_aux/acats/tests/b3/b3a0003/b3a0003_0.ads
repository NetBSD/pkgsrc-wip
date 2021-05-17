-- B3A0003.A
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
--      Check that a designated object cannot be updated through a value of
--      an access-to-constant type. Check for the cases where the access-to-
--      constant type is a generic formal type, or a non-formal type declared
--      within a formal package.
--
-- TEST DESCRIPTION:
--      An object is considered to be updated if the object or any of its
--      components, or an enclosing object, is the target of an assignment.
--
--      This test checks that the designated object of a value of a generic
--      formal access-to-constant type may not be updated through the value.
--      Three scenarios are tested:
--
--         (1) The designated type is non-private (thus, the components of
--             the designated type are known to the generic), and the formal
--             access-to-constant type is part of the generic in which the
--             assignment is attempted.
--
--         (2) The designated type is private (the components of the designated
--             type are not known to the generic), and the formal access-to-
--             constant type is declared in a formal package.
--
--         (3) The designated type is non-private, and the (non-formal)
--             access-to-constant type is declared within a formal package.
--
--      As appropriate for access-to-constant objects in each of the above
--      scenarios, attempts are made to assign to the access object (legal),
--      the designated object (illegal), and a component of the designated
--      object (illegal). The targets of assignment are both direct references
--      to and dereferences of stand-alone objects, generic formal objects,
--      and formal (subprogram) parameters.
--      
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package B3A0003_0 is

   type Component is range 0 .. 10;

   type Designated is record
      Item : Component := 0;
   end record;

   type Acc_Constant is access constant Designated;

   Rec : aliased Designated;

end B3A0003_0;
