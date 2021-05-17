
     --==================================================================--

with CA13003_0;
with Report;

procedure CA13003 is
   First_File_Name  : CA13003_0.File_Name := "Joe Smith ";
   First_File_Id    : CA13003_0.File_ID   := 11;
   Second_File_Name : CA13003_0.File_Name := "John Schep";
   Second_File_Id   : CA13003_0.File_ID   := 47;
   Expected_Name    : CA13003_0.File_Name := "          ";
   Student_File     : CA13003_0.File_Rec;
   
   function Process_Input_Files (ID_In   : CA13003_0.File_ID; 
                                 File_In : CA13003_0.File_Rec) return 
     CA13003_0.File_Name renames CA13003_0.CA13003_1.CA13003_4;

   function Process_Audit_Files (ID_In   : CA13003_0.File_ID; 
                                 File_In : CA13003_0.File_Rec) return 
     CA13003_0.File_Name renames CA13003_0.CA13003_2.CA13003_4;
begin
   Report.Test ("CA13003", "Check that separate subunits which share " &
                "an ancestor may have the same name if they have " &
                "different fully qualified names");

   Student_File := (ID => First_File_Id, Name => First_File_Name);

   -- Note that all subunits have the same simple name.
   -- Generate report from file processing.
   CA13003_0.CA13003_1.CA13003_3;
   Expected_Name := Process_Input_Files (First_File_Id, Student_File);
   CA13003_0.CA13003_1.CA13003_5.Generate_Report;

   if not CA13003_0.TC_Open_For_Process or 
     not CA13003_0.TC_Report_From_Process or 
       Expected_Name /= First_File_Name then
         Report.Failed ("Unexpected results in processing file");
   end if;

   CA13003_0.Initialize_File_Rec 
     (Second_File_Name, Second_File_Id, Student_File);

   -- Generate report from file auditing.
   CA13003_0.CA13003_2.CA13003_3;
   Expected_Name := Process_Audit_Files (Second_File_Id, Student_File);
   CA13003_0.CA13003_2.CA13003_5.Generate_Report;

   if not CA13003_0.TC_Open_For_Audit or 
     not CA13003_0.TC_Report_From_Audit or 
       Expected_Name /= Second_File_Name then
         Report.Failed ("Unexpected results in auditing file");
   end if;

   Report.Result;

end CA13003;
