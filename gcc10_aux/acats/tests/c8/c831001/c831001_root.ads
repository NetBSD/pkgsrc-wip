-- C831001.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
-- OBJECTIVE:
--     Check that overriding indicators can be given on subprogram
--     declarations, including null procedure and expression function
--     declarations, and that they have no effect on the operation of calls.
--
-- TEST DESCRIPTION:
--
--     We use the layout of test C392D01 and its associated foundation
--     to make this test. The original test is enhanced with query functions
--     and sinks to test expression functions and null procedures,
--     respectively. All of the primitive subprograms in the test are
--     decorated with overriding indicators. The use of indicators should
--     have no effect on the dynamic semantics of the test.
--
--     This test tries to use overriding indicators in a correct program
--     similarly to how they should be used in practice.
--
--     See test C392D01 for an explanation of the package and type structure
--     of this test.
--
-- CHANGE HISTORY:
--      15 Apr 2015   RLB   Created test, patterned after test C392D01.
--
--!

package C831001_Root is

   type Depth_Of_Field is range 5 .. 100;
   type Shutter_Speed  is (Tenth, Two_Fiftith, Four_Hundredth, Thousandth);
   type Exposure is (Normal, Bright, Dark);

   type Remote_Camera is tagged private;

   -- ...Other declarations.

   not overriding
   procedure Focus (C     : in out Remote_Camera;
                    Depth : in     Depth_Of_Field);

   not overriding
   function Get_Shutter_Speed (C : in Remote_Camera)
      return Shutter_Speed;

   not overriding
   function Get_Depth_of_Field (C : in Remote_Camera)
      return Depth_Of_Field;

   not overriding
   procedure Set_Exposure (C : in out Remote_Camera;
                           X : in     Exposure) is null;
      -- No exposure settings on basic camera.

   procedure Self_Test (C: in out Remote_Camera'Class);

   -- ...Other operations.

   not overriding
   procedure TC_Set_Params (C     : in out Remote_Camera;
                            Depth : in     Depth_Of_Field;
                            Speed : in     Shutter_Speed);
   -- In a real system, Focus would use its parameter to set the
   -- Depth_of_Field and Shutter_Speed; in this artifical setup, DOF and
   -- Shutter are used mainly to determine which bodies are called. As such,
   -- we provide this fake setter to actually set the (hidden) components.
   -- [Note: The original C392D01 test used visible components, which is
   -- unusual in actual practice.]

private

   type Remote_Camera is tagged record
      DOF    : Depth_Of_Field := 10;
      Shutter: Shutter_Speed  := Tenth;
   end record;

   not overriding
   procedure Set_Shutter_Speed (C     : in out Remote_Camera;
                                Speed : in     Shutter_Speed);

   -- For the basic remote camera, shutter speed might be set as a function of
   -- focus perhaps, thus it is declared as a private operation (usable
   -- only internally within the abstraction).

   -- Use expression functions to provide bodies to Getters:
   function Get_Shutter_Speed (C : in Remote_Camera)
      return Shutter_Speed is (C.Shutter);

   function Get_Depth_of_Field (C : in Remote_Camera)
      return Depth_Of_Field is (C.DOF);

end C831001_Root;
