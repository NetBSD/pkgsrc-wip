-- B432001
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
--    Check rules related to the type of the ancestor expression or subtype
--    in an extension aggregate:
--       (A) the ancestor type cannot be unrelated to the type of the aggregate;
--       (B) the type of the aggregate cannot be derived from the type of
--           the ancestor through one or more private extensions;
--       (C) the type of the ancestor cannot be untagged;
--       (D) the ancestor subtype cannot be classwide;
--       (E) the ancestor expression cannot be dynamically tagged;
--       (F) the type of the ancestor cannot be the same as or derived from
--           the type of the aggregate;
--       (G) the type of the aggregate or the components given cannot be used
--           to resolve the ancestor expression.
--    Also, check that the type of an extension aggregate cannot be a
--    tagged record type or a private extension. (H)
--
-- CHANGE HISTORY:
--    25 Apr 2007   RLB   Created test from test donated by RR Software, Inc.
--!

package B432001_Root is

   type Base is tagged record
      A : Integer := 11;
      C : Character := 'C';
   end record;
   function New_One return Base;
   function Factory return Base'Class;

   type Unrelated is tagged record
      A : Integer := 12;
      B : Boolean := False;
      C : Character := 'D';
   end record;

   package Nested is
      function Wild return Base;
      function Wild return Natural;

      function Loaded return Base;
      function Loaded return Unrelated;

      function Val return Integer;
   end Nested;

end B432001_Root;
