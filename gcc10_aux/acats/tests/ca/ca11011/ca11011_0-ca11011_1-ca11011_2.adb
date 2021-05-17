
     --=================================================================--

                                     -- Package Body OS.File_Manager.Internals
package body CA11011_0.CA11011_1.CA11011_2 is  

   procedure Create 
     (Key         : in     File_Descriptor_Type; 
      File_Name   : in     File_Name_Type   := Get_File_Name;
      File_Mode   : in     File_Mode_Type   := Init_Mode;
      File_Access : in     Permission_Type  := Init_Permission;
      File_Status : in     File_Status_Type := Init_Status) is
   begin
      Private_File_Counter := Private_File_Counter + 1;
      File_Table(Key).Descriptor     := Key;            -- Grandparent object.
      File_Table(Key).Name           := File_Name;            
      File_Table(Key).Mode           := File_Mode;            
      File_Table(Key).Acct_Access    := File_Access;            
      File_Table(Key).Current_Status := File_Status;
   end Create;

end CA11011_0.CA11011_1.CA11011_2;   -- Package body OS.File_Manager.Internals
