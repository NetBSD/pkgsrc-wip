-- C452001.A
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
--      For a type extension, check that predefined equality is defined in
--      terms of the primitive equals operator of the parent type and any
--      tagged components of the extension part.
--
--      For other composite types, check that the primitive equality operator
--      of any matching record components is used to determine equality of the
--      enclosing type.
--
--      For private types, check that predefined equality is defined in
--      terms of the user-defined (primitive) operator of the full type if
--      the full type is a record type. The partial view of the type may be
--      tagged or untagged. Check that predefined equality for a private
--      type whose full view is an untagged nonrecord type is defined in terms
--      of the predefined equality operator of its full type.
--
-- TEST DESCRIPTION:
--      Tagged types are declared and used as components in several
--      differing composite type declarations, both tagged and untagged.
--      To differentiate between predefined and primitive equality
--      operations, user-defined equality operators are declared for
--      each component type that is to contribute to the equality
--      operator of the composite type that houses it. All user-defined
--      equality operations are designed to yield the opposite result
--      from the predefined operator, given the same component values.
--
--      For cases where primitive equality is to be incorporated into
--      equality for the enclosing composite type, values are assigned
--      to the component type so that user-defined equality will return
--      True. If predefined equality is to be used instead, then the
--      same strategy results in the equality operator returning False.
--
--      When equality for a type incorporates the user-defined equality
--      operator of one of its component types, the resulting operator
--      is considered to be the predefined operator of the composite type.
--      This case is confirmed by defining an tagged component of an
--      untagged composite type, then using the resulting untagged type
--      as a component of another composite type. The user-defined operator
--      for the lowest level should still be called.
--
--      Four cases are set up to test private types:
--
--                        Case 1    Case 2      Case 3         Case 4
--         partial view:  tagged   untagged    untagged       untagged
--         full view:     tagged    tagged  untagged record  untagged array
--
--      Types are declared for each of the above cases and user-defined
--      (primitive) operators are declared following the full type
--      declaration of each type (i.e., in the private part).
--
--      Values are assigned into objects of these types using the same
--      strategy outlined above. Cases 1, 2 and 3 should execute the
--      user-defined operator. Case 4 should ignore the user-defined
--      operator and use predefined equality for the type.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--      15 Nov 95   SAIC    Fixed for 2.0.1
--      04 NOV 96   SAIC    Typographical revision
--      14 Mar 14   RLB     Updated objective and test to reflect the Ada 2012
--                          rules and add additional array cases to ensure
--                          all of the cases are tested.
--      24 Mar 14   RLB     Reorganized comments to make associations clearer.
--                          Moved declarations of "=" so 4.5.2(9.7/3) is not
--                          violated. Added test cases so incorporation of
--                          private types is tested.
--      03 Apr 14   RLB     Repaired to avoid infinite recursion for body of
--                          "=" for Untagged_Partial_Untagged_Array_Full.
--
--!

package c452001_0 is

   type Point is
      record
         X : Integer := 0;
         Y : Integer := 0;
      end record;

   type Circle is tagged
      record
         Center : Point;
         Radius : Integer;
      end record;

   function "=" (L, R : Circle) return Boolean;

   type Colors is (Red, Orange, Yellow, Green, Blue, Purple, Black, White);

   type Colored_Circle is new Circle
      with record
         Color : Colors := White;
      end record;

   function "=" (L, R : Colored_Circle) return Boolean;
   -- Override predefined equality for this tagged type. Predefined
   -- equality should incorporate user-defined (primitive) equality
   -- from type Circle. See C340001 for a test of that feature.

   -- Equality is overridden to ensure that predefined equality
   -- incorporates this user-defined function for
   -- any composite type with Colored_Circle as a component type.
   -- (i.e., the type extension is recognized as a tagged type for
   -- the purpose of defining predefined equality for the composite type).

end C452001_0;
