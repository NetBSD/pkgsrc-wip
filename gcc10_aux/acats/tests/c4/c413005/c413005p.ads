-- C413005.A
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
--     Check that a prefixed view is the name of a subprogram (with the first
--     parameter omitted from the profile) that can be renamed and passed as
--     a generic formal parameter.
--
-- CHANGE HISTORY:
--     27 Sep 2007 RLB Created test.
--     25 Oct 2007 RLB Corrected test errors.
--
--!
package C413005P is
   type TP is tagged record
      Data  : Integer := 999;
   end record;

   procedure Clear  (X : in out TP);
   procedure Set    (X : in out TP; Value : in Integer);
   function  Get    (X : TP) return Integer;
   function  Prod   (X : TP; Value : Integer) return Integer;

   procedure Class_Wide_Clear (X : in out TP'Class);
   procedure Class_Wide_Set   (X : in out TP'Class; Value : Integer);
   function  Class_Wide_Get   (X : TP'Class) return Integer;
   function  Class_Wide_Prod  (X : TP'Class; Value : Integer) return Integer;

end C413005P;
