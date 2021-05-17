-- CA11012.A
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
--      Check that a child package of a library level instantiation
--      of a generic can be the instantiation of a child package of
--      the generic. Check that the child instance can use its parent's
--      declarations and operations, including a formal type of the parent. 
--      
-- TEST DESCRIPTION:
--      Declare a generic package which simulates an integer complex 
--      abstraction.  Declare a generic child package of this package 
--      which defines additional complex operations. 
--
--      Instantiate the first generic package, then instantiate the child 
--      generic package as a child unit of the first instance.  In the main
--      program, check that the operations in both instances perform as 
--      expected.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      21 Dec 94   SAIC    Corrected visibility errors for literals
--      27 Feb 97   PWB.CTA Added elaboration pragma at package CA11012_3
--!

generic               -- Complex number abstraction.
   type Int_Type is range <>;

package CA11012_0 is
 
   -- Simulate a generic complex number support package. Complex numbers
   -- are treated as coordinates in the Cartesian plane.

   type Complex_Type is private;

   Zero : constant Complex_Type;                      -- Real number (0,0).

   function Complex (Real, Imag : Int_Type)           -- Create a complex
     return Complex_Type;                             -- number.

   function "-" (Right : Complex_Type)                -- Invert a complex
     return Complex_Type;                             -- number.

   function "+" (Left, Right : Complex_Type)          -- Add two complex
     return Complex_Type;                             -- numbers.

private
   type Complex_Type is record
      Real : Int_Type;
      Imag : Int_Type;
   end record;

   Zero : constant Complex_Type := (Real => 0, Imag => 0);

end CA11012_0;
