-- CA13001.A
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
--      Check that a separate protected unit declared in a non-generic child 
--      unit of a private parent have the same visibility into its parent, 
--      its siblings, and packages on which its parent depends as is available 
--      at the point of their declaration.
--
-- TEST DESCRIPTION:
--      A scenario is created that demonstrates the potential of having all
--      members of one family to take out a transportation.  The restriction
--      is depend on each member to determine who can get a car, a clunker, 
--      or a bicycle.  If no transportation is available, that member has to
--      walk.  
--      
--      Declare a package with location for each family member.  Declare
--      a public parent package.  Declare a private child package. Declare a 
--      public grandchild of this private package.  Declare a protected unit 
--      as a subunit in a public grandchild package.  This subunit has 
--      visibility into it's parent body ancestor and its sibling.
--
--      Declare another public parent package.  The body of this package has
--      visibility into its private sibling's descendants.
--
--      In the main program, "with"s the parent package.  Check that the
--      protected subunit performs as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

package CA13001_0 is                    

   type Location is (School, Work, Beach, Home);
   type Family is (Father, Mother, Teen);
   Destination : array (Family) of Location;

   -- Other type definitions and procedure declarations in real application.

end CA13001_0;
