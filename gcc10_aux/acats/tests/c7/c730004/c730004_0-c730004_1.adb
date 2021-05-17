
     --=================================================================--

package body C730004_0.C730004_1 is 

   function New_File_Validated (File :  File_Type 
                                     := (Descriptor => First_File,
                                         Mode       => Active_Mode,
                                         Name       => System_File_Name))
     return Boolean is                                   
      Result : Boolean := False;                         
   begin                                                 
      if (File.Descriptor > System_File.Descriptor) and  
         (File.Mode in Read_Only .. Read_Write) and (File.Name = "ACVC95")
      then
         Result := True;
      end if;

      return (Result);

   end New_File_Validated;

end C730004_0.C730004_1;       
