-- C611A021.A
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
--     See C611A020.A.
--
-- TEST DESCRIPTION:
--     See C611A020.A.
--
-- TEST FILES:
--     This test consists of the following files:
--        C611A020.A
--     -> C611A021.A
--        C611A022.AM
--
-- CHANGE HISTORY:
--     21 Mar 16   JAC    Initial pre-release version.
--     24 Mar 16   RLB    Renamed so all test parts have the same name.
--     30 Mar 16   RLB    Split all of the specific type objectives into
--                        a single test.
--     31 Mar 16   RLB    Removed duplicative suffixes.
--
--!
package C611A020.Child is

   pragma Assertion_Policy (Check);

   type Triangle is new Object with private;

   overriding
   function  Distance              (T       : in      Triangle) return Float
    with Pre        => F611A00.TC_Log_Triangle_Distance_Specific_Pre_Called
                       and then Y_Coord   (T) <= 10.0,
         Post       => F611A00.TC_Log_Triangle_Distance_Specific_Post_Called
                       and then Not_Too_Near (T);

   function  Make_Triangle         (A, B, C  : in     Float)    return
    Triangle;

   procedure Get_Sides             (T        : in     Triangle;
                                    A, B, C  :    out Float);

   -- function X_Coord   inherited

   -- function Y_Coord   inherited

   -- Postcondition functions
   function Distance_Is_Positive   (T        : in     Triangle) return Boolean;

   function Not_Too_Far            (T        : in     Triangle) return Boolean;

   function Not_Too_Near           (T        : in     Triangle) return Boolean;

private

   type Triangle is new Object with record
      A, B, C : Float;
   end record;

end C611A020.Child;
