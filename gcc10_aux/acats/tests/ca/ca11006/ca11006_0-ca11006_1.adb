
     --=================================================================--

                                -- Child package body File_Package.Operations
package body CA11006_0.CA11006_1 is  

   procedure Create_File 
     (Mode : in     File_Mode; 
      File :    out Extended_File_Type) is                 
   begin
      File.Descriptor := Next_Available_File;    -- Parent subprogram.
      File.Mode       := Default_Mode;           -- Parent private constant.
      File.Blocks     := Max_File_Size;
   end Create_File;
   ------------------------------------------------------------------------
   procedure Compress_File (Original        : in     Extended_File_Type;
                            Compressed_File :    out Extended_File_Type) is
   begin
      Compressed_File.Descriptor := Next_Available_File;      
      Compressed_File.Mode       := Read_Only;
      Compressed_File.Blocks     := Original.Blocks / 2;  -- Simulated file
   end Compress_File;                                     -- compression.
   ------------------------------------------------------------------------
   function  Validate (File : in Extended_File_Type) return Boolean is      
   begin
      if ((File.Descriptor /= System_Extended_File.Descriptor) and    
          (File.Mode = Read_Write)                             and
          (File.Blocks = Max_File_Size))                       then
         return True;
      else
         return False;
      end if;
   end Validate;
   ------------------------------------------------------------------------
   function  Validate_Compression (File : in Extended_File_Type) 
      return Boolean is      
   begin
      if ((File.Descriptor /= System_File.Descriptor) and    
          (File.Mode = Read_Only)                     and
          (File.Blocks = Max_File_Size/2))            then
         return True;
      else
         return False;
      end if;
   end Validate_Compression;

end CA11006_0.CA11006_1;         -- Child package body File_Package.Operations
