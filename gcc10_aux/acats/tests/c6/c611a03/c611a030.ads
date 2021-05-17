-- C611A030.A
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
--    Check that the class-wide precondition of a dispatching call is that
--    associated with the denoted subprogram, even if the body of a descendant
--    operation is invoked.
--
--    For a nonabstract tagged type T and a primitive subprogram S of T and
--    that has a class-wide precondition expression E, check that for a call of
--    S that is statically bound to type T, calls to primitive operations of T
--    within E invoke the bodies appropriate for T, even if the tag of the
--    controlling parameter object is not T.
--
--    For a nonabstract tagged type T and a primitive subprogram S of T and
--    that has a class-wide precondition expression E, check that for a
--    dynamically tagged dispatching call of S, calls to primitive operations
--    of T within E invoke the bodies appropriate for the controlling tag, even
--    if it is not T.
--
--    For a nonabstract tagged type T and a primitive subprogram S of T and
--    that has a class-wide postcondition expression E, check that for a call
--    of S that is statically bound to type T, calls to primitive operations
--    of T within E invoke the bodies appropriate for T, even if the tag of the
--    controlling parameter object is not T.
--
--    For a nonabstract tagged type T and a primitive subprogram S of T and
--    that has a class-wide postcondition expression E, check that for a
--    dynamically tagged dispatching call of S, calls to primitive operations
--    of T within E invoke the bodies appropriate for the controlling tag, even
--    if it is not T.
--
--    For a dispatching call, check that the class-wide postcondition evaluated
--    is that of the actual body invoked.
--
--    Check that if multiple enabled class-wide postconditions apply to a
--    subprogram S, check that they are all evaluated if they all evaluate to
--    True.
--
--    Check that if a subprogram S has multiple applicable class-wide
--    preconditions, that all such expressions evaluate to False before
--    Assertion_Error is raised.
--
--    Check that an enabled class-wide postcondition of a subprogram S is
--    evaluated after completing the subprogram body but before continuing
--    execution after the call of S, and that Assertion_Error is raised if any
--    such expression evaluates to False.
--
--    Check that an enabled class-wide precondition of a subprogram S is
--    evaluated after evaluating the parameters of a call on S and before S is
--    called, and that Assertion_Error is raised if all such expressions
--    evaluate to False.
--
-- TEST DESCRIPTION:
--    Loosely derived from adding pre- and postconditions to the examples in
--    Chapter 14 of Programming in Ada 2012.  Object is the root type from
--    which shape types are derived. Triangle is the only shape type in
--    this teest.
--
--    We test only class-wide preconditions and postconditions in this test;
--    in normal use, the programmer will use all class-wide contracts or
--    all specific contracts. Mixing them on a single subprogram is
--    unusual and the ACATS is supposed to concentrate on typical usage.
--
-- TEST FILES:
--    This test consists of the following files:
--      -> C611A030.A
--         C611A031.A
--         C611A032.AM
--
-- CHANGE HISTORY:
--    21 Mar 16   JAC     Initial pre-release version.
--    24 Mar 16   RLB     Renamed so all test parts have same first 7
--                        characters.
--    31 Mar 16   RLB     Split all of the class-wide type objectives into
--                        a single test.
--!
with F611A00;

package C611A030 is

   pragma Assertion_Policy (Check);

   type Object is tagged private;

   function  Distance             (O : in     Object) return Float
    with Pre'Class  => F611A00.TC_Log_Object_Distance_Pre_Class_Called
                       and then X_Coord (O) >= 0.0,
         Post'Class => F611A00.TC_Log_Object_Distance_Post_Class_Called
                       and then Distance_Is_Positive (O);

   procedure Move                   (O : in out Object'Class;
                                     X : in     Float;
                                     Y : in     Float);

   function  X_Coord                (O : in     Object) return Float;

   function  Y_Coord                (O : in     Object) return Float;

   -- Postcondition functions
   function  Distance_Is_Positive   (O : in     Object) return Boolean;

   function  Not_Too_Far            (O : in     Object) return Boolean;

   function  Not_Too_Near           (O : in     Object) return Boolean;

private

   type Object is tagged record
      X_Coord : Float := 0.0;
      Y_Coord : Float := 0.0;
   end record;

end C611A030;
