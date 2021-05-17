-- B452002.A
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
-- OBJECTIVES:
--     [A] Check that a universal access equality operator does not resolve
--     if neither operand is a specific anonymous access type.
--
--     [B] Check that a universal access equality operator is illegal if one
--     of the operands is access-to-object and the other is
--     access-to-subprogram.
--
--     [C] Check that a universal access equality operator is illegal when both
--     operands have access-to-object types and the designated subtypes of
--     the operands are different kinds of types.
--
--     [D] Check that a universal access equality operator is illegal when both
--     operands have access-to-object types and the designated subtypes of
--     the operands are elementary and do not statically match.
--
--     [E] Check that a universal access equality operator is illegal when both
--     operands have access-to-object types and the designated subtypes of the
--     operands are array types and do not statically match.
--
--     [F] Check that a universal access equality operator is illegal when both
--     operands have access-to-object types and the designated types of the
--     operands are record types and one does not cover the other.
--
--     [G] Check that a universal access equality operator is illegal when both
--     operands have access-to-subprogram types and the designated profiles of
--     the operand types are not subtype conformant.
--
-- TEST DESCRIPTION:
--     We declare a bunch-o-types to serve as designated types (along with a
--     anonymous access components), then declare a few procedures with a lot
--     of anonymous access parameters and a few SOAATs. We then try comparing
--     various objects.
--
--     The test is verifying that RM 4.5.2(9.5/2), 4.5.2(9.6/2), and
--     4.5.2(9.7/2) are correctly implemented.
--
--     Note: When a named access type is involved, we use Standard."=" to
--     ensure that the universal access operator is being used. We don't
--     want the compiler to be confused by the predefined "=" for the named
--     access type.
--
-- CHANGE HISTORY:
--     29 Mar 2019  RLB  Created new test.

package B452002_0 is
   -- Some named access types to use in equality:
   Var : Natural := 0;
   subtype Dyn is Integer range Var .. Integer'Last;

   type Pool_Acc is access Positive;

   type General_Acc is access all Positive;
   subtype NNGen_Acc is not null General_Acc;

   type Func_Acc is access function return Positive;

   type My_Array is array (Positive range <>) of Natural;

   subtype Short_Array is My_Array (1 .. 4);

   subtype Long_Array is My_Array (1 .. 20);

   subtype Dyn_Array is My_Array (1 .. Var + 4);

   type Arr_Acc is access My_Array;

   type Root is tagged null record;

   type Child is new Root with null record;

   type AChild_Acc is access all Child'Class;

   type Grandchild is new Child with null record;

   type Sibling is new Root with null record;

   type Disc_Rec (D : Natural) is record
      C : Natural;
   end record;

   subtype Four_Rec is Disc_Rec(4);

   subtype Six_Rec is Disc_Rec(6);

   type Rec_Comp is record
       Comp_Pos  : access Positive;
       Comp_Nat  : access Natural;
       Comp_Dyn  : access Dyn;
       Comp_Flt  : access Float;
       Comp_SArr : access Short_Array;
       Comp_DArr : access Dyn_Array;
       Comp_Func : access function return Natural;
       Comp_Proc : access procedure (N : in Natural);
       Comp_NNAcc: access NNGen_Acc;
       Comp_Child: access Child'Class;
       Comp_Sibl : access Sibling;
       Comp_GAcc : access General_Acc;
       Comp_4Rec : access Four_Rec;
       Comp_DRec : access Disc_Rec;
   end record;

end B452002_0;
