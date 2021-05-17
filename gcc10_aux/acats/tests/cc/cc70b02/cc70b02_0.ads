-- CC70B02.A
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
--      Check that a formal package actual part may specify actual parameters
--      for a generic formal package. Check that such an actual parameter may
--      be a formal parameter of a previously declared formal package
--      (with a (<>) actual part). Check that a use clause in the generic
--      formal part provides direct visibility of declarations within the
--      generic formal package, including formal parameters (if the formal
--      package has a (<>) actual part). Check that the scope of such a use
--      clause extends to the generic subprogram body. Check that the visible
--      part of the generic formal package includes the first list of basic
--      declarative items of the package specification.
--
--      Check the case where the formal package is declared in a generic
--      package.
--
-- TEST DESCRIPTION:
--      Declare a list abstraction in a generic package which manages lists of
--      elements of any nonlimited type (foundation code). Declare a second
--      generic package which declares operations on discrete types. Declare
--      a third generic package which combines the abstractions of the first
--      two generics and declares operations on lists of elements of discrete
--      types. Provide the third generic package with two formal parameters:
--      (1) a generic formal package with the discrete operation package as
--      template, and (2) a generic formal package with the list abstraction
--      package as template. Use the formal discrete type of the discrete
--      operations generic as the generic formal actual part for the second
--      formal package. Include a use clause for the first formal package in
--      the third generic package formal part.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC70B00.A
--         CC70B02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

generic
   type Discrete_Type is (<>);  -- Discrete types only.
package CC70B02_0 is            -- Discrete type operations.

   procedure Double (Object : in out Discrete_Type);

   -- ... Other operations on discrete objects.

end CC70B02_0;
