
     --=================================================================--

with C730004_0.C730004_1;

package body C730004_0.C730004_2 is  

   procedure Create_File (File : out File_Type) is
      New_File : File_Type;

   begin
      New_File.Descriptor := Next_Available_File;       
      New_File.Mode       := Default_Mode;
      New_File.Name       := C730004_0.C730004_1.System_File_Name;

      if C730004_0.C730004_1.New_File_Validated (New_File) then
         File := New_File;
      else 
         File := (Null_File, Lost, "MISSED");
      end if;

   end Create_File;

   --------------------------------------------------------------
   procedure Modify_File (File : out File_Type) is
   begin
      File.Descriptor := Next_Available_File;      
      File.Mode       := Active_Mode;
      File.Name       := String1;
   end Modify_File;     

   --------------------------------------------------------------
   function  Validate_Create (File : in File_Type) return Boolean is
   begin
      if ((File.Descriptor /= Child_File.Descriptor) and
          (File.Mode = Read_Only) and (File.Name = "ACVC95"))
      then
         return True;
      else
         return False;
      end if;
   end Validate_Create;
  
   ------------------------------------------------------------------------
   function  Validate_Modification (File : in File_Type) 
      return Boolean is      
   begin
      if ((File.Descriptor /= C730004_0.C730004_1.System_File.Descriptor) and 
          (File.Mode = Read_Write) and (File.Name = "ACVC  "))
      then
         return True;
      else
         return False;
      end if;
   end Validate_Modification;

   ------------------------------------------------------------------------
   function  Validate_Dir (Dir : in File_Dir) return Boolean is      
   begin
      if ((Dir.Comp.Descriptor = C730004_0.C730004_1.System_File.Descriptor) 
        and (Dir.Comp.Mode = Write_Only) and (Dir.Comp.Name = String2))
      then
         return True;
      else
         return False;
      end if;
   end Validate_Dir;

end C730004_0.C730004_2;
