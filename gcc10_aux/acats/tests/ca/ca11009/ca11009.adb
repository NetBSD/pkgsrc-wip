
     --=================================================================--

with CA11009_0.CA11009_1;       -- with Child Package OS.File_Manager
with Report;

procedure CA11009 is

   package OS           renames CA11009_0;
   use OS;
   package File_Manager renames CA11009_0.CA11009_1;

   Data_Base_File_Key : File_Descriptor_Type := Default_Descriptor;
   New_Mode           : File_Mode_Type := Read_Write;

begin
   
   -- This test indicates one approach to file management.
   -- It is not intended to demonstrate full functionality, but rather
   -- that the use of a private child package could provide a solution
   -- to this type of situation.

   Report.Test ("CA11009", "Check that a private child package can use "   &
                           "entities declared in the visible part of the " &
                           "parent unit of its parent unit");

   -- Check initial conditions of the first entry in the file table.
   -- These are all default values provided in the declaration of the 
   -- type File_Type.                           

   if (not (Data_Base_File_Key      = Default_Descriptor)) and then
      (((not (File_Table(1).Name    = Default_Filename))   or 
      (File_Table(1).Descriptor     /= Default_Descriptor))  or else
      ((File_Table(1).Acct_Access   /= Default_Permission)  or
      (not (File_Table(1).Mode      = Default_Mode))       or
      (File_Table(1).Current_Status /= Default_Status)))
   then
      Report.Failed ("Initial condition failure");
   end if;

   -- Create/initialize file using the capability provided by the visible 
   -- interface to the operating system, OS.File_Manager.  The actual 
   -- processing routine is contained in the private grandchild package 
   -- Internals, which utilize the components from the grandparent package.

   File_Manager.Create_File (New_Mode, Data_Base_File_Key);

   -- Verify that the initial conditions of the file table component have
   -- been properly modified by the initialization function.

   if not ((File_Table(1).Descriptor          = Data_Base_File_Key)   and then
           (File_Table(1).Name                = An_Ada_File_Name)  and then
           (File_Table(1).Acct_Access         = User)              and then
           not ((File_Table(1).Mode           = Default_Mode)      or else
                (File_Table(1).Current_Status = Default_Status)))
   then
      Report.Failed ("File creation failure");
   end if;

   Report.Result;

end CA11009;
