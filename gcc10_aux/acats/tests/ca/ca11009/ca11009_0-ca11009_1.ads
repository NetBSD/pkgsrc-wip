
     --=================================================================--

package CA11009_0.CA11009_1 is     -- Child Package OS.File_Manager

   -- This package simulates a visible interface for the Operating System.
   -- The actual processing performed by this routine is encapsulated
   -- in the routines of private child package Internals, which is "withed"
   -- by the body of this package.

   procedure Create_File (Mode      : in     File_Mode_Type;
                          File_Key  :    out File_Descriptor_Type);

end CA11009_0.CA11009_1;           -- Child Package OS.File_Manager
