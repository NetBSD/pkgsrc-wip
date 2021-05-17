
     --=================================================================--

package CA11007_0.CA11007_1.CA11007_2 is        -- Grandchild package Digital

   type    Digital_File_Type is new File_Type with private;

   procedure Recording (File : out Digital_File_Type);    

   procedure Convert (From : in     Analog_File_Type;
                      To   :    out Digital_File_Type);

   function Validate         (File : in Digital_File_Type) return Boolean;
   function Valid_Conversion (To : Digital_File_Type) return Boolean;
   function Valid_Initial (From : Analog_File_Type) return Boolean;

private

   type Track_Type is new File_Measure_Type;          -- Grandparent type.

   Min_Tracks : constant Track_Type := 
     Track_Type (Null_Measure) + Track_Type'First;    -- Grandparent private 
   Max_Tracks : constant Track_Type :=                -- constant.
     Track_Type (Null_Measure) + Track_Type'Last;

   type Digital_File_Type is new File_Type with       -- Grandparent type.  
      record
         Tracks : Track_Type := Min_Tracks;
      end record;

end CA11007_0.CA11007_1.CA11007_2;             -- Grandchild package Digital
