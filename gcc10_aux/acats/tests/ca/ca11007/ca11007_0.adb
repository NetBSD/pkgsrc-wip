
     --=================================================================--

package body CA11007_0 is                      -- Package body File_Package  

   File_Count : Integer := 0;

   function Next_Available_File return File_Descriptor is
   begin
      File_Count := File_Count + 1;
      return File_Descriptor (File_Count);
   end Next_Available_File;

end CA11007_0;                                 -- Package body File_Package   
