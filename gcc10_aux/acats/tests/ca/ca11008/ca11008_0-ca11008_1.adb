
     --=================================================================--

package body CA11008_0.CA11008_1 is  -- Package body OS.Internals

   function Next_Available_File return File_Descriptor_Type is
   begin
      Private_File_Counter := Private_File_Counter + 1; 
      return (File_Descriptor_Type(File_Counter));
   end Next_Available_File;
   -----------------------------------------------------------------
   function Initialize 
     (File_Name : File_Name_Type := Get_File_Name; -- Parent function
      File_Mode : File_Mode_Type := Read_Write)    -- Parent literal
     return File_Descriptor_Type is                -- Parent type
      Number : File_Descriptor_Type;                         
   begin
      Number := Next_Available_File;
      File_Table(Number).Descriptor := Number;     -- Parent object
      File_Table(Number).Name := File_Name;        -- Default parameter value 
      File_Table(Number).Mode := File_Mode;        -- Default parameter value
      File_Table(Number).Acct_Access := User;
      File_Table(Number).Current_Status := Open;
      return (Number);
   end Initialize;

end CA11008_0.CA11008_1;           -- Package body OS.Internals
