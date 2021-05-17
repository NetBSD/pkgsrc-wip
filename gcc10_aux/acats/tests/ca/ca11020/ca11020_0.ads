-- CA11020.A
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
--      Check that body of the generic parent package can depend on one of 
--      its own public generic children.
--
-- TEST DESCRIPTION:
--      A scenario is created that demonstrates the potential of adding a
--      public generic child during code maintenance without distubing a large 
--      subsystem.  After child is added to the subsystem, a maintainer
--      decides to take advantage of the new functionality and rewrites
--      the parent's body.
--
--      Declare a bag abstraction in a generic package. Declare a public 
--      generic child of this package which adds a generic procedure to the 
--      original subsystem.  In the parent body, instantiate the public
--      child.  Then instantiate the procedure as a child instance of the
--      public child instance.  
--
--      In the main program, declare an instance of parent.  Check that the 
--      operations in both parent and child packages perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Simulates bag application.

generic
   type Element is private;
   with function Image (E : Element) return String;

package CA11020_0 is

   type Bag is limited private;

   procedure Add (E : in Element; To_The_Bag : in out Bag);

   function Bag_Image (B : Bag) return string;

private
   type Node_Type;
   type Bag is access Node_Type;

   type Node_Type is
      record
         The_Element : Element;

         -- Other components in real application, i.e.,
         -- The_Count   : positive;

         Next        : Bag;
      end record;

end CA11020_0;
