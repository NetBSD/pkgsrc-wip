-- CA11016.A
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
--      Check that a child of a non-generic package can be a private generic 
--      package. Check that the private child instance can use its parent's
--      declarations and operations.  Check that the body of a public child 
--      package can instantiate its sibling private generic package.
--
-- TEST DESCRIPTION:
--      Declare a map abstraction in a package which manages basic physical
--      map[s].  Declare a private generic child of this package which can be
--      instantiated for any display device which has display locations of 
--      the physical map that can be characterized by any integer type, i.e., 
--      the intensity of the display point.
--
--      Declare a public child of the physical map which specifies the 
--      display device.  In the body of this child, declare an instance of 
--      its generic sibling to display the geographic locations.
--
--      In the main program, check that the operations in the parent, public 
--      child and instance of the private child package perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      17 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate.
--
--!

-- Simulates map of physical features, i.e., desert, forest, or water.

package CA11016_0 is              
   type Map_Type is private;
   subtype Latitude is integer range 1 .. 9;
   subtype Longitude is integer range 1 .. 7;

   type Physical_Features is (Desert, Forest, Water);
   
   -- Use geographic database to initialize the basic map.

   procedure Initialize_Basic_Map (Map  : in out Map_Type);

   function Get_Physical_Feature (Lat  : Latitude;
                                  Long : Longitude;
                                  Map  : Map_Type) return Physical_Features;

private
   type Map_Type is array (Latitude, Longitude) of Physical_Features;
   Basic_Map : Map_Type;

end CA11016_0;
