
     --=================================================================--

-- Grandchild subprogram Validate 
function  CA11003_0.CA11003_1.CA11003_3         
  (File : in Extended_File_Type)                            -- Parent type.
  return Boolean is      

   function New_File_Validated (File : Extended_File_Type) 
       return Boolean is  
   begin                                                
      if (File.Descriptor > System_File.Descriptor) and     -- Grandparent
         (File.Mode in File_Mode ) and                      -- object and type
         not ((File.Blocks < System_Extended_File.Blocks) or       
              (File.Blocks > Max_File_Size))                -- Parent object
      then                                                  -- and constant.
         return True;
      else
         return False;
      end if;
   end New_File_Validated;
      
begin
   return (New_File_Validated (File)) and    
          (File.Descriptor /= Null_File);              -- Grandparent constant.
                                                 
end CA11003_0.CA11003_1.CA11003_3;      -- Grandchild subprogram Validate
