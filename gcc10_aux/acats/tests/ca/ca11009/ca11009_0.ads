-- CA11009.A
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
--      visible part of the parent unit of its parent unit.
--
-- TEST DESCRIPTION:
--      Declare a parent package containing types and objects used by the 
--      system.  Declare a public child package that provides a visible 
--      interface to the system functionality.
--      Declare a private grandchild package that uses the visible grandparent
--      components to provide the actual functionality to the system. 
--
--      The public child (parent of the private grandchild) uses the 
--      functionality of its private child (grandchild package) to provide 
--      the visible interface to operations of the system.
--
--      The test itself will utilize the visible interface provided in the 
--      public child package to demonstrate a possible structure for
--      file management.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate_body.
--
--!

package CA11009_0 is               -- Package OS.
   pragma Elaborate_Body (CA11009_0);

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

   Max_Files          : constant File_Descriptor_Type := 10;
   An_Ada_File_Name   : constant File_Name_Type       := "AdaFileName";
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

end CA11009_0;                     -- Package OS.
