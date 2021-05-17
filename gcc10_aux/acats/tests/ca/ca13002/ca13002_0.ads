-- CA13002.A
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
--      Check that two library child units and/or subunits may have the same 
--      simple names if they have distinct expanded names.
--
-- TEST DESCRIPTION:
--      Declare a package that provides some primitive functionality (minimal
--      terminal driver operations in this case).  Add child packages to 
--      expand the functionality for different but related contexts (different
--      terminal kinds).  Add child packages, or subunits, to the children to
--      provide the same high level operation for each of the different 
--      contexts (terminals).  Since the operations are the same, at the leaf
--      level they are likely to have the same names.
--
--      The main program "with"s the child packages.  Check that the
--      child units and subunits perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!
   
-- Public parent.
package CA13002_0 is                     -- Terminal_Driver.

   type TC_Name is (First_Child, Second_Child, Third_Child, Fourth_Child);
   type TC_Call_From is (First_Grandchild, Second_Grandchild, First_Subunit, 
                           Second_Subunit);
   type TC_Calls_Arr is array (TC_Name, TC_Call_From) of boolean;
   TC_Calls : TC_Calls_Arr := (others => (others => false));

   -- In real application, Send_Control_Sequence sends keystrokes from
   -- the terminal, i.e., space, escape, etc.
   procedure Send_Control_Sequence (Row : in TC_Name;
                                    Col : in TC_Call_From);

end CA13002_0;
