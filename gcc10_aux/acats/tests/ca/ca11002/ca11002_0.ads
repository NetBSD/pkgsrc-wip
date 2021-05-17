-- CA11002.A
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
--      Check that a public child can utilize its parent unit's visible 
--      definitions.
--      
-- TEST DESCRIPTION:
--      Declare a parent package that contains the following: type, object,
--      constant, exception, and subprograms.  Declare a public child unit
--      that utilizes the components found in the visible part of its parent.
--
--      Demonstrate utilization of the following parent components in the 
--      child package:
--
--                          Parent
--          Type              X
--          Constant          X
--          Object            X           
--          Subprogram        X           
--          Exception         X           
--
--      This abstraction simulates a portion of a simple operating system.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CA11002_0 is                      -- Package OS.

   type File_Descriptor is new Integer;
   type File_Mode is (Read_Only, Write_Only, Read_Write);

   Null_File    : constant File_Descriptor := 0;
   Default_Mode : constant File_Mode       := Read_Only;
   Active_Mode  : constant File_Mode       := Read_Write;

   type File_Type is 
     record
        Descriptor : File_Descriptor := Null_File;
        Mode       : File_Mode       := Default_Mode;
     end record;

   System_File     : File_Type;
   File_Mode_Error : exception;

   function Next_Available_File return File_Descriptor;

   function Mode_Of_File (File : File_Type) return File_Mode;

end CA11002_0;                            -- Package OS. 
