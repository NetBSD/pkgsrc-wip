
     --=================================================================--

package body CA11009_0 is          -- Package body OS.

   function Get_File_Name return File_Name_Type is
   begin
      return (An_Ada_File_Name);   -- Processing would be replace by a user
                                   -- prompt in a functioning system.
   end Get_File_Name;           
                                
end CA11009_0;                     -- Package body OS.
