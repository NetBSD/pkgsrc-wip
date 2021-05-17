-- B730004.A
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
--      Check that if a public child is "with"ed by a client, the client 
--      does not have visibility into the private part of the child's parent.
--
--      Check that the full view of a private type defined in a parent and
--      extended in a child is not visible outside the child.
--
-- TEST DESCRIPTION:
--      Declare a parent package with a private part.  Declare a public 
--      child package.  Declare two kinds of extensions in the public child:
--      (a) An extension from parent visible tagged type, and (b) An extension
--      from parent private tagged type.  In the main program, "with" the 
--      child and incorrectly use its parent's private declarations and its
--      extensions.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Parent package

package B730004_0 is

   -- Type definitions.

   type Visible_Integer is range 1 .. 10;

   type Private_Record is private;

   type Visible_Tagged is tagged
      record
         PR : Private_Record;
      end record;

   type Private_Tagged is tagged private;

   type Private_Extension is new Visible_Tagged with private;

private

   -- Type definitions.

   type Private_Integer is range 11 .. 20;

   type Private_Record is
      record
         VI : Visible_Integer;
      end record;

   type Private_Tagged is tagged
      record
         VI : Visible_Integer;
      end record;

   type Private_Extension is new Visible_Tagged with
      record
         VI : Visible_Integer;
      end record;

   -- Object definitions.

   Private_Integer_Num : Visible_Integer :=  6;

end B730004_0;
