-- BC54A06.A
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
--      Check that, for a formal access-to-object type, the designated
--      subtypes of the formal and actual must statically match. Check for the
--      case where the access-to-object type is a pool-specific
--      access-to-variable type.
--
-- TEST DESCRIPTION:
--      Two subtypes of the same type statically match if their constraints
--      statically match. Two constraints statically match if they are both
--      null constraints, both are static and have equal corresponding bounds
--      or discriminant values, or both are nonstatic and result from the same
--      elaboration of a constraint of a subtype indication or the same
--      evaluation of a range of a discrete subtype definition.
--      The test declares generics with formal pool-specific access-to-variable
--      types designating tagged and formal discrete types.
--      For each of these designated types (as appropriate), various general
--      and pool-specific access-to-variable actual types are declared which
--      designate unconstrained, constrained, class-wide, and derived types,
--      with null, static, and nonstatic constraints.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC54A00.A
--      -> BC54A06.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC54A00;
package BC54A06_0 is

--
-- Generics declaring formal pool-specific access-to-variable types:
--

   -- Tagged designated type:

   generic
      type Access_To_Variable is access FC54A00.Tag;
   package Pool_Access_To_Var_Tagged is end;

   generic
      type Access_To_Variable is access FC54A00.Tag20;
   package Pool_Access_To_Var_Tag_Static is end;

   generic
      type Access_To_Variable is access FC54A00.Tag20_Nonstatic;
   package Pool_Access_To_Var_Tag_Nonstat is end;



   -- Formal discrete designated type:
   -- Two levels of indirection through formal packages:

   generic                                           -- Template (A) for
      type Formal_Discrete is (<>);                  -- formal package.
   package Outer_FP_Template is end;

   generic                                           -- Template (B) for
      with package Outer_FP is new                   -- formal package.
        Outer_FP_Template (<>);
   package Inner_FP_Template is end;


   package Out_Desig_Num is new                      -- Instance of template A
   Outer_FP_Template (FC54A00.Numerals);             -- to be passed as actual.

   package In_Desig_Num is new                       -- Instance of template B
   Inner_FP_Template (Out_Desig_Num);                -- to be passed as actual.


   generic
      with package Formal_Package is new Inner_FP_Template (<>);
      type Access_To_Variable is access
        Formal_Package.Outer_FP.Formal_Discrete;
   package Pool_Access_To_Var_Form_Disc is end;


end BC54A06_0;
