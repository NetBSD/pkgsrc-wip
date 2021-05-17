-- CC51B03.A
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
--      Check that the attribute S'Definite, where S is an indefinite formal
--      private or derived type, returns true if the actual corresponding to
--      S is definite, and returns false otherwise.
--
-- TEST DESCRIPTION:
--      A definite subtype is any subtype which is not indefinite. An
--      indefinite subtype is either:
--         a) An unconstrained array subtype.
--         b) A subtype with unknown discriminants (this includes class-wide
--            types).
--         c) A subtype with unconstrained discriminants without defaults.
--
--      The possible forms of indefinite formal subtype are as follows:
--
--         Formal derived types:
--          X - Ancestor is an unconstrained array type
--          * - Ancestor is a discriminated record type without defaults
--          X - Ancestor is a discriminated tagged type
--          * - Ancestor type has unknown discriminants
--            - Formal type has an unknown discriminant part
--          * - Formal type has a known discriminant part
--
--         Formal private types:
--            - Formal type has an unknown discriminant part
--          * - Formal type has a known discriminant part
--
--      The formal subtypes preceded by an 'X' above are not covered, because
--      other rules prevent a definite subtype from being passed as an actual.
--      The formal subtypes preceded by an '*' above are not covered, because
--      'Definite is less likely to be used for these formals.
--
--      The following kinds of actuals are passed to various of the formal
--      types listed above:
--
--            - Undiscriminated type
--            - Type with defaulted discriminants
--            - Type with undefaulted discriminants
--            - Class-wide type
--
--      A typical usage of S'Definite might be algorithm selection in a
--      generic I/O package, e.g., the use of fixed-length or variable-length
--      records depending on whether the actual is definite or indefinite.
--      In such situations, S'Definite would appear in if conditions or other
--      contexts requiring a boolean expression. This test checks S'Definite
--      in such usage contexts but, for brevity, omits any surrounding
--      usage code.
--      
-- TEST FILES:
--      The following files comprise this test:
--
--         FC51B00.A
--      -> CC51B03.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC51B00;  -- Indefinite subtype declarations.
package CC51B03_0 is

   --
   -- Formal private type cases:
   --

   generic
      type Formal (<>) is private;              -- Formal has unknown
   package PrivateFormalUnknownDiscriminants is -- discriminant part.
      function Is_Definite return Boolean;
   end PrivateFormalUnknownDiscriminants;


   --
   -- Formal derived type cases:
   --

   generic
      type Formal (<>) is new FC51B00.Vector    -- Formal has an unknown disc.
        with private;                           -- part; ancestor is tagged.
   package TaggedAncestorUnknownDiscriminants is
      function Is_Definite return Boolean;
   end TaggedAncestorUnknownDiscriminants;


end CC51B03_0;
