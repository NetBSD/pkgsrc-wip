-- F650A00.A
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
--
-- FOUNDATION DESCRIPTION:
--      This package declares three limited tagged types for use in limited
--      return tests, Alert, Special_Alert, and Practice_Alert.
--      It models (in miniature) an application situation in which an
--      abstraction is defined with an abstract root type and several
--      concrete extensions.
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0.
--      29 Mar 08   RLB     Created from existing F393B00 foundation.
--      17 Jul 08   RLB     Removed illegal component reference.
--
--!

package F650A00 is
   type Alert is abstract tagged limited private;  -- Abstract type
                                               -- See procedure Handle below

   procedure Handle (A : in out Alert) is abstract;
                                               -- Abstract procedure,
                                               -- explicitly declared

   procedure Set_Alert_Time (A : in out Alert; Time : in Duration);

   function Alert_Time (A : in Alert) return Duration;

private
   type Alert is abstract tagged limited record
      Time : Duration := 0.0;
   end record;
end F650A00;
