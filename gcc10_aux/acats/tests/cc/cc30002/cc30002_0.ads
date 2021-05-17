-- CC30002.A
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
--      Check that an explicit declaration in the private part of an instance
--      does not override an implicit declaration in the instance, unless the
--	corresponding explicit declaration in the generic overrides a
--      corresponding implicit declaration in the generic. Check for primitive
--      subprograms of tagged types.
--
-- TEST DESCRIPTION:
--      Consider the following:
--
--         type Ancestor is tagged null record;
--         procedure R (X: in Ancestor);
--
--         generic
--            type Formal is new Ancestor with private;
--         package G is
--            type T is new Formal with null record;
--            -- Implicit procedure R (X: in T);
--            procedure P (X: in T);  -- (1)
--         private
--            procedure Q (X: in T);  -- (2)
--            procedure R (X: in T);  -- (3) Overrides implicit R in generic.
--         end G;
--
--         type Actual is new Ancestor with null record;
--         procedure P (X: in Actual);
--         procedure Q (X: in Actual);
--         procedure R (X: in Actual);
--
--         package Instance is new G (Formal => Actual);
--
--      In the instance, the copy of P at (1) overrides Actual's P, since it
--      is declared in the visible part of the instance. The copy of Q at (2)
--      does not override anything. The copy of R at (3) overrides Actual's
--      R, even though it is declared in the private part, because within
--      the generic the explicit declaration of R overrides an implicit
--      declaration.
--
--      Thus, for calls involving a parameter with tag T:
--         - Calls to P will execute the body declared for T.
--         - Calls to Q from within Instance will execute the body declared
--           for T.
--         - Calls to Q from outside Instance will execute the body declared
--           for Actual.
--         - Calls to R will execute the body declared for T.
--
--      Verify this behavior for both dispatching and nondispatching calls to
--      Q and R. 
--
--
-- CHANGE HISTORY:
--      24 Feb 95   SAIC    Initial prerelease version.
--
--!

package CC30002_0 is

   type TC_Body_Kind is (Body_Of_Ancestor, Body_In_Instance,
                         Body_Of_Actual,   Initial_Value);

   type Camera is tagged record
      -- ... Camera components.
      TC_Focus_Called   : TC_Body_Kind := Initial_Value;
      TC_Shutter_Called : TC_Body_Kind := Initial_Value;
   end record;

   procedure Focus (C: in out Camera);

   -- ...Other operations.

end CC30002_0;
