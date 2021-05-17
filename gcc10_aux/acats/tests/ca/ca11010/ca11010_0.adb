
     --=================================================================--

with CA11010_0.CA11010_1;          -- Private child package "withed" by
                                   -- parent body.

package body CA11010_0 is          -- Package body OS

   function Get_File_Name return File_Name_Type is
   begin
      return (An_Ada_File_Name); -- If this was a real function, the user 
   end Get_File_Name;            -- would be asked to input a name, or there 
                                 -- would be some type of similar processing.

   -- This subprogram utilizes a call to a subprogram contained in a private
   -- child to perform the actual processing.

   function Initialize_File return File_Descriptor_Type is
   begin
     return (CA11010_0.CA11010_1.Initialize);    -- No parameters are needed, 
                                                 -- since defaults have been 
                                                 -- provided.
   end Initialize_File;

   --
   -- Separate subunits.
   --

   procedure Verify_Initial_Conditions (Status : out Boolean) is separate;

   function  Final_Conditions_Valid return Boolean is separate;

end CA11010_0;                         -- Package body OS
