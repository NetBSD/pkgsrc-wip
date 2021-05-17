-- CXAA017.A
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
--      Check that Ada.Text_IO function Look_Ahead sets parameter End_Of_Line
--      to True if at the end of a line; otherwise check that it returns the
--      next character from a file (without consuming it), while setting 
--      End_Of_Line to False.  
--      
--      Check that Ada.Text_IO function Get_Immediate will return the next
--      control or graphic character in parameter Item from the specified 
--      file.  Check that the version of Ada.Text_IO function Get_Immediate 
--      with the Available parameter will, if a character is available in the
--      specified file, return the character in parameter Item, and set 
--      parameter Available to True.
--      
-- TEST DESCRIPTION:
--      This test exercises specific capabilities of two Text_IO subprograms, 
--      Look_Ahead and Get_Immediate.  A file is prepared that contains a 
--      variety of graphic and control characters on several lines.
--      In processing this file, a call to Look_Ahead is performed to ensure
--      that characters are available, then individual characters are 
--      extracted from the current line using Get_Immediate.  The characters
--      returned from both subprogram calls are compared with the expected
--      character result.  Processing on each file line continues until
--      Look_Ahead indicates that the end of the line is next.  Separate
--      verification is performed to ensure that all characters of each line
--      are processed, and that the Available and End_Of_Line parameters
--      of the subprograms are properly set in the appropriate instances.
--      
-- APPLICABILITY CRITERIA: 
--      This test is applicable to implementations capable of supporting
--      external Text_IO files.
--
--       
-- CHANGE HISTORY:
--      30 May 95   SAIC    Initial prerelease version.
--      01 May 96   SAIC    Incorporated reviewer comments for ACVC 2.1.
--      26 Feb 97   PWB.CTA Allowed for non-support of some IO operations.
--!

with Ada.Text_IO;
package CXAA017_0 is

   User_Defined_Input_File : aliased Ada.Text_IO.File_Type;

end CXAA017_0;
