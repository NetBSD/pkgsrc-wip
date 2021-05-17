
     --=================================================================--

package CA11006_0.CA11006_1 is        -- Child package File_Package.Operations

   type File_Length_Type   is private;
   type Extended_File_Type is new File_Type with private;

   System_Extended_File : constant Extended_File_Type;

   procedure Create_File (Mode : in     File_Mode;
                          File :    out Extended_File_Type);    

   procedure Compress_File (Original        : in     Extended_File_Type;
                            Compressed_File :    out Extended_File_Type);

   function  Validate (File : in Extended_File_Type) return Boolean;

   function  Validate_Compression (File : in Extended_File_Type) 
     return Boolean;
                                   -- These two validation functions provide
                                   -- the capability to check the private
                                   -- components defined in the parent and
                                   -- child packages from within the client
                                   -- program.
private

   type File_Length_Type is new File_Measure;       -- Parent private type.

   Min_File_Size : File_Length_Type := File_Length_Type'First;
   Max_File_Size : File_Length_Type := File_Length_Type'Last;

   type Extended_File_Type is new File_Type with        -- Parent type.
      record
         Blocks : File_Length_Type := Min_File_Size;
      end record;

   System_Extended_File : constant Extended_File_Type :=
     (Descriptor => System_File.Descriptor,      -- Parent private object.
      Mode       => Read_Only,                   -- Parent enumeration literal.
      Blocks     => Min_File_Size);


end CA11006_0.CA11006_1;             -- Child Package File_Package.Operations
