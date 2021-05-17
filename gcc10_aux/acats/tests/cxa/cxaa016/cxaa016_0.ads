-- CXAA016.A
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
--      Check that the type File_Access is available in Ada.Text_IO, and that
--      objects of this type designate File_Type objects.
--      Check that function Set_Error will set the current default error file.
--      Check that versions of Ada.Text_IO functions Standard_Input,
--      Standard_Output, Standard_Error return File_Access values designating
--      the standard system input, output, and error files.
--      Check that versions of Ada.Text_IO functions Current_Input,
--      Current_Output, Current_Error return File_Access values designating
--      the current system input, output, and error files.
--      
-- TEST DESCRIPTION:
--      This test tests the use of File_Access objects in referring 
--      to File_Type objects, as well as several new functions that return 
--      File_Access objects as results.
--      Four user-defined files are created.  These files will be set to 
--      function as current system input, output, and error files.
--      Data will be read from and written to these files during the
--      time at which they function as the current system files.  
--      An array of File_Access objects will be defined.  It will be 
--      initialized using functions that return File_Access objects 
--      referencing the Standard and Current Input, Output, and Error files.
--      This "saves" the initial system environment, which will be modified
--      to use the user-defined files as the current default Input, Output,
--      and Error files.  At the end of the test, the data in this array 
--      will be used to restore the initial system environment.
--      
-- APPLICABILITY CRITERIA: 
--      This test is applicable to implementations capable of supporting
--      external Text_IO files.
--
--       
-- CHANGE HISTORY:
--      25 May 95   SAIC    Initial prerelease version.
--      22 Apr 96   SAIC    Incorporated reviewer comments for ACVC 2.1.
--      26 Feb 97   PWB.CTA Allowed for non-support of some IO operations.
--      18 Jan 99   RLB     Repaired to allow Not_Applicable systems to
--                          fail delete.
--!

with Ada.Text_IO;
package CXAA016_0 is
   New_Input_File,
   New_Output_File,
   New_Error_File_1,
   New_Error_File_2 : aliased Ada.Text_IO.File_Type;
end CXAA016_0;
