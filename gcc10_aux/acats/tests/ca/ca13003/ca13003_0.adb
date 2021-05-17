
     --==================================================================--

package body CA13003_0 is       

   procedure Initialize_File_Rec (Name_In : in     File_Name;
                                  ID_In   : in     File_ID;
                                  File_In :    out File_Rec) is
   -- Not a real initialization.  Real application can use file
   -- database to create the file record.
   begin
      File_In.Name := Name_In;
      File_In.ID   := ID_In;
   end Initialize_File_Rec;

   package body CA13003_1 is separate;
   package body CA13003_2 is separate;

end CA13003_0;
