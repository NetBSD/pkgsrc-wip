-- C392D02.A
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
--      Check that a primitive procedure declared in a private part is not
--      overridden by a procedure explicitly declared at a place where the
--      primitive procedure in question is not visible.
--
--      Check for the case where the non-overriding operation is declared in a
--      separate (non-child) package from that declaring the parent type, and
--      the descendant type is a record extension.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package P is
--         type Root is tagged ...
--      private
--         procedure Pri_Op (A: Root);
--      end P;
--
--      with P;
--      package Q is
--         type Derived is new P.Root with record...
--         procedure Pri_Op (A: Derived);  -- Does NOT override parent's Op.
--         ...
--      end Q;
--
--      Type Derived inherits Pri_Op from the parent type Root. However,
--      because P.Pri_Op is never visible within the immediate scope of
--      Derived, it is not implicitly declared for Derived. As a result,
--      the explicit Q.Pri_Op does not override P.Pri_Op and is totally
--      unrelated to it.
--
--      Dispatching calls to P.Pri_Op with operands of tag Derived will
--      not dispatch to Q.Pri_Op; the body executed will be that of P.Pri_Op.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F392D00.A
--         C392D02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with F392D00;
package C392D02_0 is

   type Aperture is (Eight, Sixteen);     

   type Auto_Speed is new F392D00.Remote_Camera with record
      -- ...
      FStop : Aperture;
   end record;


   procedure Set_Shutter_Speed (C     : in out Auto_Speed;     
                                Speed : in     F392D00.Shutter_Speed); 
                                                   -- Does NOT override.

   -- This version of Set_Shutter_Speed does NOT override the operation
   -- inherited from the parent, because the inherited operation is never
   -- visible (and thus, is never implicitly declared) within the immediate
   -- scope of type Auto_Speed.

   procedure Self_Test (C : in out Auto_Speed'Class);

   -- ...Other operations.

end C392D02_0;
