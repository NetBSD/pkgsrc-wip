-- B854003.A
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
--     Check that a renames-as-body is illegal if:
--       A) it does not fully conform to the declaration that it completes;
--       B) the renamed entity is not subtype conformant with the declaration
--          that it completes if that declaration is frozen;
--       C) the renamed entity has convention Intrinsic;
--       D) the renamed entity is abstract;
--
-- CHANGE HISTORY:
--     06 Sep 2018 RLB Created test.
--
package B854003A is
   -- Entities to rename:

   -- For case B:
   ONE : Integer := 1;
   subtype Dyn_Positive is Integer range One .. Integer'Last;
   type New_Positive is range 1 .. Integer'Last;

   procedure Munge_1 (Val : in out Integer);

   procedure Munge_2 (Val : in out Natural);

   procedure Munge_3 (Val : in out Dyn_Positive);

   procedure Munge_4 (Val : in Integer);

   procedure Munge_5 (Val : in out New_Positive);

   procedure Munge_6 (Val : in out Positive; Foo : in Boolean := True);

   function Double_1 (Val : in Integer) return Integer;

   function Double_2 (Val : in Integer) return Natural;

   function Double_3 (Val : in Integer) return Dyn_Positive;


   -- For case D:

   type T is abstract tagged null record;

   procedure Proc (Obj : in out T) is abstract;

   function Func (Obj : in T) return Boolean is abstract;

   function Count (Obj : in T) return Natural;

   procedure Sink (Obj : in T);

end B854003A;
