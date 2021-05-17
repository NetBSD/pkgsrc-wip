
     --=================================================================--

package body CA11003_0.CA11003_1 is     -- Child package body OS.Operations

   procedure Create_File 
     (Mode : in     File_Mode;
      File :    out Extended_File_Type) is                 
   begin
      File.Descriptor := Next_Available_File;           -- Parent subprogram.
      File.Mode       := Default_Mode;                  -- Parent constant.
      File.Blocks     := Min_File_Size;
   end Create_File;
   --------------------------------------------------
   procedure Duplicate_File (Original  : in     Extended_File_Type;
                             Duplicate :    out Extended_File_Type) is
   begin
      Duplicate.Descriptor := Next_Available_File;      -- Parent subprogram.
      Duplicate.Mode       := Original.Mode;
      Duplicate.Blocks     := Original.Blocks;
   end Duplicate_File;

end CA11003_0.CA11003_1;                   -- Child package body OS.Operations
