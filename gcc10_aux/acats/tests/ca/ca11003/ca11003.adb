
     --=================================================================--

with CA11003_0.CA11003_1.CA11003_2;  -- Grandchild Pkg OS.Operations.Menu
with CA11003_0.CA11003_1.CA11003_3;  -- Grandchild Ftn OS.Operations.Validate
with Report;

procedure CA11003 is

   package Menu renames CA11003_0.CA11003_1.CA11003_2;

begin

   Report.Test ("CA11003", "Check that a public grandchild can utilize " &
                "its ancestor unit's visible definitions");

   File_Processing:         -- Validate all of the capabilities contained in 
                            -- the Menu package by exercising them on specific 
                            -- files.  This will demonstrate the use of child
                            -- and grandchild functionality based on components
                            -- that have been declared in the
                            -- parent/grandparent package.
   declare

      function Validate (File : CA11003_0.CA11003_1.Extended_File_Type) 
        return Boolean renames CA11003_0.CA11003_1.CA11003_3;

      MacWrite_File,
      Backup_Copy : CA11003_0.CA11003_1.Extended_File_Type;        
      MacWrite_File_Mode : CA11003_0.File_Mode := CA11003_0.Read_Write;
                                     
   begin                                                
                                                        
      Menu.News (MacWrite_File_Mode, MacWrite_File);                          

      if not Validate (MacWrite_File) then
         Report.Failed ("Incorrect initialization of files");
      end if;

      Menu.Copy (MacWrite_File, Backup_Copy);

      if not (Validate (MacWrite_File) and 
              Validate (Backup_Copy))
      then
         Report.Failed ("Incorrect duplication of files");
      end if;

      Menu.Delete (Backup_Copy);

   exception
      when CA11003_0.File_Data_Error =>
          Report.Failed ("Exception raised during file validation");
      when CA11003_0.CA11003_1.File_Duplication_Error =>
          Report.Failed ("Exception raised during file duplication");
      when others =>
          Report.Failed ("Unexpected exception in test procedure");

   end File_Processing;

   Report.Result;

end CA11003; 
