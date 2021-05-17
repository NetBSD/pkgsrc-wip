-- B324003.A
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
--     Check that rules prohibiting use of subtypes with predicates are
--     enforced in generic instances.
--
-- TEST DESCRIPTION:
--     Check one problem per generic. Try using various generic formal
--     types. We try some cases in the private part as well as the
--     visible specification.
--
--     (A) Unconstrained array index subtypes with a predicate.
--     (B) Constrained array index subtypes with a predicate.
--     (C) Entry family subtype with a predicate.
--     (D) Index constraints that is a subtype with a predicate.
--     (E) Slice indexing that is a subtype with a predicate.
--     (F) Prefix of 'First, 'Last, or 'Range with a predicate.
--     (G) Subtype of a for loop with a dynamic predicate.
--     (H) Aggregate choice that is a nonstatic subtype with a predicate.
--
--     Note: It appears that (D), (E), and (H) cannot be tested, as we
--     only have generic formal types (not subtypes), and using the type
--     to declare the array to use for the index constraint, slice, or
--     aggregate choice will necessarily violate (A) or (B).
--
-- CHANGE HISTORY:
--      26 May 14   RLB     Created test.
--
--!

package B324003 is

   generic
      type GDisc is (<>);
   package Gen_A is
       type Formal_as_Index_Subtype is array (GDisc range <>) of Boolean;
          -- Actual cannot have a predicate.
   end Gen_A;

   generic
      type GDisc is (<>);
   package Gen_B is
       type Formal_as_Constrained_Index_Subtype is array (GDisc) of Boolean;
          -- Actual cannot have a predicate.
   end Gen_B;

   generic
      type GInt is range <>;
   package Gen_C is
      protected type Prot is
         entry Ent (GInt);
      end Prot;
          -- Actual cannot have a predicate.
   end Gen_C;

--   generic
--      type GDer is new Integer;
--   package Gen_D is
--      type OK_Array is array (Integer range <>) of Boolean;
--      subtype Index_Constraint is OK_Array(GDer);
--          -- Actual cannot have a predicate.
--   end Gen_D;
--
--   generic
--      type GDer is new Character;
--   package Gen_E is
--      type OK_Array is array (Character range <>) of Boolean;
--   private
--      OK_Array_Obj: OK_Array := (False, True, False, True);
--      Slice_1: OK_Array := OK_Array_Obj(GDer);
--          -- Actual cannot have a predicate.
--   end Gen_E;

   generic
      type GInt is range <>;
   package Gen_F1 is
      First : constant GInt := GInt'First;
      Last  : constant GInt := GInt'Last;
          -- Actual cannot have a predicate.
   end Gen_F1;

   generic
      type GDisc is (<>);
   package Gen_F2 is
      function F (A : GDisc) return GDisc is
          (GDisc'Succ(A));
   private
      First : constant GDisc := GDisc'First;
      Last  : constant GDisc := GDisc'Last;
          -- Actual cannot have a predicate.
   end Gen_F2;

   generic
      type GDisc is (<>);
   package Gen_G is
      B : Boolean := (for all I in GDisc => True);
          -- Actual cannot have a nonstatic subtype with a predicate.
   end Gen_G;

--   generic
--      type GDer is new Character;
--   package Gen_H is
--      type OK_Array is array (Character range <>) of Boolean;
--
--      Obj : OK_Array := (GDer => True);
--          -- Actual cannot have a nonstatic subtype with a predicate.
--   end Gen_H;

end B324003;
