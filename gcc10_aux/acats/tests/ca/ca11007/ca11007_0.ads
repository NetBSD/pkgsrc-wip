-- CA11007.A
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
--      Check that the private part of a grandchild library unit can
--      utilize its grandparent unit's private definition.
--
-- TEST DESCRIPTION:
--      Declare a package, child package, and grandchild package, all 
--      with private parts in their specifications.  
--
--      The private part of the grandchild package will make use of components
--      that have been declared in the private part of the grandparent
--      specification.
--
--      The child package demonstrates the extension of a parent file type 
--      into an abstraction of an analog file structure. The grandchild package
--      extends the grandparent file type into an abstraction of a digital 
--      file structure, and provides conversion capability to/from the parent 
--      analog file structure.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!
  
package CA11007_0 is                                -- Package File_Package 

   type File_Descriptor is private;
   type File_Type       is tagged private;

   function  Next_Available_File return File_Descriptor;

private

   type File_Measure_Type is range 0 .. 1000;
   type File_Descriptor   is new Integer;

   Null_Measure : constant File_Measure_Type := File_Measure_Type'First;
   Null_File    : constant File_Descriptor   := 0;

   type File_Type is tagged
     record
        Descriptor : File_Descriptor := Null_File;
     end record;

end CA11007_0;                                 -- Package File_Package  
