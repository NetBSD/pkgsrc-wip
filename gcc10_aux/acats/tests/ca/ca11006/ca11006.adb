
     --=================================================================--

with CA11006_0.CA11006_1;        -- with Child package File_Package.Operations
with Report;

procedure CA11006 is

   package File      renames CA11006_0;
   package File_Ops  renames CA11006_0.CA11006_1;            

   Validation_File_Mode : File.File_Mode := File.Read_Only;
   Validation_File,
   Storage_Copy         : File_Ops.Extended_File_Type;     

begin

   Report.Test ("CA11006", "Check that the private part of a child "  &
                           "library unit can utilize its parent "     &
                           "unit's private definition");

   File_Ops.Create_File (Validation_File_Mode, Validation_File);

   if not File_Ops.Validate (Validation_File) then
      Report.Failed ("Incorrect initialization of file");
   end if;

   File_Ops.Compress_File (Validation_File, Storage_Copy);

   if not (File_Ops.Validate (Validation_File) and 
           File_Ops.Validate_Compression (Storage_Copy))
   then
      Report.Failed ("Incorrect compression of file");
   end if;

   Report.Result;

end CA11006; 
