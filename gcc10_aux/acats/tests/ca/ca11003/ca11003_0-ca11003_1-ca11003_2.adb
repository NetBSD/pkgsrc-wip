
     --=================================================================--

with CA11003_0.CA11003_1.CA11003_3;
                                 -- Grandchild package body OS.Operations.Menu
package body CA11003_0.CA11003_1.CA11003_2 is  

   procedure News (Mode : in     File_Mode;
                   File :    out Extended_File_Type) is   -- Parent type.
   begin
      Create_File (Mode, File);                           -- Parent subprogram.
      if not CA11003_0.CA11003_1.CA11003_3 (File) then                       
         raise File_Data_Error;                       -- Grandparent exception.
      end if;
   end News;
   --------------------------------------------------
   procedure Copy (Original  : in     Extended_File_Type;
                   Duplicate :    out Extended_File_Type) is
   begin
      Duplicate_File (Original, Duplicate);               -- Parent subprogram.

      if Original.Descriptor = Duplicate.Descriptor then
         raise File_Duplication_Error;                    -- Parent exception.
      end if;

   end Copy;
   --------------------------------------------------
   procedure Delete (File : in Extended_File_Type) is
   begin
      Reclaim_File_Descriptor;                            -- Grandparent
   end Delete;                                            -- subprogram.

end CA11003_0.CA11003_1.CA11003_2;  
