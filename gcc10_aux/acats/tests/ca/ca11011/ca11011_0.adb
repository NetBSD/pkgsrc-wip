
     --=================================================================--

package body CA11011_0 is          -- Package body OS.

   function Get_File_Name return File_Name_Type is
   begin
      return (An_Ada_File_Name);
   end Get_File_Name;
   ---------------------------------------------------------------------
   procedure Verify_Initial_Conditions (Key    : in     File_Descriptor_Type;
                                        Status :    out Boolean) is
   begin
      Status := False;
      if (File_Table(Key).Descriptor     = Default_Descriptor) and then
         (File_Table(Key).Name           = Default_Filename)   and then
         (File_Table(Key).Acct_Access    = Default_Permission) and then
         (File_Table(Key).Mode           = Default_Mode)       and then
         (File_Table(Key).Current_Status = Default_Status)
      then 
         Status := True;
      end if;
   end Verify_Initial_Conditions;
   ---------------------------------------------------------------------
   function Final_Conditions_Valid (Key : File_Descriptor_Type) 
     return Boolean is
   begin
      if  ((File_Table(Key).Descriptor          = First_File)         and then
           (File_Table(Key).Name                = An_Ada_File_Name)   and then
           (File_Table(Key).Acct_Access         = Init_Permission)    and then
           not ((File_Table(Key).Mode           = Default_Mode)       or else
                (File_Table(Key).Current_Status = Default_Status)))
      then
         return (True);
      else
         return (False);
      end if;
   end Final_Conditions_Valid;

end CA11011_0;                     -- Package body OS.
