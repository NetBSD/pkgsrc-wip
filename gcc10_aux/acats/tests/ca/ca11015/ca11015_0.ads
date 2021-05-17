-- CA11015.A
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
--      Check that a generic child of a non-generic package can use its 
--      parent's declarations and operations.  Check that the instantiation
--      of the generic child can correctly use the operations.
--
-- TEST DESCRIPTION:
--      Declare a map abstraction in a package which manages basic physical
--      maps.  Declare a generic child of this package which defines copies
--      of maps of any discrete type, i.e., population, density, or weather.
--
--      In the main program, declare an instance of the child.  Check that
--      the operations in the parent and instance of the child package 
--      perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Simulates map of physical features, i.e., desert, forest, water, 
-- or plains.

package CA11015_0 is              
   type Map_Type is private;
   subtype Latitude is integer range 1 .. 9;
   subtype Longitude is integer range 1 .. 7;

   type Physical_Features is (Desert, Forest, Water, Plains, Unexplored);
   type Page_Type is range 0 .. 80;
   
   Terra_Incognita : exception;

   -- Use geographic database to initialize the basic map.

   procedure Initialize_Basic_Map (Map  : in out Map_Type);

   function Get_Physical_Feature (Lat  : Latitude;
                                  Long : Longitude;
                                  Map  : Map_Type) return Physical_Features;

   function Next_Page return Page_Type;

private
   type Map_Type is array (Latitude, Longitude) of Physical_Features;
   Basic_Map : Map_Type;
   Page      : Page_Type := 0;       -- Location for each copy of Map.

end CA11015_0;
