-- C840001.A
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
--      Check that, for the type determined by the subtype mark of a use type
--      clause, the declaration of each primitive operator is use-visible
--      within the scope of the clause, even if explicit operators with the
--      same names as the type's operators are declared for the subtype. Check
--      that a call to such an operator executes the body of the type's
--      operation.
--
-- TEST DESCRIPTION:
--      A type may declare a primitive operator, and a subtype of that type
--      may overload the operator. If a use type clause names the subtype,
--      it is the primitive operator of the type (not the subtype) which
--      is made directly visible, and the primitive operator may be called
--      unambiguously. Such a call executes the body of the type's operation.
--
--      In a package, declare a type for which a predefined operator is
--      overridden.  In another package, declare a subtype of the type in the
--      previous package.  Declare another version of the predefined operator
--      for the subtype.
--
--      The main program declares objects of both the type and the explicit
--      subtype, and uses the "**" operator for both.  In all cases, the
--      operator declared for the 1st subtype should be the one executed,
--      since it is the primitive operators of the *type* that are made
--      visible; the operators which were declared for the explicit subtype
--      are not primitive operators of the type, since they were declared in
--      a separate package from the original type.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      23 Sep 99   RLB     Added test case where operator made visible is
--                          not visible by selection (as in AI-00122).
--
--!

package C840001_0 is
-- Usage scenario: the predefined operators for a floating point type
-- are overridden in order to take advantage of improved algorithms.

   type Precision_Float is new Float range -100.0 .. 100.0;
   -- Implicit: function "**" (Left: Precision_Float; Right: Integer'Base)
   -- return Precision_Float;

   function "**" (Left: Precision_Float; Right: Integer'Base)
     return Precision_Float;
   -- Overrides predefined operator.

   function "+" (Right: Precision_Float)
     return Precision_Float;
   -- Overrides predefined operator.

   -- ... Other overridden operations.

   TC_Expected : constant Precision_Float := 68.0;

end C840001_0;
