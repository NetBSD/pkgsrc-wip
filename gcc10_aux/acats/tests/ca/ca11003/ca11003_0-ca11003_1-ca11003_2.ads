
     --=================================================================--

-- This package contains menu selectable operations for manipulating files.
-- This abstraction builds on the capabilities available from ancestor
-- packages.

package CA11003_0.CA11003_1.CA11003_2 is   

   procedure News (Mode : in     File_Mode;
                   File :    out Extended_File_Type);    

   procedure Copy (Original  : in     Extended_File_Type;
                   Duplicate :    out Extended_File_Type);

   procedure Delete   (File : in Extended_File_Type);

end CA11003_0.CA11003_1.CA11003_2;  -- Grandchild package OS.Operations.Menu
