-- C611A041.A
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
--     -> C611A041.A
--        C611A042.A
--        C611A043.AM
--
-- CHANGE HISTORY:
--      24 Dec 16   JAC     Initial pre-release version.
--
--!
package C611A040.Child is

   pragma Assertion_Policy (Check);

   type Object is new Point with private;

   overriding
   function  Distance              (O : in     Object) return Float;

   procedure Move                  (O : in out Object'Class;
                                    X : in     Float;
                                    Y : in     Float);

   overriding
   function  X_Coord               (O : in     Object) return Float;

   overriding
   function  Y_Coord               (O : in     Object) return Float;

   -- Postcondition functions
   function Distance_Is_Positive   (O : in     Object) return Boolean;

   function Not_Too_Far            (O : in     Object) return Boolean;

   function Not_Too_Near           (O : in     Object) return Boolean;

private

   type Object is new Point with record
      X_Coord : Float := 0.0;
      Y_Coord : Float := 0.0;
   end record;

end C611A040.Child;
