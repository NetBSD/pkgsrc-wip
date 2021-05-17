-- B611015.A
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
-- OBJECTIVE:
--     Check that the prefix of an Old attribute cannot have a limited type.
--
-- CHANGE HISTORY:
--     16 Nov 2016   RLB   Created test.
--
--!
package B611015A is

   type Priv is private;

   function Is_OK (P : Priv) return Boolean;

   type Lim_Priv is limited private;

   function Is_OK (P : Lim_Priv) return Boolean;

   type PTag is tagged private;

   function Is_OK (P : PTag) return Boolean;

   type LTag is tagged limited private;

   function Is_OK (P : LTag) return Boolean;

   protected type Prot is
      function Is_OK return Boolean;
      entry E (B : in out Boolean);
   private
      C : Boolean := False;
   end Prot;

   task type Tsk is
      entry E (N : in out Natural);
   end Tsk;

   type Rec (D : Boolean) is record
      C : Character;
      case D is
          when True => N : Natural;
          when False => null;
      end case;
   end record;

   type Lim_Rec is limited record
      C : Character;
      N : Natural;
   end record;

   type LR_Rec is limited record
      R : Lim_Rec;
      N : Natural;
   end record;

   type LP_Rec is limited record
      R : Lim_Priv;
      C : Character;
   end record;

   type LP_Arr is array (1..10) of Lim_Priv;

private

   type Priv is new Natural;

   type Lim_Priv is record
      F : Float;
      P : Positive;
   end record;

   type PTag is tagged record
      P : Positive;
   end record;

   type LTag is tagged limited record
      N : Natural;
   end record;

end B611015A;
