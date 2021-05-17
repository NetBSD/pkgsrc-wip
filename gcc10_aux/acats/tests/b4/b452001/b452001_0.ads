-- B452001.A
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
--     Check that if the tested expression has a limited type and the
--     membership has any choice expressions, the tested type must have
--     a visible equality operator.

--
-- TEST DESCRIPTION:
--     We declare various limited types and constructors, and then try using
--     them in memberships.
--
--     This test is important to ensure that a membership using a choice
--     expression does not provide a backdoor way to use equality when none
--     is defined.
--
-- CHANGE HISTORY:
--     19 Dec 2018  RLB  Created new test.

package B452001_0 is

   type Lim_Never_Equal is limited private;

   function Create (N : in Natural) return Lim_Never_Equal;

   ZERO_1 : constant Lim_Never_Equal;

   TWO_1  : constant Lim_Never_Equal;

   --

   type Lim_Hidden_Predef_Equal is limited private;

   function Create (N : in Natural) return Lim_Hidden_Predef_Equal;

   ZERO_2 : constant Lim_Hidden_Predef_Equal;

   TWO_2  : constant Lim_Hidden_Predef_Equal;

   --

   type Lim_Hidden_UDef_Equal is limited private;

   function Create (N : in Natural) return Lim_Hidden_UDef_Equal;

   ZERO_3 : constant Lim_Hidden_UDef_Equal;

   TWO_3  : constant Lim_Hidden_UDef_Equal;

   --

   type Lim_w_Equal is limited private;

   function Create (N : in Natural) return Lim_w_Equal;

   function "=" (Left, Right : in Lim_w_Equal) return Boolean;

   ZERO_4 : constant Lim_w_Equal;

   TWO_4  : constant Lim_w_Equal;

   --

   type Lim_Tagged_wo_Equal is tagged limited private;

   function Create (N : in Natural) return Lim_Tagged_wo_Equal;

   ZERO_5 : constant Lim_Tagged_wo_Equal;

   TWO_5  : constant Lim_Tagged_wo_Equal;

   --

   type Lim_Tagged_w_Equal is tagged limited private;

   function Create (N : in Natural) return Lim_Tagged_w_Equal;

   function "=" (Left, Right : in Lim_Tagged_w_Equal) return Boolean;

   ZERO_6 : constant Lim_Tagged_w_Equal;

   TWO_6  : constant Lim_Tagged_w_Equal;


private
   type Lim_Never_Equal is limited record
      Val : Natural := 1;
   end record;

   function Create (N : in Natural) return Lim_Never_Equal is (Val => N);

   ZERO_1 : constant Lim_Never_Equal := (Val => 0);

   TWO_1  : constant Lim_Never_Equal := (Val => 2);

   --

   type Lim_Hidden_Predef_Equal is range 0 .. Natural'Last;

   function Create (N : in Natural) return Lim_Hidden_Predef_Equal is
      (Lim_Hidden_Predef_Equal(N));

   ZERO_2 : constant Lim_Hidden_Predef_Equal := 0;

   TWO_2  : constant Lim_Hidden_Predef_Equal := 2;

   NOPE_2 : constant Boolean := ZERO_2 = TWO_2;           -- OK. {4;1}

   --

   type Lim_Hidden_UDef_Equal is limited record
      Val : Natural := 1;
   end record;

   function "=" (Left, Right : in Lim_Hidden_UDef_Equal) return Boolean is
      (Left.Val = Right.Val);

   function Create (N : in Natural) return Lim_Hidden_UDef_Equal is
      (Val => N);

   ZERO_3 : constant Lim_Hidden_UDef_Equal := (Val => 0);

   TWO_3  : constant Lim_Hidden_UDef_Equal := (Val => 2);

   NOPE_3 : constant Boolean := ZERO_3 = TWO_3;           -- OK. {4;1}

   --

   type Lim_w_Equal is limited record
      Val : Natural := 1;
   end record;

   function Create (N : in Natural) return Lim_w_Equal is
      (Val => N);

   function "=" (Left, Right : in Lim_w_Equal) return Boolean is
      (Left.Val = Right.Val);

   ZERO_4 : constant Lim_w_Equal := (Val => 0);

   TWO_4  : constant Lim_w_Equal := (Val => 2);

   NOPE_4 : constant Boolean := ZERO_4 = TWO_4;           -- OK. {4;1}

   --

   type Lim_Tagged_wo_Equal is tagged limited record
      Val : Natural := 1;
   end record;

   function "=" (Left, Right : in Lim_Tagged_wo_Equal) return Boolean is
      (Left.Val = Right.Val);

   function Create (N : in Natural) return Lim_Tagged_wo_Equal is
      (Val => N);

   ZERO_5 : constant Lim_Tagged_wo_Equal := (Val => 0);

   TWO_5  : constant Lim_Tagged_wo_Equal := (Val => 2);

   NOPE_5 : constant Boolean := ZERO_5 = TWO_5;           -- OK. {4;1}

   --

   type Lim_Tagged_w_Equal is tagged limited record
      Val : Natural := 1;
   end record;

   function Create (N : in Natural) return Lim_Tagged_w_Equal is
      (Val => N);

   function "=" (Left, Right : in Lim_Tagged_w_Equal) return Boolean is
      (Left.Val = Right.Val);

   ZERO_6 : constant Lim_Tagged_w_Equal := (Val => 0);

   TWO_6  : constant Lim_Tagged_w_Equal := (Val => 2);

   NOPE_6 : constant Boolean := ZERO_6 = TWO_6;           -- OK. {4;1}

end B452001_0;
