-- C460006.A
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
--      Check that a view conversion to a tagged type is permitted in the 
--      prefix of a selected component, an object renaming declaration, and 
--      (if the operand is a variable) on the left side of an assignment 
--      statement. Check that such a renaming or assignment does not change 
--      the tag of the operand.
--
--      Check that, for a view conversion of a tagged type, each
--      nondiscriminant component of the new view denotes the matching
--      component of the operand object. Check that reading the value of the
--      view yields the result of converting the value of the operand object
--      to the target subtype.
--
-- TEST DESCRIPTION:
--      The fact that the tag of an object is not changed is verified by
--      making calls to primitive operations which in turn make (re)dispatching
--      calls, and confirming that the proper bodies are executed.
--
--      Selected components are checked in three contexts: as the object name
--      in an object renaming declaration, as the left operand of an inequality
--      operation, and as the left side of an assignment statement.
--
--      View conversions of an object of a 2nd level type extension are
--      renamed as objects of an ancestor type and of a class-wide type. In
--      one case the operand of the conversion is itself a renaming of an
--      object.
--
--      View conversions of an object of a 2nd level type extension are
--      checked for equality with record aggregates of various ancestor types.
--      In one case, the view conversion is to a class-wide type, and it is
--      checked for equality with the result of a class-wide function with
--      the following structure:
--
--         function F return T'Class is
--            A : DDT     := Expected_Value;
--            X : T'Class := T(A);
--         begin
--            return X;
--
--         end F;
--
--         ...
--
--         Var : DDT := Expected_Value;
--
--         if (T'Class(Var) /= F) then    -- Condition should yield FALSE.
--            FAIL;
--         end if;
--
--      The view conversion to which X is initialized does not affect the
--      value or tag of the operand; the tag of X is that of type DDT (not T),
--      and the components are those of A. The result of this function
--      should equal the value of an object of type DDT initialized to the
--      same value as F.A.
--
--      To check that assignment to a view conversion does not change the tag
--      of the operand, an assignment is made to a conversion of an object,
--      and the object is then passed as an actual to a dispatching operation.
--      Conversions to both specific and class-wide types are checked.
--
--
-- CHANGE HISTORY:
--      20 Jul 95   SAIC    Initial prerelease version.
--      24 Apr 96   SAIC    Added type conversions.
--
--!

package C460006_0 is

   type Call_ID_Kind is (None, Parent_Outer,     Parent_Inner,
                               Child_Outer,      Child_Inner,
                               Grandchild_Outer, Grandchild_Inner);

   type Root_Type is abstract tagged record
      First_Call  : Call_ID_Kind := None;
      Second_Call : Call_ID_Kind := None;
   end record;

   procedure Inner_Proc (X : in out Root_Type) is abstract;
   procedure Outer_Proc (X : in out Root_Type) is abstract;

end C460006_0;
