-- CA13A02.A
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
--      Check that subunits declared in generic child units of a public 
--      parent have the same visibility into its parent, its siblings 
--      (public and private), and packages on which its parent depends 
--      as is available at the point of their declaration.
--
-- TEST DESCRIPTION:
--      Declare an outside elevator button operation as a subunit in a 
--      generic child package of the basic operation package (FA13A00.A).  
--      This procedure has visibility into its parent ancestor and its 
--      private sibling.
--
--      In the main program, instantiate the child package. Check that 
--      subunits perform as expected.  
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FA13A00.A
--         CA13A02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Public generic child package of an elevator application.  This package
-- provides outside elevator button operations.

generic                           -- Instantiate once for each floor.
   Our_Floor : in Floor;          -- Reference type declared in parent.

package FA13A00_1.CA13A02_4 is    -- Outside Elevator Button Operations

   type Light is (Up, Down, Express, Off);

   type Direction is (Up, Down, Express);

   function Call_Elevator (D : Direction) return Light;

   -- other type definitions and procedure declarations in real application.

end FA13A00_1.CA13A02_4;
