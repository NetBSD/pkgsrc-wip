
     --=================================================================--

with CA11008_0.CA11008_1;          -- Private child package "withed" by
                                   -- parent body.

package body CA11008_0 is          -- Package body OS

   function Get_File_Name return File_Name_Type is
   begin
      return (Constant_Name);   -- Of course if this was a real function, the
   end Get_File_Name;           -- user would be asked to input a name, or
                                -- there would be some type of similar process.

   -- This subprogram utilizes a call to a subprogram contained in a private
   -- child to perform the actual processing.

   function Initialize_File return File_Descriptor_Type is
   begin
     return (CA11008_0.CA11008_1.Initialize);    -- No parameters are needed, 
                                                 -- since defaults have been 
                                                 -- provided.
   end Initialize_File;

end CA11008_0;                         -- Package body OS
