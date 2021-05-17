-- C392D03.A
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
--      Check that, for an inherited dispatching operation that is overridden,
--      the body executed is the body of the overriding subprogram, even if
--      the overriding occurs in a private part.
--
--      Check for the case where the overriding operation is declared in a
--      separate (non-child) package from that declaring the parent type, and
--      the descendant type is a record extension.
--
--      Check for both dispatching and nondispatching calls.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package P is
--         type Root is tagged ...
--         procedure Op (A: Root);
--      end P;
--
--      with P;
--      package Q is
--         type Derived1 is new P.Root with record...
--         -- Implicit procedure Op (A: Derived1) declared here.
--         type Derived2 is new P.Root with private...
--         -- Implicit procedure Op (A: Derived2) declared here.
--         type New_Derived is new Derived1 with private...
--         -- Implicit procedure Op (A: New_Derived) declared here.
--      private
--         procedure Op (A: Derived1);  -- Overrides parent's Op.
--         type Derived2 is new P.Root with record...
--         procedure Op (A: Derived2);  -- Overrides parent's Op.
--         type New_Derived is new Derived1 with record...
--         ...
--      end Q;
--
--      Both type Derived1 and Derived2 inherit Op from the parent type Root. 
--      Type New_Derived inherits (inherited) Op from Derived1.  The inherited 
--      operation is implicitly declared immediately after the type extension.  
--      The inherited operation is overridden by an explicit declaration in 
--      the private part. Even though the overriding operation is private, 
--      calls to Op with an operand of tag Derived1, Derived2, or New_Derived
--      will execute the body of the overriding operation.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F392D00.A
--         C392D03.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with F392D00;
package C392D03_0 is

   type Aperture is (Eight, Sixteen);     

   type Auto_Focus is new F392D00.Remote_Camera with record
      -- ...
      FStop : Aperture;
   end record;

   -- Implicit procedure Focus (C     : in out Auto_Focus;
   --                           Depth : in     Depth_Of_Field) declared here.

   type Auto_Flashing is new F392D00.Remote_Camera with private;

   -- Implicit procedure Focus (C     : in out Auto_Flashing;
   --                           Depth : in     Depth_Of_Field) declared here.

   type Special_Focus is new Auto_Focus with private;

   -- Implicit procedure Focus (C     : in out Special_Focus;
   --                           Depth : in     Depth_Of_Field) declared here.

   -- ...Other operations.

private

   procedure Focus (C     : in out Auto_Focus;              -- Overrides
                    Depth : in     F392D00.Depth_Of_Field); -- parent's op.

   -- For the improved remote camera, focus is set automatically, so it is
   -- declared as a private operation.

   type Auto_Flashing is new F392D00.Remote_Camera with null record;

   procedure Focus (C     : in out Auto_Flashing;           -- Overrides
                    Depth : in     F392D00.Depth_Of_Field); -- parent's op.

   type Special_Focus is new Auto_Focus with null record;

end C392D03_0;
