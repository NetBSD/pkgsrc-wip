-- CA11010.A
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
--     Check that a private child package can use entities declared in the
--     private part of its parent unit.
--
-- TEST DESCRIPTION:
--     Declare a parent package containing private types, objects,
--     and functions used by the system. Declare a private child package that 
--     uses the parent components to provide functionality to the system.  
--
--     Declare an array of files with default values for all 
--     component fields of the files (records).  Check the initial state of
--     a specified file for proper default values.  Perform the file "creation"
--     (initialization), which will modify the fields of the record object.
--     Again verify the file object to determine whether the fields have been
--     reset properly.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
   
package CA11010_0 is               -- Package OS.
 
   type File_Descriptor_Type is private;

   Default_Descriptor  : constant File_Descriptor_Type;

   function  Initialize_File           return File_Descriptor_Type;
   procedure Verify_Initial_Conditions (Status : out Boolean);
   function  Final_Conditions_Valid    return Boolean;

private

   type File_Descriptor_Type    is new Integer;
   type File_Name_Type          is new String (1 .. 11);
   type Permission_Type         is (None, User, System);
   type File_Mode_Type          is (Read_Only, Write_Only, Read_Write);
   type File_Status_Type        is (Open, Closed);

   Default_Descriptor : constant File_Descriptor_Type := 0;
   Default_Permission : constant Permission_Type      := None;
   Default_Mode       : constant File_Mode_Type       := Read_Only;
   Default_Status     : constant File_Status_Type     := Closed;
   Default_Filename   : constant File_Name_Type       := "           ";
   An_Ada_File_Name   : constant File_Name_Type       := "AdaFileName";
   Max_Files          : constant File_Descriptor_Type := 100;

   type File_Type is tagged
      record
         Descriptor     : File_Descriptor_Type := Default_Descriptor;
         Name           : File_Name_Type       := Default_Filename;
         Acct_Access    : Permission_Type      := Default_Permission;
         Mode           : File_Mode_Type       := Default_Mode;
         Current_Status : File_Status_Type     := Default_Status;
      end record;

   type File_Array_Type is array (1 .. Max_Files) of File_Type;

   File_Table   : File_Array_Type;
   File_Counter : Integer := 0;

   --

   function Get_File_Name return File_Name_Type;

end CA11010_0;                     -- Package OS.
