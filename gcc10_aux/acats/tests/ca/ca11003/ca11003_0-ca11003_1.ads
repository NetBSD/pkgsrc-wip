
     --=================================================================--

package CA11003_0.CA11003_1 is          -- Child package OS.Operations

   subtype File_Length_Type is Integer range 0 .. 1000;
   Min_File_Size : File_Length_Type := File_Length_Type'First;
   Max_File_Size : File_Length_Type := File_Length_Type'Last;

   File_Duplication_Error : exception;

   type Extended_File_Type is new File_Type with private;

   procedure Create_File (Mode : in     File_Mode;
                          File :    out Extended_File_Type);    

   procedure Duplicate_File (Original  : in     Extended_File_Type;
                             Duplicate :    out Extended_File_Type);

private
   type Extended_File_Type is new File_Type with
      record
         Blocks : File_Length_Type := Min_File_Size;
      end record;

   System_Extended_File : Extended_File_Type;

end CA11003_0.CA11003_1;                -- Child Package OS.Operations 
