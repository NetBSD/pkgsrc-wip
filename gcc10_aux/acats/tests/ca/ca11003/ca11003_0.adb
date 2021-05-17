
     --=================================================================--

package body CA11003_0 is    -- Package body OS 
   
   File_Count : Integer := 0;

   function Next_Available_File return File_Descriptor is
   begin
      File_Count := File_Count + 1;
      return (File_Descriptor(File_Count));
   end Next_Available_File;
   --------------------------------------------------
   procedure Reclaim_File_Descriptor is
   begin
      null;                                        -- Dummy processing unit.
   end Reclaim_File_Descriptor;

end CA11003_0;                          -- Package body OS 
