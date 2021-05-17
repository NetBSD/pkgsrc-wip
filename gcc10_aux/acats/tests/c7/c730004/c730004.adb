
     --=================================================================--

with C730004_0.C730004_2; 
with Report;

procedure C730004 is

   package File      renames C730004_0;
   package File_Ops  renames C730004_0.C730004_2;            

   Validation_File : File.File_Type;     

   Validation_Dir  : File_Ops.File_Dir;

   ------------------------------------------------------------------------ 
   -- Limited File_Type is allowed as an out parameter outside package File.

   procedure Call_Modify_File (Modified_File : out File.File_Type) is
   begin
      File_Ops.Modify_File (Modified_File);
   end Call_Modify_File;     
  
begin

   Report.Test ("C730004", "Check that for a type declared in a package, "   &
                           "descendants of the package use the full view "   &
                           "of the type.  Specifically check that full "     &
                           "view of the limited type is visible only in "    &
                           "private children and in the private parts and "  &
                           "bodies of public children");

   File_Ops.Create_File (Validation_File);

   if not File_Ops.Validate_Create (Validation_File) then
      Report.Failed ("Incorrect creation of file");
   end if;

   Call_Modify_File (Validation_File);

   if not File_Ops.Validate_Modification (Validation_File) then 
      Report.Failed ("Incorrect modification of file");
   end if;

   if not File_Ops.Validate_Dir (Validation_Dir) then
      Report.Failed ("Incorrect creation of directory");
   end if;

   Report.Result;

end C730004; 
