-- C3A0018.A
--
--                            Grant of Unlimited Rights
--
--    AdaCore holds unlimited rights in the software and documentation
--    contained herein. Unlimited rights are the same as those granted
--    by the U.S. Government for older parts of the Ada Conformity
--    Assessment Test Suite, and are defined in DFAR 252.227-7013(a)(19).
--    By making this public release, AdaCore intends to confer upon all
--    recipients unlimited rights equal to those held by the Ada Conformity
--    Assessment Authority. These rights include rights to use, duplicate,
--    release or disclose the released technical data and computer software
--    in whole or in part, in any manner and for any purpose whatsoever,
--    and to have or permit others to do so.
--
--                                   DISCLAIMER
--
--    ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--    DISCLOSED ARE AS IS. ADACORE MAKES NO EXPRESS OR IMPLIED WARRANTY AS
--    TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE SOFTWARE,
--    DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE OR
--    DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--    PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                    Notice
--
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--    This test is based on one submitted by AdaCore; AdaCore retains the
--    copyright on the test.
--*
--  OBJECTIVE:
--     Check that an anonymous access type can be an access-to-protected
--     subprogram type, and that it can be called with an appropriate profile.
--
--  CHANGE HISTORY:
--     15 Apr 2004 JM  Initial Version.
--     03 Apr 2008 RLB Converted to ACATS test, adding test cases.
--     18 Jul 2008 RLB Corrected test errors.
--!


package C3A0018P is

   protected PO is
      function Double (X : Float) return Float;
      function Times_Factor (X : Float) return Float;
      procedure Set_Factor (X : Float);
   private
      Factor : Float := 3.0;
   end PO;

   function Evaluate
     (Fn : access protected function (X: Float) return Float;
      X  : Float)
     return Float;

   procedure Pass_It
     (Fn : access protected function (X: Float)
      return Float := PO.Double'Access);

   function Return_It
      return access protected function (X: Float) return Float;
      -- Return an access to PO.Times_Factor.

end C3A0018P;
