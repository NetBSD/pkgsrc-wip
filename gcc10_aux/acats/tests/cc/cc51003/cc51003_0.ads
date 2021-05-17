-- CC51003.A
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
--      Check that if the ancestor type of a formal derived type is a composite
--      type that is not an array type, the formal type inherits components,
--      including discriminants, from the ancestor type.
--
--      Check for the case where the ancestor type is a record type, and the
--      formal derived type is declared in a generic subprogram.
--
-- TEST DESCRIPTION:
--      Define a discriminated record type in a package. Declare a
--      library-level generic subprogram with a formal derived type using the
--      record type as ancestor. Give the generic subprogram an in out
--      parameter of the formal derived type. Inside the generic, use the
--      discriminant component and modify the remaining components of the
--      record parameter. In the main program, declare record objects with two
--      different discriminant values. Derive an indefinite type from the
--      record type with a new discriminant part. Instantiate the generic
--      subprogram for the root record subtype and the derived subtype. Call
--      the root subtype instance with actual parameters having the two
--      discriminant values. Also call the derived subtype instance with
--      an appropriate actual.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      03 Jan 95   SAIC    Removed unknown discriminant part from formal
--                          derived type.
--      05 Nov 95   SAIC    ACVC 2.0.1 fixes: Removed constrained subtype
--                          instantiation and associated declarations.
--                          Modified commentary.
--
--!


-- Simulate a fragment of a matrix manipulation application.

package CC51003_0 is  -- Matrix types.

   type Matrix is array (Natural range <>, Natural range <>) of Integer;

   type Square (Side : Natural) is record
      Mat : Matrix (1 .. Side, 1 .. Side);
   end record;

   type Double_Square (Number : Natural) is record
      Left  : Square (Number);
      Right : Square (Number);
   end record;

end CC51003_0;
