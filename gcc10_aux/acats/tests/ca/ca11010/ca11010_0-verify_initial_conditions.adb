
     --=================================================================--

separate (CA11010_0)
procedure Verify_Initial_Conditions (Status : out Boolean) is
begin
   Status := False;
   if (File_Table(1).Descriptor     = Default_Descriptor) and then
      (File_Table(1).Name           = Default_Filename)   and then
      (File_Table(1).Acct_Access    = Default_Permission) and then
      (File_Table(1).Mode           = Default_Mode)       and then
      (File_Table(1).Current_Status = Default_Status)
   then 
      Status := True;
   end if;
end Verify_Initial_Conditions;
