-- BC51020.A
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
--      Check that, for an abstract generic formal derived type whose ancestor
--      type has an abstract primitive subprogram, non-abstract record and
--      private extensions of the formal derived type must override the
--      subprogram. Check that abstract record and private extensions need
--      not override the subprogram.
--
--      Check that, for a non-abstract generic formal derived type whose
--      ancestor type has an abstract primitive subprogram, record and
--      private extensions of the formal derived type need not override
--      the subprogram.
--
-- TEST DESCRIPTION:
--      If a formal derived type is declared abstract, it inherits the
--      abstract primitive subprograms of the ancestor type as abstract,
--      and non-abstract type extensions of the formal derived type must
--      override these subprograms.
--
--      If a formal derived type is not declared abstract, by definition it
--      does not have abstract primitive subprograms, even if the ancestor
--      type has abstract primitive subprograms. Thus any type extensions
--      of the formal derived type need not override anything.
--
--      This test checks that if a type extension of a formal derived type
--      inherits an abstract subprogram, it must either be declared abstract
--      or override the abstract subprogram. In particular, this is checked
--      for the case where the subprogram to be inherited is a procedure
--      which has been explicitly declared as abstract (the ancestor type
--      is thus abstract). Record extensions, and abstract and non-abstract
--      private extensions are checked. Cases are verified for both abstract
--      and non-abstract formal derived types.
--
-- PASS/FAIL CRITERIA:
--     This test contains several lines marked POSSIBLE ERROR: [Setnn].
--     For each value of n, the implementation must detect one or more of
--     these possible errors. For instance, an error must be detected on
--     at least one of the lines labeled POSSIBLE ERROR: [Set1] for an
--     implementation to pass.
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      09 Nov 95   SAIC    ACVC 2.0.1 fixes: Changed two ERROR cases to
--                          OK. Eliminated resulting redundant cases.
--      11 Aug 96   SAIC    ACVC 2.1: Added optional ERROR comment to
--                          Private_Extension.
--      21 Nov 19   RLB     Added error location indicators.
--
--!

package BC51020_0 is

   type Ancestor is abstract tagged record               -- Root type of class
      Component : Boolean := False;                      -- (abstract).
   end record;

   procedure Set_Comp (P : in out Ancestor) is abstract; -- Abstract
                                                         -- procedure.
   -- ...Other operations.

end BC51020_0;
