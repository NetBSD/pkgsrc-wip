-- C611001.A
--
--                             Grant of Unlimited Rights
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
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that pre- and post-conditions are checked before and after
--      each call.
--
-- TEST DESCRIPTION:
--      Define an abstract generic stack, and then a concrete bounded
--      descendant.  Instantiate the generic stack and its bounded
--      descendant.  Create a stack and try various combinations of
--      pushing and popping to verify that pre- and postconditions are being
--      appropriately enforced.
--
-- CHANGE HISTORY:
--      02 Oct 2013   T. Taft    ACVC 4.0.
--      23 Apr 2014   RLB        Fixed name of main subprogram, minor
--                               formatting issues. Added missing
--                               Assertion_Policy pragmas (initial mode is
--                               implementation-defined, we need to know).
--
--!

generic
   type Item is private;
package C611001_0 is

   pragma Assertion_Policy (Check);

   type Stack is interface;
   function Is_Empty (S : Stack) return Boolean is abstract;
   function Is_Full (S : Stack) return Boolean is abstract;

   procedure Push (S : in out Stack; I : in Item) is abstract
      with Pre'Class => not Is_Full (S),
           Post'Class => not Is_Empty (S);

   function Pop (S : in out Stack) return Item is abstract
      with Pre'Class => not Is_Empty (S),
           Post'Class => not Is_Full (S);

end C611001_0;
