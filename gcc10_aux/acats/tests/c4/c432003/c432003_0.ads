-- C432003.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check that if the type of the ancestor part of an extension aggregate
--      has discriminants that are not inherited by the type of the aggregate,
--      and the ancestor part is a subtype mark that denotes a constrained
--      subtype, Constraint_Error is raised if: 1) any discriminant of the
--      ancestor has a different value than that specified for a corresponding
--      discriminant in the derived type definition for some ancestor of the
--      type of the aggregate, or 2) the value for the discriminant in the
--      record association list is not the value of the corresponding 
--      discriminant.  Check that the components of the value of the
--      aggregate not given by the record component association list are
--      initialized by default as for an object of the ancestor type.
--
-- TEST DESCRIPTION:
--      Consider:
--
--      type T (D1: ...) is tagged ...
--
--      type    DT is new T with ...
--      subtype ST is DT (D1 => 3);    -- Constrained subtype.
--
--      type NT1 (D2: ...) is new DT (D1 => D2) with null record;
--      type NT2 (D2: ...) is new DT (D1 => 6)  with null record;
--      type NT3           is new DT (D1 => 6)  with null record;
--
--      A: NT1 := (T  with D2 => 6); -- OK: T  is unconstrained.
--      B: NT1 := (DT with D2 => 6); -- OK: DT is unconstrained.
--      C: NT1 := (ST with D2 => 6); -- NO: ST.D1 /= D2.
--
--      D: NT2 := (T  with D2 => 4); -- OK: T  is unconstrained.
--      E: NT2 := (DT with D2 => 4); -- OK: DT is unconstrained.
--      F: NT2 := (ST with  . . . ); -- NO: ST.D1 /= DT.D1 as specified in NT2.
--
--      G: NT3 := (T  with D1 => 6); -- OK: T  is unconstrained.
--      H: NT3 := (DT with D1 => 6); -- OK: DT is unconstrained.
--      I: NT3 := (ST with D1 => 6); -- NO: ST.D1 /= DT.D1 as specified in NT3.
--
--      In A, B, D, E, G, and H the ancestor part is the name of an
--      unconstrained subtype, so this rule does not apply. In C, F, and I
--      the ancestor part (ST) is the name of a constrained subtype of DT,
--      which is itself a derived type of a discriminated tagged type T. ST
--      constrains the discriminant of DT (D1) to the value 3; thus, the
--      type of any extension aggregate for which ST is the ancestor part
--      must have an ancestor which also constrained D1 to 3. F and I raise
--      Constraint_Error because NT2 and NT3, respectively, constrain D1 to
--      6. C raises Constraint_Error because NT1 constrains D1 to the value
--      of D2, which is set to 6 in the record component association list of
--      the aggregate.
--
--      This test verifies each of the three scenarios above:
--
--         (1) Ancestor of type of aggregate constrains discriminant with
--             new discriminant.
--         (2) Ancestor of type of aggregate constrains discriminant with
--             value, and has a new discriminant part.
--         (3) Ancestor of type of aggregate constrains discriminant with
--             value, and has no discriminant part.
--
--      Verification is made for cases where the type of the aggregate is
--      once- and twice-removed from the type of the ancestor part.
--      
--      Additionally, a case is included where a new discriminant corresponds
--      to multiple discriminants of the type of the ancestor part.
--
--      To test the portion of the objective concerning "initialization by 
--      default," the test verifies that, after a successful aggregate
--      assignment, components not assigned an explicit value by the aggregate
--      contain the default values for the corresponding components of the
--      ancestor type.
--    
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Dec 94   SAIC    Removed discriminant defaults from tagged types.
--      17 Nov 95   SAIC    ACVC 2.0.1 fixes: Corrected subtype constraint
--                          for component NT_C3.Str2. Added missing component
--                          checks. Removed record component update from
--                          Avoid_Optimization. Fixed incorrect component
--                          checks.
--      02 Dec 95   SAIC    ACVC 2.0.1 fixes: Corrected Failed comment for
--                          Q case.
--
--!

package C432003_0 is

   Default_String : constant String := "This is a default string"; -- len = 24
   Another_String : constant String := "Another default string";   -- len = 22

   subtype Length is Natural range 0..255;

   type ROOT (D1 : Length) is tagged 
      record
         S1  : String (1..D1) := Default_String(1..D1);
         Acc : Natural := 356;
      end record;

   procedure Avoid_Optimization (Rec : in out ROOT); -- Inherited by all type
                                                     -- extensions.

   type Unconstrained_Der is new ROOT with 
      record
         Str1 : String(1..5) := "abcde";
      end record;

   subtype Constrained_Subtype is Unconstrained_Der (D1 => 10);

   type NT_A1 (D2 : Length) is new Unconstrained_Der (D1 => D2) with 
      record
         S2 : String(1..D2);         -- Inherited discrim. constrained by
      end record;                    -- new discriminant.

   type NT_A2 (D3 : Length) is new NT_A1 (D2 => D3) with 
      record
         S3 : String(1..D3);         -- Inherited discrim. constrained by
      end record;                    -- new discriminant.


   type NT_B1 (D2 : Length) is new Unconstrained_Der (D1 => 5) with 
      record
         S2 : String(1..D2);         -- Inherited discrim. constrained by
      end record;                    -- explicit value.

   type NT_B2 (D3 : Length) is new NT_B1 (D2 => 10) with 
      record
         S3 : String(1..D3);         -- Inherited discrim. constrained by
      end record;                    -- explicit value.

   type NT_B3 (D2 : Length) is new Unconstrained_Der (D1 => 10) with
      record
         S2 : String(1..D2);
      end record;


   type NT_C1 is new Unconstrained_Der (D1 => 5) with 
      record
         Str2 : String(1..5);         -- Inherited discrim. constrained
      end record;                     -- No new value.

   type NT_C2 (D2 : Length) is new NT_C1 with 
      record
         S2 : String(1..D2);          -- Inherited discrim. not further
      end record;                     -- constrained, new discriminant.

   type NT_C3 is new Unconstrained_Der(D1 => 10) with
      record
         Str2 : String(1..5);
      end record;


   type MULTI_ROOT (D1 : Length; D2 : Length) is tagged
      record
         S1 : String (1..D1) := Default_String(1..D1);
         S2 : String (1..D2) := Another_String(1..D2);
      end record;

   procedure Avoid_Optimization (Rec : in out MULTI_ROOT); -- Inherited by all
                                                           -- type extensions.
                                                           
   type Mult_Unconstr_Der is new MULTI_ROOT with
      record
         Str1 : String(1..8) := "AbCdEfGh";  -- Derived, no constraints.
      end record;

   -- Subtypes with constrained discriminants.
   subtype Mult_Constr_Sub1 is Mult_Unconstr_Der(D1 => 15,  -- Disc. have
                                                 D2 => 20); -- diff values

   subtype Mult_Constr_Sub2 is Mult_Unconstr_Der(D1 => 15,  -- Disc. have
                                                 D2 => 15); -- same value

   type Mult_NT_A1 (D3 : Length) is 
     new Mult_Unconstr_Der (D1 => D3, D2 => D3) with
      record
         S3 : String(1..D3);      -- Both inherited discriminants constrained
      end record;                 -- by new discriminant.

end C432003_0;
