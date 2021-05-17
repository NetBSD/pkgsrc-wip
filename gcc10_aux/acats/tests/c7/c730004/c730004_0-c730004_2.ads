
     --=================================================================--

package C730004_0.C730004_2 is                   -- public child

   -- File_Type is limited here.

   procedure Create_File (File : out File_Type);    
                          
   procedure Modify_File (File : out File_Type);

   type File_Dir is limited private;

   -- The following three validation functions provide the capability to 
   -- check the limited private types defined in the parent and the
   -- private child package from within the client program.
                                   
   function  Validate_Create (File : in File_Type) return Boolean;

   function  Validate_Modification (File : in File_Type) 
     return Boolean;

   function  Validate_Dir (Dir : in File_Dir) return Boolean;

private

   -- Since full view of the nontagged File_Type is nonlimited in the parent 
   -- package, it is not limited in the private part of the public child, so 
   -- aggregates are available.

   Child_File :  File_Type 
              := File_Type'(Descriptor => Null_File, 
                            Mode       => Write_Only,
                            Name       => String2);
                     
   -- Since full view of the nontagged component File_Type is nonlimited in 
   -- the parent package, it is not limited in the private part of the public 
   -- child, so default expressions are available.

   type File_Dir is 
     record
        Comp : File_Type := Child_File;
     end record;

end C730004_0.C730004_2;             
