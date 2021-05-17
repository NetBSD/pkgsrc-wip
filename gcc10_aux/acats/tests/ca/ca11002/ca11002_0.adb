
     --=================================================================--

package body CA11002_0 is                 -- Package body OS.
   
   File_Count : Integer := 0;

   function Next_Available_File return File_Descriptor is
   begin
      File_Count := File_Count + 1;
      return (File_Descriptor(File_Count));    -- Type conversion.
   end Next_Available_File;
   --------------------------------------------------------------
   function Mode_Of_File (File : File_Type) return File_Mode is
      Mode : File_Mode := File.Mode;
   begin
      return (Mode);
   end Mode_Of_File;

end CA11002_0;                            -- Package body OS.
