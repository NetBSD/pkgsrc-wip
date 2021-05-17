-- CA11B01.A
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
--      Check that a type derived in a public child inherits primitive 
--      operations from parent.  
--
-- TEST DESCRIPTION:
--      Declare a root record type with discriminant in a package 
--      specification. Declare a primitive subprogram for the type 
--      (foundation code).
--
--      Add a public child to the above package.  Derive a new type 
--      with constraint to the discriminant record type from the parent 
--      package.  Declare a new primitive subprogram to write to the child 
--      derived type.
--
--      Add a new public child to the above package.  This grandchild package
--      derives a new type using the record type from the above package.  
--      Declare a new primitive subprogram to write to the grandchild derived 
--      type.
--
--      In the main program, "with" the grandchild.  Access the inherited 
--      operations from grandparent, parent, and grandchild packages.
--
-- TEST FILES:
--      This test depends on the following foundation code:
--
--         FA11B00.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

-- Child package of FA11B00.
package FA11B00.CA11B01_0 is          -- Application_Two_Widget
-- This public child declares a derived type from its parent.  It 
-- represents processing of widgets in a window system.  
                                                               
   type App2_Widget is new App1_Widget (Maximum_Size => 5000); 
   -- Inherits procedure Create_Widget from parent.

   -- Primitive operation of type App2_Widget.
   -- To be inherited by its children derivatives.
   procedure App2_Widget_Specific_Oper (The_Widget : in out App2_Widget;    
                                        Loc        : in     Widget_Location);

end FA11B00.CA11B01_0;                -- Application_Two_Widget
