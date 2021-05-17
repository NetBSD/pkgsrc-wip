-- CA11008.A
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
--      Check that a private child package can use entities declared in the
--      visible part of its parent unit.
--      
-- TEST DESCRIPTION:
--      Declare a parent package containing types and objects used 
--      by the system. Declare a private child package that uses the parent
--      components to provide functionality to the system.  
--
--      The tagged file type defined in the parent has defaults for all
--      component fields.  Prior to initialization, these values are checked
--      to ensure a correct start condition.  The initial subprogram is
--      called, which utilizes the functionality provided in the private
--      child package.  This subprogram changes the fields of the file object
--      to something other than the default values, and this process is then
--      verified at the conclusion of the test.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!
  
package CA11008_0 is               -- Package OS.

   type File_Descriptor_Type is new Integer;
   type File_Name_Type       is new String (1 .. 11);
   type Permission_Type      is (None, User, System, Bypass);
   type File_Mode_Type       is (Read_Only, Write_Only, Read_Write);
   type File_Status_Type     is (Open, Closed);

   Default_Descriptor : constant File_Descriptor_Type := 0;
   Default_Permission : constant Permission_Type      := None;
   Default_Mode       : constant File_Mode_Type       := Read_Only;
   Default_Status     : constant File_Status_Type     := Closed;
   Default_Filename   : constant File_Name_Type       := "           ";

   Max_Files          : constant File_Descriptor_Type := 100;
   Constant_Name      : constant File_Name_Type       := "AdaFileName";
   File_Counter       : Integer                       := 0;

   type File_Type is tagged
      record
         Descriptor     : File_Descriptor_Type := Default_Descriptor;
         Name           : File_Name_Type       := Default_Filename;
         Acct_Access    : Permission_Type      := Default_Permission;
         Mode           : File_Mode_Type       := Default_Mode;
         Current_Status : File_Status_Type     := Default_Status;
      end record;

   type File_Array_Type is array (1 .. Max_Files) of File_Type;

   File_Table : File_Array_Type;

   --

   function Get_File_Name return File_Name_Type;

   function Initialize_File return File_Descriptor_Type;

end CA11008_0;                     -- Package OS.
