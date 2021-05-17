-- C851002.A
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
--*
-- OBJECTIVE:
--     For an object renaming with an anonymous access type, check that the
--     name is resolved if there is only one interpretation with a correct
--     anonymous access type, even if other interpretations exist.
--
-- TEST DESCRIPTION:
--     The test defines a number of record types with identically named
--     components and various overloaded accessor functions. This models
--     all of these record types being placed into containers in the
--     same package. We then try to rename various components, and
--     verify that that succeeds.
--
--     The rule tested by this test was confirmed by AI05-0105-1, in
--     particular the case represented by type Not_Right_3. Note
--     that since it is impossible to qualify an anonymous access type,
--     renames like these are an important way to disambiguate overloaded
--     calls.
--
-- CHANGE HISTORY:
--     21 Jul 2008 RLB Created test.
--
package C851002_A is
   Aux : aliased Integer := 99;

   function Double (X : Float) return Float;

   type Expected is record -- This is the type we expect to resolve to.
      Comp1 : access Integer := Aux'Access;
      Comp2 : access function (X : Float) return Float := Double'Access;
      -- Other (differently named) components in a real type.
   end record;

   function Element1 (Cursor : Natural) return Expected;

   function Element2 (Cursor : Natural) return Expected;

   function Element3 (Cursor : Natural) return Expected;

   type Not_Right_1 is record -- This is a type with components with completely
                              -- different types.
      Comp1 : Float := 92.0;
      Comp2 : String(1..5) := "12345";
      -- Other (differently named) components in a real type.
   end record;

   function Element1 (Cursor : Natural) return Not_Right_1;

   type Not_Right_2 is record -- This is a type with components with access
			      -- types with the wrong designated type/profile.
      Comp1 : access Float;
      Comp2 : access function return Natural;
      -- Other (differently named) components in a real type.
   end record;

   function Element2 (Cursor : Natural) return Not_Right_2;

   type Int_Ptr is access all Integer;
   type Func_Ptr is access function (X : Float) return Float;

   type Not_Right_3 is record -- This is a type with components with named
			      -- access types with the correct characteristics.
      Comp1 : Int_Ptr := Aux'Access;
      Comp2 : Func_Ptr := Double'Access;
      -- Other (differently named) components in a real type.
   end record;

   function Element3 (Cursor : Natural) return Not_Right_3;

end C851002_A;
