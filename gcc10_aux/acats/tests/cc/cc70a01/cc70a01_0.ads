-- CC70A01.A
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
--      Check that the visible part of a generic formal package includes the
--      first list of basic declarative items of the package specification.
--      Check for a generic package which declares a formal package with (<>)
--      as its actual part.
--
-- TEST DESCRIPTION:
--      The "first list of basic declarative items" of a package specification
--      is the visible part of the package. Thus, the declarations in the
--      visible part of the actual instance corresponding to a formal
--      package are available in the generic which declares the formal package.
--       
--      Declare a generic package which simulates a complex integer abstraction
--      (foundation code).
--
--      Declare a second, library-level generic package which utilizes the
--      first generic package as a generic formal package (with a (<>)
--      actual_part). In the second generic package, declare objects, types,
--      and operations in terms of the objects, types, and operations declared
--      in the first generic package.
--
--      In the main program, instantiate the first generic package, then
--      instantiate the second generic package and pass the first instance
--      to it as a generic actual parameter. Check that the operations in
--      the second instance perform as expected.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC70A00;         -- Generic complex integer operations.

generic               -- Generic complex matrix operations.
   with package Complex_Package is new FC70A00 (<>);
package CC70A01_0 is

   type Complex_Matrix_Type is                        -- 1st index is matrix
      array (Positive range <>, Positive range <>)    -- row, 2nd is column.
        of Complex_Package.Complex_Type;              
   Dimension_Mismatch : exception;


   function Identity_Matrix (Size : Positive)         -- Create identity matrix
     return Complex_Matrix_Type;                      -- of specified size.

   function "*" (Left  : Complex_Matrix_Type;         -- Multiply two complex
                 Right : Complex_Matrix_Type)         -- matrices.
     return Complex_Matrix_Type;

end CC70A01_0;
