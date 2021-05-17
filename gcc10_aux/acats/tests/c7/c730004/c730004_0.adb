
     --=================================================================--

package body C730004_0 is     

   File_Count : Integer := 0;

   function Next_Available_File return File_Descriptor is
   begin
      File_Count := File_Count + 1;
      return (File_Descriptor(File_Count));    -- Type conversion.
   end Next_Available_File;

end C730004_0;     
