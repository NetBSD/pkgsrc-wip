-- C392D01.A
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
--      Check that, for an implicitly declared dispatching operation that is
--      overridden, the body executed is the body for the overriding
--      subprogram, even if the overriding occurs in a private part.
--      Check that, for an implicitly declared dispatching operation that is
--      NOT overridden, the body executed is the body of the corresponding
--      subprogram of the parent type.
--
--      Check for the case where the overriding (and non-overriding) operations
--      are declared for a private extension (and its full type) in a public
--      child unit of the package declaring the ancestor type, and the ancestor
--      type is a tagged private type whose full view is itself a derived type.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package Parent is
--         type Root is tagged ...
--         procedure Vis_Op (P: Root);
--      private
--         procedure Pri_Op (P: Root);                     -- (A)
--      end Parent;
--
--      package Intermediate is
--         type Mid is tagged private;
--      private
--         type Mid is new Parent.Root with record ...
--         -- Implicit Vis_Op (P: Mid) declared here.
--
--         procedure Vis_Op (P: Mid);                      -- (B)
--      end Intermediate;
--
--      package Intermediate.Child is
--         type Derived is new Mid with private; 
--
--         procedure Pri_Op (P: Derived);                  -- (C)
--         ...
--
--      private
--         type Derived is new Mid with record...
--         -- Implicit Vis_Op (P: Derived) declared here.
--         ...
--      end Intermediate.Child;
--
--      Type Derived inherits Vis_Op from the parent type Mid. Note, however,
--      that it is implicitly declared in the private part (inherited
--      subprograms for a derived_type_definition -- in this case, the full
--      type -- are implicitly declared at the  earliest place within the
--      immediate scope of the type_declaration where the corresponding
--      declaration from the parent is visible).
--
--      Because Parent.Pri_Op is never visible within the immediate scope
--      of Mid, it is not implicitly declared for Mid. Thus, it is also not
--      implicitly declared for Derived. As a result, the version of Pri_Op
--      declared at (C) above does not override an inherited version of
--      Parent.Pri_Op and is totally unrelated to it.
--
--      Dispatching calls with tag Mid will execute (A) and (B). Dispatching 
--      calls with tag Derived from Parent will execute the bodies of (B) 
--      and (A).  Dispatching calls with tag Derived from Parent.Child
--      will execute the bodies of (B) and (C).  
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F392D00.A
--         C392D01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with F392D00;
package C392D01_0 is

   type Zoom_Camera is tagged private;

   procedure Self_Test (C : in out Zoom_Camera'Class);

   -- ...Additional operations.


   function TC_Correct_Result (C : Zoom_Camera;
                               D : F392D00.Depth_Of_Field;
                               S : F392D00.Shutter_Speed) return Boolean;

private

   type Magnification is (Low, Medium, High);

   type Zoom_Camera is new F392D00.Remote_Camera with record
      Mag : Magnification;
   end record;

   -- procedure Focus (C     : in out Zoom_Camera;               -- Implicitly
   --                  Depth : in     Depth_Of_Field)            -- declared
                                                                 -- here.

   procedure Focus (C     : in out Zoom_Camera;                -- Overrides
                    Depth : in     F392D00.Depth_Of_Field);    -- inherited op.

   -- For the remote zoom camera, perhaps the focusing algorithm is different
   -- in some way, so the original Focus operation is overridden here.

   -- Since the partial view is not an extension, the overriding operation
   -- must be declared after the full type. This version of Focus, although
   -- not visible for type Zoom_Camera from outside the package, can still be
   -- dispatched to.  


   -- Note: F392D00.Set_Shutter_Speed is inherited by Zoom_Camera from
   -- F392D00.Remote_Camera, but since the operation never becomes visible
   -- within the immediate scope of Zoom_Camera, it is never implicitly
   -- declared. 

end C392D01_0;
