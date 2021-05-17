
     --=================================================================--

with CA11008_0;                        -- with Package OS.
with Report;

procedure CA11008 is

   package OS renames CA11008_0;
   use OS;
   Ada_File_Key : File_Descriptor_Type := Default_Descriptor;

begin

   -- This test indicates one approach to file management operations.
   -- It is not intended to demonstrate full functionality, but rather
   -- that the use of a private child package can provide a solution
   -- to a user situation, that being the implementation of certain functions
   -- being provided in a child package, with the parent package body 
   -- utilizing these implementations.

   Report.Test ("CA11008", "Check that a private child package can use "   &
                           "entities declared in the visible part of its " &
                           "parent unit");

   -- Check initial conditions of the first entry in the file table.
   -- These are all default values provided in the declaration of the 
   -- type File_Type.

   if (Ada_File_Key                 /= Default_Descriptor)  or else
      (File_Table(1).Descriptor     /= (Default_Descriptor) or
      (File_Table(1).Name           /= Default_Filename))   or else
      (File_Table(1).Acct_Access    /= (Default_Permission) or
      (File_Table(1).Mode           /= Default_Mode))       or else
      (File_Table(1).Current_Status /= Default_Status)
   then
      Report.Failed ("Initial condition failure");
   end if;
   
   -- Call the initialization function.  This will result in the resetting
   -- of the fields associated with the first entry in the File_Table (this
   -- is the first call of Initialize_File).  
   -- No parameters are necessary for this call, due to the default values
   -- provided in the private child package routine Initialize.
   
   Ada_File_Key := Initialize_File;

   -- Verify that the initial conditions of the file table component have
   -- been properly modified by the initialization function.

   if not ((File_Table(1).Descriptor     = Ada_File_Key)         and then
           (File_Table(1).Name           = Constant_Name) and then
           (File_Table(1).Acct_Access    = User)              and then
           not ((File_Table(1).Mode      = Default_Mode)      or else
                (File_Table(1).Current_Status = Default_Status)))
   then
      Report.Failed ("Initialization processing failure");
   end if;

   Report.Result;

end CA11008;
