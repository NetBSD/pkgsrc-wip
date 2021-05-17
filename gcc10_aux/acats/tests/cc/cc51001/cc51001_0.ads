-- CC51001.A
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
--      Check that a formal parameter of a generic package may be a formal
--      derived type. Check that the formal derived type may have an unknown
--      discriminant part. Check that the ancestor type in a formal derived
--      type definition may be a tagged type, and that the actual parameter
--      may be a descendant of the ancestor type. Check that the formal derived
--      type belongs to the derivation class rooted at the ancestor type;
--      specifically, that components of the ancestor type may be referenced
--      within the generic. Check that if a formal derived subtype is
--      indefinite then the actual may be either definite or indefinite.
--
-- TEST DESCRIPTION:
--      Define a class of tagged types with a definite root type. Extend the
--      root type with a discriminated component. Since discriminants of
--      tagged types may not have defaults, the type is indefinite.
--
--      Extend the extension with a second discriminated component, but with
--      a new discriminant part. Declare a generic package with a formal
--      derived type using the root type of the class as ancestor, and an
--      unknown discriminant part. Declare an operation in the generic which
--      accesses the common component of types in the class.
--
--      In the main program, instantiate the generic with each type in the
--      class and verify that the operation correctly accesses the common
--      component.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CC51001_0 is  -- Root type for message class.

   subtype Msg_String is String (1 .. 20);

   type Msg_Type is tagged record                          -- Root type of
      Text : Msg_String := (others => ' ');                -- class (definite).
   end record;

end CC51001_0;
