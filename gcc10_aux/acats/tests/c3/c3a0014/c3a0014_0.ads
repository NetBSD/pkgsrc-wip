-- C3A0014.A
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
--      Check that if the view defined by an object declaration is aliased,
--      has discriminants, and its nominal subtype is unconstrained, then
--      the object is unconstrained.
--
--      Check that the attribute A'Constrained returns False if A is a formal
--      out or in out parameter and A denotes an aliased view of an object
--      with an unconstrained nominal subtype.
--
-- TEST DESCRIPTION:
--      This test checks rules that applied in Ada 95 but were removed by
--      Amendment 1. We wish to ensure that implementations have removed
--      the enforcement of the old rules.
--
--      The Ada 95 rules applied to objects of a record type with defaulted
--      discriminants, which may be unconstrained variables. If such a
--      variable was declared to be aliased in Ada 95, then it was constrained
--      by its initial value, and the value of the discriminant cannot be
--      changed for the life of the variable. This no longer applies to Ada,
--      and the change needs to be tested.
--
--      A'Constrained returns True if A denotes a constant, value, or
--      constrained variable. Since aliased objects were constrained in Ada
--      95, it had to return True if the actual parameter corresponding to a
--      formal parameter A was an aliased object. Again, this no longer
--      applies to Ada. The objective only mentions formal
--      parameters of mode out and in out, since parameters of mode in are
--      by definition constant, and would result in True anyway.
--
--      This test declares aliased objects of a nominally unconstrained
--      record subtype, both with and without initialization expressions.
--      It also declares access values which point to such objects. It then
--      checks whether Constraint_Error is raised if an attempt is made to
--      change the discriminant value of an aliased object, either directly
--      or via a dereference of an access value. For aliased objects, this
--      check is also performed for subprogram parameters of mode out.
--
--      The test also passes aliased objects and access values which point
--      to such objects as actuals to subprograms and verifies, for parameter
--      modes out and in out, the correct value of P'Constrained if P is the
--      corresponding formal parameter or a dereference thereof.
--
--      Additionally, the test declares a generic package which declares a
--      an aliased object of a formal derived unconstrained type, which is
--      is initialized with the value of a formal object of that type. A
--      procedure declared within the generic assigns a value to the object
--      which has the same discriminant value as the formal derived type's
--      ancestor type. The generic is instantiated with various actuals
--      for the formal object, and the procedure is called. The test determines
--      if Constraint_Error is raised if the discriminant values of the
--      actual corresponding to the formal object and the value assigned
--      by the procedure are not equal.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Nov 95   SAIC    ACVC 2.0.1 fixes: Corrected numerous errors.
--      18 Oct 07   GD      Updated for the removal of these rules from
--                          the Amendment.
--      26 Oct 07   RLB     Updated the test objective and description.
--
--!

package C3A0014_0 is

   subtype Reasonable is Integer range 1..10;
                                          -- Unconstrained (sub)type.
   type UC (D: Reasonable := 2) is record -- Discriminant default.
      S: String (1 .. D) := "Hi";         -- Default value.
   end record;

   type AUC is access all UC;

   -- Nominal subtype is unconstrained for the following:

   Obj0 :         UC;                  -- An unconstrained object.

   Obj1 :         UC := (5, "Hello");  -- Non-aliased with initialization,
                                       -- an unconstrained object.

   Obj2 : aliased UC := (5, "Hello");  -- Aliased with initialization,
                                       -- a constrained object.

   Obj3 :         UC renames Obj2;     -- Aliased (renaming of aliased view),
                                       -- a constrained object.
   Obj4 : aliased UC;                  -- Aliased without initialization, Obj4
                                       -- constrained here to initial value
                                       -- taken from default for type.

   Ptr1 : AUC := new UC'(Obj1);
   Ptr2 : AUC := new UC;
   Ptr3 : AUC := Obj3'Access;
   Ptr4 : AUC := Obj4'Access;


   procedure NP_Proc (A:    out UC);
   procedure NP_Cons (A: in out UC;  B: out Boolean);
   procedure P_Cons  (A:    out AUC; B: out Boolean);


   generic
      type FT is new UC;
      FObj : in out FT;
   package Gen is
      F  : aliased FT := FObj;     -- Constrained if FT has discriminants.
      procedure Proc;
   end Gen;


   procedure Avoid_Optimization_and_Fail ( P : UC; Msg : String );


end C3A0014_0;
