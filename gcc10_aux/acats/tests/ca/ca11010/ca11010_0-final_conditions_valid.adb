
     --=================================================================--

separate (CA11010_0)
function Final_Conditions_Valid return Boolean is 
begin
   if  ((File_Table(1).Descriptor         /= Default_Descriptor) and then
        (File_Table(1).Name                = An_Ada_File_Name)   and then
        (File_Table(1).Acct_Access         = User)               and then
        not ((File_Table(1).Mode           = Default_Mode)       or else
             (File_Table(1).Current_Status = Default_Status)))
   then
      return (True);
   else
      return (False);
   end if;
end Final_Conditions_Valid;
