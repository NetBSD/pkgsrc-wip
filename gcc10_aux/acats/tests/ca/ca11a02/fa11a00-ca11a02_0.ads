-- CA11A02.A
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
--      Check that a type extended in a client of a public child inherits 
--      primitive operations from parent.  
--
-- TEST DESCRIPTION:
--      Declare a root tagged type in a package specification. Declare two 
--      primitive subprograms for the type (foundation code).
--
--      Add a public child to the above package.  Extend the root type with 
--      a record extension in the specification.  Declare a new primitive 
--      subprogram to write to the child extension.
--
--      In the main program, "with" the child.  Declare an extension of
--      the child extension.  Access the primitive operations from both 
--      parent and child packages.
--
-- TEST FILES:
--      This test depends on the following foundation code:
--
--         FA11A00.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      20 Dec 94   SAIC    Moved declaration of Label_Widget to library level
--
--!

package FA11A00.CA11A02_0 is     -- Color_Widget_Pkg
-- This public child declares an extension from its parent.  It 
-- represents processing of widgets in a window system.  

   type Widget_Color_Enum is (Black, Green, White);

   type Color_Widget is new Widget with           -- Record extension of
      record                                      -- parent tagged type.
         Color : Widget_Color_Enum;
      end record;

   -- Inherits procedure Set_Width from parent.
   -- Inherits procedure Set_Height from parent.

   -- To be inherited by its derivatives.
   procedure Set_Color (The_Widget : in out Color_Widget; 
                        C          : in     Widget_Color_Enum);

end FA11A00.CA11A02_0;     -- Color_Widget_Pkg
