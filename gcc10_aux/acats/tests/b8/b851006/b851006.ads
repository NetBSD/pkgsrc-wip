-- B851006.A
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
--     Check that an object renaming declaration is illegal if it
--     renames a discriminant-dependent component or subcomponent
--     if the enclosing record type has an unconstrained nominal
--     subtype and the object is not known to be constrained.
--     Part B: Access types and dereferences.
--
-- TEST DESCRIPTION:
--     This test follows the same outline as test B851005.
--
--     Discriminant dependent components can be:
--     (1) A component with a discriminant constraint using a discriminant.
--     (2) A component with an index constraint using a discriminant.
--     (3) A component declared in a variant.
--     We indicate components that are none of these by "Not DDC".
--
--     No enclosing object cannot have an unconstrained-but-definite
--         nominal subtype that's not immutably limited and be:
--     (A) A component of a containing composite type (of any other of these
--         choices) [try both array and record cases];
--     (B) A variable stand-alone object;
--     (C) A formal "in out" or "out" parameter of a subprogram or entry;
--     (D) A generic formal in out parameter (note: the subtype is
--         unconstrained by 12.4(9/2) even if the named subtype is
--         constrained);
--     (E) A nonconstant return object in an extended return statement;
--     (F) A dereference of a general access-to-object type (try an
--         access-to-constant case);
--     (G) A dereference of a pool-specific access-to-object type if the
--         designated type has a constrained partial view;
--     (H) A qualified expression of any of these cases (by AI12-0228-1).
--     Additionally, in a generic body, we assume that a type descended from
--     an untagged generic formal private or derived type is not indefinite
--     and has a constrained partial view. (Thus, if the type is unconstrained,
--     all of the cases noted above are illegal.) Also, formal access types
--     are not pool-specific. We also check that rechecking of the
--     above is done in generic instances.
--
--     All of the following can be the enclosing object, regardless of the
--     subtype:
--     (S) Any object of a immutably limited type;
--     (T) Any object of an indefinite type;
--     (U) A dereference of a pool-specific access-to-object type if the
--         designated type does not have a constrained partial view;
--     (V) A formal "in" parameter of a subprogram or entry;
--     (W) A constant return object in an extended return statement;
--     (X) A qualified aggregate;
--     (Y) A function call;
--     (Z) A stand-alone constant.
--     (Recall that the rules need to pass for *all* enclosing objects of the
--     renamed component; these cases don't automatically make the rename legal
--     if there are other enclosing objects as well). We only try a few of
--     these cases; C-Tests ought to be used to test these legal cases.
--
--     This test includes tests for all three kinds of components,
--     and cases F, G, and U combined with modifiers A and H. Since the access
--     object itself isn't relevant to these rules, we primarily try
--     stand-alone access objects. We try a handful of other cases just to
--     check that the source of the dereference isn't considered when
--     enforcing these rules.
--
--     Note that there are five kinds of access types to check:
--     (a) A named pool specific access type;
--     (b) A named general access-to-object type; ("all")
--     (c) A named general access-to-constant type; ("constant")
--     (d) An anonymous access-to-object type;
--     (e) An anonymous access-to-constant type.
--     For the later two, the context could matter (the semantics of
--     anonymous access type vary by context), so we try some cases
--     of stand-alone objects, components, and of parameters.
--
-- CHANGE HISTORY:
--     08 Jun 2018  RLB  Created test, patterning on B851005.

package B851006 is

   type R0 (D : Integer) is record
      F : Integer := D;
   end record;

   type A0 is array (Integer range <>) of Integer;

   type Rec (D : Integer := 1) is
      record
         F1 : Integer;
         F2 : R0(D);
         F3 : A0(1 .. D);
         case D is
            when 1 =>
               F4 : Integer range -10 .. 0;
               F5 : A0(1..5);
            when others =>
               F6 : Float;
               F7 : R0(5);
           end case;
      end record;

   type PCRec is private; -- Constrained partial view.

   type PDRec (D : Integer := 1) is private;
      -- Unconstrained definite partial view.

   type PIRec (D : Integer) is private;
      -- Unconstrained indefinite partial view.

   type Outer_Rec is record
      F : Rec;
   end record;

   procedure Fooey (A : in Rec); -- Force a body.

private

   type PCRec (D : Integer := 1) is
      record
         F1 : Integer;
         F2 : R0(D);
         F3 : A0(1 .. D);
         case D is
            when 1 =>
               F4 : Integer range -10 .. 0;
               F5 : A0(1..5);
            when others =>
               F6 : Float;
               F7 : R0(5);
           end case;
      end record;

   type PDRec (D : Integer := 1) is
      record
         F1 : Integer;
         F2 : R0(D);
         F3 : A0(1 .. D);
         case D is
            when 1 =>
               F4 : Integer range -10 .. 0;
               F5 : A0(1..5);
            when others =>
               F6 : Float;
               F7 : R0(5);
           end case;
      end record;

   type PIRec (D : Integer) is
      record
         F1 : Integer;
         F2 : R0(D);
         F3 : A0(1 .. D);
         case D is
            when 1 =>
               F4 : Integer range -10 .. 0;
               F5 : A0(1..5);
            when others =>
               F6 : Float;
               F7 : R0(5);
           end case;
      end record;

end B851006;
