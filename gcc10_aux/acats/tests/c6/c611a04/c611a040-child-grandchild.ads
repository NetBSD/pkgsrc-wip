-- C611A042.A
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
--     See C611A040.A.
--
-- TEST DESCRIPTION:
--     See C611A040.A.
--
-- TEST FILES:
--     This test consists of the following files:
--        C611A040.A
--        C611A041.A
--     -> C611A042.A
--        C611A043.AM
--
-- CHANGE HISTORY:
--      12 Dec 16   JAC     Initial pre-release version.
--
--!
package C611A040.Child.Grandchild is

   pragma Assertion_Policy (Check);

   type Triangle is new Object with private;

   overriding
   function  Distance              (T       : in     Triangle) return Float
    with Pre'Class  => F611A00.TC_Log_Triangle_Distance_Pre_Class_Called
                       and then Y_Coord   (T) >= 0.0,
         Post'Class => F611A00.TC_Log_Triangle_Distance_Post_Class_Called
                       and then Not_Too_Far (T);

   function  Area                  (T       : in     Triangle) return Float
    with Post'Class => Area_Is_Positive (Area'Result);

   function  Make_Triangle         (A, B, C : in     Float)    return
    Triangle;

   procedure Get_Sides             (T       : in     Triangle;
                                    A, B, C :    out Float);

   overriding
   function  X_Coord               (T       : in     Triangle) return Float;

   overriding
   function  Y_Coord               (T       : in     Triangle) return Float;

   -- Postcondition functions
   function Distance_Is_Positive   (T       : in     Triangle) return Boolean;

   function Not_Too_Far            (T       : in     Triangle) return Boolean;

   function Not_Too_Near           (T       : in     Triangle) return Boolean;

   function Area_Is_Positive       (Area    : in     Float)    return Boolean;

private

   type Triangle is new Object with record
      A, B, C : Float;
   end record;

end C611A040.Child.Grandchild;
