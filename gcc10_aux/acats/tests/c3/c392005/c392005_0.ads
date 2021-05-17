-- C392005.A
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
--
--      Check for the case where the overriding operations are declared in a
--      public child unit of the package declaring the parent type, and the
--      descendant type is a private extension.
--
--      Check for both dispatching and nondispatching calls.
--
--
-- TEST DESCRIPTION:
--      Consider:
--
--      package Parent is
--         type Root is tagged ...
--         procedure Vis_Op (P: Root);
--      private
--         procedure Pri_Op (P: Root);
--      end Parent;
--
--      package Parent.Child is
--         type Derived is new Root with private;
--         -- Implicit Vis_Op (P: Derived) declared here.
--
--         procedure Pri_Op (P: Derived);                  -- (A)
--         ...
--      private
--         type Derived is new Root with record...
--         -- Implicit Pri_Op (P: Derived) declared here.

--         procedure Vis_Op (P: Derived);                  -- (B)
--         ...
--      end Parent.Child;
--
--      Type Derived inherits both Vis_Op and Pri_Op from the ancestor type
--      Root. Note, however, that Vis_Op is implicitly declared in the visible
--      part, whereas Pri_Op is implicitly declared in the private part
--      (inherited subprograms for a private extension are implicitly declared
--      after the private_extension_declaration if the corresponding
--      declaration from the ancestor is visible at that place; otherwise the
--      inherited subprogram is not declared for the private extension,
--      although it might be for the full type).
--
--      Even though Root's version of Pri_Op hasn't been implicitly declared
--      for Derived at the time Derived's version of Pri_Op has been
--      explicitly declared, the explicit Pri_Op still overrides the implicit
--      version. 
--      Also, even though the explicit Vis_Op for Derived is declared in the
--      private part it still overrides the implicit version declared in the
--      visible part. Calls with tag Derived will execute (A) and (B).
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      26 Nov 96   SAIC    Improved for ACVC 2.1
--
--!

package C392005_0 is

   type Remote_Camera is tagged private;

   type Depth_Of_Field is range 5 .. 100;  
   type Shutter_Speed  is (One, Two_Fifty, Four_Hundred, Thousand);
   type Aperture       is (Eight, Sixteen, Thirty_Two);     

   -- ...Other declarations.

   procedure Focus (Cam   : in out Remote_Camera;
                    Depth : in     Depth_Of_Field);

   procedure Self_Test (C: in out Remote_Camera'Class);

   -- ...Other operations.

   function TC_Get_Depth (C: Remote_Camera) return Depth_Of_Field;
   function TC_Get_Speed (C: Remote_Camera) return Shutter_Speed;

private

   type Remote_Camera is tagged record
      DOF    : Depth_Of_Field := 10;
      Shutter: Shutter_Speed  := One;
      FStop  : Aperture       := Eight;
   end record;

   procedure Set_Shutter_Speed (C     : in out Remote_Camera;
                                Speed : in     Shutter_Speed);

   -- For the basic remote camera, shutter speed might be set as a function of
   -- focus perhaps, thus it is declared as a private operation (usable
   -- only internally within the abstraction).

   function Set_Aperture (C : Remote_Camera) return Aperture;
                               
end C392005_0;
