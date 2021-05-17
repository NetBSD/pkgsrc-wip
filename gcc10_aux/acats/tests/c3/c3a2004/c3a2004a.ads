-- C3A2004.A
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
--      Check that the type of the prefix of X'Access is used to resolve
--      the expected type (both for X as an object and as a subprogram).
--
-- TEST DESCRIPTION:
--      Ada 2005 revised 3.10.2(2) to allow context to help resolve 'Access
--      attributes.
--
--      The revised 3.10.2(2) says that the expected type of an 'Access or
--      'Unchecked_Access attribute is a single access type whose designated
--      type covers the prefix. This rule change allows a variety of
--      interesting overloading scenarios.
--
--      This test is intended to ensure that expressions allowed by the new
--      rule are resolved and implemented properly. We've simplified the
--      types and subprogram names from a realistic case in order to make the
--      test easier to understand and debug if necessary. Even so, it is
--      relatively common that pairs of subprograms end up the with same
--      name (especially via use-visibility) but different profiles. In such
--      cases, resolution should be able to differentiate them.
--
-- CHANGE HISTORY:
--      31 May 00   RLB     Created initial test from now-legal cases from
--                          existing B-Test.
--      18 Dec 14   RLB     Updates for issuance.
--
--!

package C3A2004A is

   type Int_Ptr is access all Integer;
   type Char_Ptr is access all Character;
   type Float_Ptr is access all Float;

   function Zap (Val : Int_Ptr) return Float;
   function Zap (Val : Float_Ptr) return Float;

   type Access_Proc is access procedure (Flag : Boolean);
   type Access_Func is access function (Val : Integer) return Boolean;

   procedure Zip (Val : Access_Proc);
   procedure Zip (Val : Access_Func);

   function Zep (Val : Int_Ptr) return Float;
   function Zep (Val : Access_Func) return Float;

   function Zyp return Int_Ptr;
   function Zyp return Char_Ptr;

   Some_Value : aliased Integer;

   package Pkg is
      type My_Tagged is tagged record
         TC_Count : Natural := 0;
      end record;

      procedure My_Op (Val : access My_Tagged);
   end Pkg;

   package Pkg2 is
      type New_Tagged is new Pkg.My_Tagged with null record;

      procedure My_Op (Val : access New_Tagged); -- Overrides.
   end Pkg2;

   procedure Set_Flag (Flag : Boolean);
   procedure Set_Flag (Value : Integer);

   TC_Set_Flag_Count : Natural := 0;

end C3A2004A;
