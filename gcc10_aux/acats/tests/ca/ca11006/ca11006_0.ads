-- CA11006.A
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
--      Check that the private part of a child library unit can utilize
--      its parent unit's private definition.
--
-- TEST DESCRIPTION:
--      Declare a package and public child package, both with private 
--      parts.  The child package will have a private extension of a type 
--      declared in the parent's private part.  In addition, the private 
--      part of the child package specification will make use of some of 
--      the components declared in the private part of the parent.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

package CA11006_0 is      -- Package File_Package 

   type File_Descriptor is private;
   type File_Mode       is (Read_Only, Write_Only, Read_Write);
   type File_Type       is tagged private;

   function  Next_Available_File return File_Descriptor;

private

   type File_Measure    is range 0 .. 1000;
   type File_Descriptor is new Integer;

   Null_File       : constant File_Descriptor := 0;
   Default_Mode    : constant File_Mode       := Read_Write;

   type File_Type is tagged
     record
        Descriptor : File_Descriptor := Null_File;
        Mode       : File_Mode       := Default_Mode;
     end record;

   System_File : File_Type;

end CA11006_0;               -- Package File_Package  
