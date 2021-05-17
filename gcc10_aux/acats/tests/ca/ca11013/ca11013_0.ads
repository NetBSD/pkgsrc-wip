-- CA11013.A
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
--      Check that a child function of a library level instantiation
--      of a generic can be the instantiation of a child function of
--      the generic. Check that the child instance can use its parent's
--      declarations and operations, including a formal subprogram of the 
--      parent.                                                           
--      
-- TEST DESCRIPTION:
--      Declare a generic package which simulates a real complex
--      abstraction.  Declare a generic child function of this package 
--      which builds a random complex number.  Declare a second
--      package which defines a random complex number generator.  This
--      package provides actual parameters for the generic parent package.
--
--      Instantiate the first generic package, then instantiate the child 
--      generic function as a child unit of the first instance.  In the main
--      program, check that the operations in both instances perform as 
--      expected.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--      19 Oct 96   SAIC    ACVC 2.1: Added pragma Elaborate to context
--                          clause of CA11013_3.
--      27 Feb 97   CTA.PWB Added elaboration pragma at package CA11013_3
--!
  
generic               -- Complex number abstraction.
   type Real_Type is digits <>;
   with function Random_Generator (Seed : Real_Type) return Real_Type;

package CA11013_0 is
 
   -- Simulate a generic complex number support package. Complex numbers
   -- are treated as coordinates in the Cartesian plane.

   type Complex_Type is
     record
        Real : Real_Type;
        Imag : Real_Type;
     end record;

   function Make (Real, Imag : Real_Type)           -- Create a complex
     return Complex_Type;                           -- number.

   procedure Components (Complex_No           : in Complex_Type;
                         Real_Part, Imag_Part : out Real_Type);

end CA11013_0;
