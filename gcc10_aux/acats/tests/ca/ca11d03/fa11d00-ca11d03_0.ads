-- CA11D03.A
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
--      Check that an exception declared in a package can be raised by a 
--      client of a child of the package.  Check that it can be renamed in 
--      the client of the child of the package and raised with the correct 
--      effect.
--
-- TEST DESCRIPTION:
--      Declare a package which defines complex number abstraction with
--      user-defined exceptions (foundation code).
--
--      Add a public child package to the above package. Declare two 
--      subprograms for the parent type.  
--
--      In the main program, "with" the child package, then check that
--      an exception can be raised and handled as expected.  
--
-- TEST FILES:
--      This test depends on the following foundation code:
--
--         FA11D00.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Child package of FA11D00.
package FA11D00.CA11D03_0 is     -- Basic_Complex

   function "+" (Left, Right : Complex_Type) 
     return Complex_Type;                   -- Add two complex numbers.

   function "*" (Left, Right : Complex_Type) 
     return Complex_Type;                   -- Multiply two complex numbers.

end FA11D00.CA11D03_0;     -- Basic_Complex
