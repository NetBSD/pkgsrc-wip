-- C730004.A
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
--      Check that for a type declared in a package, descendants of the package
--      use the full view of type.  Specifically check that full view of the
--      limited type is visible only in private descendants (children) and in
--      the private parts and bodies of public descendants (children).
--      Check that a limited type may be used as an out parameter outside
--      the package that defines the type.
--
-- TEST DESCRIPTION:
--      This test defines a parent package containing limited private type 
--      definitions. Children packages are defined (one public, one private) 
--      that use the nonlimited full view of the types defined in the private 
--      part of the parent specification.
--      The main declares a procedure with an out parameter that was defined
--      as limited in the specification of the parent package.
--
--
-- CHANGE HISTORY:
--      15 Sep 95   SAIC    Initial prerelease version.
--      23 Apr 96   SAIC    Added prefix for parameter in Call_Modify_File.
--      02 Nov 96   SAIC    ACVC 2.1: Modified prologue and Test.Report. 
--
--!

package C730004_0 is 

   -- Full views of File_Descriptor, File_Mode, File_Name, and File_Type are
   -- are nonlimited.

   type File_Descriptor is limited private;

   type File_Mode is limited private;

   Active_Mode  : constant File_Mode;

   type File_Name is limited private;

   type File_Type is limited private;

   function Next_Available_File return File_Descriptor;

private

   type File_Descriptor is new Integer;

   Null_File    : constant File_Descriptor := 0;
   First_File   : constant File_Descriptor := 1;

   type File_Mode is 
     (Read_Only, Write_Only, Read_Write, Archived, Corrupt, Lost);

   Default_Mode : constant File_Mode       := Read_Only;
   Active_Mode  : constant File_Mode       := Read_Write;

   type File_Name is array (1 .. 6) of Character;

   Null_String : File_Name := "      ";
   String1     : File_Name := "ACVC  ";
   String2     : File_Name := "  1995";

   type File_Type is 
     record
        Descriptor : File_Descriptor := Null_File;
        Mode       : File_Mode       := Default_Mode;
        Name       : File_Name       := Null_String;
     end record;

end C730004_0;       
