
     --=================================================================--

private
package C730004_0.C730004_1 is                             -- private child

   -- Since full view of the nontagged File_Name is nonlimited in the parent 
   -- package, it is not limited in the private child, so concatenation is 
   -- available.

   System_File_Name :  constant File_Name
                    := String1(1..4) & String2(5..6);

   -- Since full view of the nontagged File_Type is nonlimited in the parent 
   -- package, it is not limited in the private child, so a default expression
   -- is available.

   function New_File_Validated (File :  File_Type 
                                     := (Descriptor => First_File,
                                         Mode       => Active_Mode,
                                         Name       => System_File_Name))
     return Boolean;

   -- Since full view of the nontagged File_Type is nonlimited in the parent 
   -- package, it is not limited in the private child, so initialization
   -- expression in an object declaration is available.

   System_File      :  File_Type 
                    := (Null_File, Read_Only, System_File_Name);


end C730004_0.C730004_1;    
