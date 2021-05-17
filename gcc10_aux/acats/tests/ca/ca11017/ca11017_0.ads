-- CA11017.A
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
--      Check that body of the parent package may depend on one of its own 
--      public children.
--
-- TEST DESCRIPTION:
--      A scenario is created that demonstrates the potential of adding a
--      public child during code maintenance without distubing a large 
--      subsystem.  After child is added to the subsystem, a maintainer
--      decides to take advantage of the new functionality and rewrites
--      the parent's body.
--
--      Declare a string abstraction in a package which manipulates string
--      replacement. Define a parent package which provides operations for 
--      a record type with discriminant.  Declare a public child of this 
--      package which adds functionality to the original subsystem.  In the 
--      parent body, call operations from the public child.
--
--      In the main program, check that operations in the parent and public 
--      child perform as expected.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Simulates application which manipulates strings.

package CA11017_0 is               

   type String_Rec (The_Size : positive) is private;

   type Substring is new string;

   -- ... Various other types used by the application.

   procedure Replace (In_The_String   : in out String_Rec;
                      At_The_Position : in     positive;
                      With_The_String : in     String_Rec);

   -- ... Various other operations used by the application.

private
   -- Different size for each individual record.

   type String_Rec (The_Size : positive) is
      record
         The_Length  : natural := 0;
         The_Content : Substring (1 .. The_Size);
      end record;

end CA11017_0;
