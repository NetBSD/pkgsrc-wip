
     --=================================================================--

package body CA11006_0 is    -- Package File_Package  
   
   File_Count : Integer := 0;

   function Next_Available_File return File_Descriptor is
   begin
      File_Count := File_Count + 1;
      return File_Descriptor (File_Count);
   end Next_Available_File;

end CA11006_0;               -- Package File_Package   
