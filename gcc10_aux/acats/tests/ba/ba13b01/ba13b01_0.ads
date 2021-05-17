-- BA13B01.A
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
--      Check that a separate subprogram declared in a private child unit 
--      of a public parent does not have visibility into the private part 
--      of the package on which its parent depends or the private part of 
--      its parent's public sibling.
--
-- TEST DESCRIPTION:
--      Declare a public parent package.  Declare a public child package
--      with a private part.  Declare a procedure as a subunit in a private
--      child package.  Verify that all cases in which a subunit tries to 
--      access the private parts are illegal.
--
-- TEST FILES:
--      The following files comprise this test:
--
--      FA13B00.A
--      BA13B01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      27 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

-- Public parent.

package BA13B01_0 is                      

   type Parent_Integer is range 21 .. 50;

   type Parent_Color is (White, Black, Red);

   -- Other type definitions in real application.

end BA13B01_0;
