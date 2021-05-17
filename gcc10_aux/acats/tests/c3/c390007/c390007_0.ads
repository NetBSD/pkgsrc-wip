-- C390007.A
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
--      Check that the tag of an object of a tagged type is preserved by
--      type conversion and parameter passing.
--
-- TEST DESCRIPTION:
--      The fact that the tag of an object is not changed is verified by
--      making dispatching calls to primitive operations, and confirming that
--      the proper body is executed. Objects of both specific and class-wide
--      types are checked. 
--
--      The dispatching calls are made in two contexts. The first is a
--      straightforward dispatching call made from within a class-wide
--      operation. The second is a redispatch from within a primitive
--      operation.
--
--      For the parameter passing case, the initial class-wide and specific
--      objects are passed directly in calls to the class-wide and primitive
--      operations. The redispatch is accomplished by initializing a local
--      class-wide object in the primitive operation to the value of the
--      formal parameter, and using the local object as the actual in the
--      (re)dispatching call.
--
--      For the type conversion case, the initial class-wide object is assigned
--      a view conversion of an object of a specific type:
--
--         type T is tagged ...
--         type DT is new T with ...
--
--         A : DT;
--         B : T'Class := T(A); -- Despite conversion, tag of B is that of DT.
--
--      The class-wide object is then passed directly in calls to the
--      class-wide and primitive operations. For the initial object of a
--      specific type, however, a view conversion of the object is passed,
--      forcing a non-dispatching call in the primitive operation case. Within
--      the primitive operation, a view conversion of the formal parameter to
--      a class-wide type is then used to force a (re)dispatching call.
--
--      For the type conversion and parameter passing case, a combining of
--      view conversion and parameter passing of initial specific objects are 
--      called directly to the class-wide and primitive operations. 
--
--
-- CHANGE HISTORY:
--      28 Jun 95   SAIC    Initial prerelease version.
--      23 Apr 96   SAIC    Added use C390007_0 in the main.
--
--!

package C390007_0 is

   type Call_ID_Kind is (None, Parent_Outer,  Parent_Inner,
                               Derived_Outer, Derived_Inner);

   type Root_Type is abstract tagged null record;

   procedure Outer_Proc (X : in out Root_Type) is abstract;
   procedure Inner_Proc (X : in out Root_Type) is abstract;

   procedure ClassWide_Proc (X : in out Root_Type'Class);

end C390007_0;
