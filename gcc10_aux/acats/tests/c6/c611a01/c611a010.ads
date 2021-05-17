-- C611A01.A
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
--
-- OBJECTIVE:
--
--    Check that if all applicable class-wide preconditions evaluated to False,
--    Assertion_Error is raised even if an enabled specific precondition of
--    S evaluates to True.
--
--    Check that an enabled specific precondition of a subprogram S raises
--    Assertion_Error if it evaluates to False, even if a class-wide
--    precondition for S evaluated to True.
--
--    Check that if any applicable class-wide postcondition evaluates to False,
--    Assertion_Error is raised even if an enabled specific postcondition of S
--    evaluates to True.
--
--    Check that if an enabled specific postcondition valuates to False,
--    Assertion_Error is raised even if all enabled applicable class-wide
--    postconditions of S evaluate to True.
--
-- TEST DESCRIPTION:
--    Loosely derived from adding pre- and postconditions to the examples in
--    Chapter 14 of Programming in Ada 2012.  Object is the root type from
--    which shape types are derived (we only declare Triangle here).
--
--    We use class-wide preconditions and postconditions on type Object,
--    and then use specific preconditions and postconditions on type Triangle
--    derived from Object. This is the most likely way that mixed class-wide
--    and specific contracts would appear in a program, especially as
--    a specific precondition is needed to strengthen an existing precondition
--    (class-wide preconditions can only be weakened). (Best practice would
--    never mix class-wide and specific contracts on a single subprogram.)
--
--    Since this is based on another submitted test, there are some ordering
--    checks that are not strictly needed for this test.
--
-- CHANGE HISTORY:
--    29 Mar 16   RLB    Created test from a version of the test submitted
--                       by JAC (and used to create C611A02 and other tests).
--    31 Mar 16   RLB    Removed duplicative suffixes.
--
--!
with F611A00;

package C611A010 is

   pragma Assertion_Policy (Check);

   type Object is tagged private;

   function  Distance             (O : in     Object) return Float
    with Pre'Class  => F611A00.TC_Log_Object_Distance_Pre_Class_Called
                       and then X_Coord (O) >= 0.0,
         Post'Class => F611A00.TC_Log_Object_Distance_Post_Class_Called
                       and then Not_Too_Near (O);

   procedure Move                   (O : in out Object'Class;
                                     X : in     Float;
                                     Y : in     Float);

   function  X_Coord                (O : in     Object) return Float;

   function  Y_Coord                (O : in     Object) return Float;


   -- Postcondition functions
   function  Not_Too_Far            (O : in     Object) return Boolean;

   function  Not_Too_Near           (O : in     Object) return Boolean;

private

   type Object is tagged record
      X_Coord : Float := 0.0;
      Y_Coord : Float := 0.0;
   end record;

end C611A010;
