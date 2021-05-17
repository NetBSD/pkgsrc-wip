                          -- Grandchild Package OS.File_Manager.Internals

     --=================================================================--

                          -- Grandchild Package body OS.File_Manager.Internals
package body CA11009_0.CA11009_1.CA11009_2 is  

   function Next_Available_File return File_Descriptor_Type is
   begin
      File_Counter := File_Counter + 1;              -- Grandparent object.
      return (File_Descriptor_Type(File_Counter));
   end Next_Available_File;
   -------------------------------------------------------------------------
   function Create (Mode : File_Mode_Type)           -- Grandparent literal.
     return File_Descriptor_Type is
      Number : File_Descriptor_Type;                 -- Grandparent type.
   begin
      Number := Next_Available_File;
      File_Table(Number).Descriptor     := Number;   -- Grandparent object.
      File_Table(Number).Name           := Initial_Filename;
      File_Table(Number).Mode           := Mode;     -- Parameter.
      File_Table(Number).Acct_Access    := Initial_Permission;
      File_Table(Number).Current_Status := Initial_Status;
      return (Number);
   end Create;

end CA11009_0.CA11009_1.CA11009_2;  
