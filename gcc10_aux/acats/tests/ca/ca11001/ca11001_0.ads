-- CA11001.A
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
--      Check that a child unit can be used to provide an alternate view and
--      operations on a private type in its parent package.  Check that a 
--      child unit can be a package.  Check that a WITH of a child unit 
--      includes an implicit WITH of its ancestor unit.  
--
-- TEST DESCRIPTION:
--      Declare a private type in a package specification. Declare 
--      subprograms for the type.
--
--      Add a public child to the above package.  Within the body of this
--      package, access the private type. Declare operations to read and 
--      write to its parent private type.
--
--      In the main program, "with" the child.  Declare objects of the
--      parent private type.  Access the subprograms from both parent and
--      child packages.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CA11001_0 is   -- Cartesian_Complex
--  This package represents a Cartesian view of a complex number.  It contains 
--  a private type plus subprograms to construct and decompose a complex 
--  number.

   type Complex_Int is range 0 .. 100;

   type Complex_Type is private;

   Constant_Complex : constant Complex_Type;

   Complex_Error : exception;

   procedure Cartesian_Assign   (R, I : in     Complex_Int; 
                                 C    :    out Complex_Type);

   function Cartesian_Real_Part (C : Complex_Type) 
     return Complex_Int;

   function Cartesian_Imag_Part (C : Complex_Type) 
     return Complex_Int;

   function Complex (Real, Imaginary : Complex_Int)
     return Complex_Type;                             

private
   type Complex_Type is                      -- Parent private type
      record
         Real, Imaginary : Complex_Int;
      end record;

   Constant_Complex : constant Complex_Type := (Real => 0, Imaginary => 0);

end CA11001_0;       -- Cartesian_Complex
