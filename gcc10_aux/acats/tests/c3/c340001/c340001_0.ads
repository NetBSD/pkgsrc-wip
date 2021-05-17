-- C340001.A
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
--      Check that user-defined equality operators are inherited by a
--      derived type except when the derived type is a nonlimited record
--      extension. In the latter case, ensure that the primitive
--      equality operation of the record extension compares any extended
--      components according to the predefined equality operators of the
--      component types.  Also check that the parent portion of the extended
--      type is compared using the user-defined equality operation of the
--      parent type.
--
-- TEST DESCRIPTION:
--      Declares a nonlimited tagged record and a limited tagged record
--      type, each in a separate package. A user-defined "=" operation is
--      defined for each type. Each type is extended with one new record
--      component added.
--
--      Objects are declared for each parent and extended types and are
--      assigned values. For the limited type, modifier operations defined
--      in the package are used to assign values.
--
--      To verify the use of the user-defined "=", values are assigned so
--      that predefined equality will return the opposite result if called.
--      Similarly, values are assigned to the extended type objects so that
--      one comparison will verify that the inherited components from the
--      parent are compared using the user-defined equality operation.
--
--      A second comparison sets the values of the inherited components to
--      be the same so that equality based on the extended component may be
--      verified. For the nonlimited type, the test for equality should
--      fail, as the "=" defined for this type should include testing
--      equality of the extended component. For the limited type, "=" of the
--      parent should be inherited as-is, so the test for equality should
--      succeed even though the records differ in the extended component.
--
--      A third package declares a discriminated tagged record. Equality
--      is user-defined and ignores the discriminant value. A type
--      extension is declared which also contains a discriminant. Since
--      an inherited discriminant may not be referenced other than in a
--      "new" discriminant, the type extension is also discriminated. The
--      discriminant is used as the constraint for the parent type.
--
--      A variant part is declared in the type extension based on the new
--      discriminant. Comparisons are made to confirm that the user-defined
--      equality operator is used to compare values of the type extension.
--      Two record objects are given values so that user-defined equality
--      for the parent portion of the record succeeds, but the variant
--      parts in the type extended object differ. These objects are checked
--      to ensure that they are not equal.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--
--! 

with Ada.Calendar;
package C340001_0 is

   type DB_Record is tagged record
      Key : Natural range 1 .. 9999;
      Data : String (1..10);
   end record;

   function "=" (L, R : in DB_Record) return Boolean;

   type Dated_Record is new DB_Record with record
      Retrieval_Time : Ada.Calendar.Time;
   end record;

end C340001_0;
