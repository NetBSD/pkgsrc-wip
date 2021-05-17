-- CA11022.A
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
--      Check that body of a child unit can instantiate its generic sibling.
--      
-- TEST DESCRIPTION:
--      Declare a package that provides some types for the graphic 
--      application.  Add a generic child package with a subprogram parameter
--      to provide algorithms that can be used by different terminal types
--      but that have to be customized to the specific terminal. Add child 
--      packages to take advantage of the parent types and to provide a 
--      customized operation for each of the different terminals.  The 
--      customized operation will be passed as a generic subprogram parameter 
--      to the child package's sibling.
--
--      The main program "with"s the child packages.  Check that the
--      operations in child units perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CA11022_0 is    -- Graphic Manager
 
   type Row is range 1 .. 66;
   type Column is range 1 .. 80;
   type Radius is range 1 .. 3;
   type Length is range 5 .. 10;

   -- Testing artifice.
   TC_Screen : array (Row, Column) of boolean := (others => (others => false));
   TC_Draw_Circle : boolean := false;
   TC_Draw_Square : boolean := false;

   -- ... and other complicated ones.

end CA11022_0;
