
     --=================================================================--

with CA11011_0.CA11011_1;       -- with public Child Package OS.File_Manager
with Report;

procedure CA11011 is

   package OS           renames CA11011_0;
   package File_Manager renames CA11011_0.CA11011_1;

   Data_Base_File_Key : OS.File_Descriptor_Type := OS.First_File;
   TC_Status          : Boolean := False;

begin

   -- This test indicates one approach to file management operations.
   -- It is not intended to demonstrate full functionality, but rather
   -- that the use of a private child package can provide a solution
   -- to a typical user situation.

   Report.Test ("CA11011", "Check that a private child package can use "   &
                           "entities declared in the private part of the " &
                           "parent unit of its parent unit");

   OS.Verify_Initial_Conditions (Data_Base_File_Key, TC_Status);

   if not TC_Status then
      Report.Failed ("Initial condition failure");
   end if;

   -- Perform file initializations.

   File_Manager.Create_File (File_Key => Data_Base_File_Key);

   TC_Status := OS.Final_Conditions_Valid (Data_Base_File_Key);

   if not TC_Status then
      Report.Failed ("Bad status return from Create_File");
   end if;

   Report.Result;

end CA11011;
