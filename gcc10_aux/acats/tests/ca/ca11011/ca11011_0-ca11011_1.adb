
     --=================================================================--

with CA11011_0.CA11011_1.CA11011_2;  -- with Child OS.File_Manager.Internals

package body CA11011_0.CA11011_1 is  -- Package body OS.File_Manager

   package Internal renames CA11011_0.CA11011_1.CA11011_2;            

   -- This subprogram utilizes a call to a subprogram contained in a private
   -- child to perform the actual processing.

   procedure Create_File (File_Key : in File_Descriptor_Type) is
   begin
      Internal.Create (Key => File_Key);  -- Other parameters are defaults, 
                                          -- since they are of private types
                                          -- from the parent package.
                                          -- File_Descriptor_Type is private,
                                          -- but declared in visible part of 
                                          -- parent spec.
   end Create_File;

end CA11011_0.CA11011_1;        -- Package body OS.File_Manager
