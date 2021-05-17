
     --=================================================================--

                                          -- Grandchild package body Digital
package body CA11007_0.CA11007_1.CA11007_2 is  

   procedure Recording (File : out Digital_File_Type) is
   begin
      File.Descriptor := Next_Available_File;    -- Assign new file descriptor.
      File.Tracks     := Max_Tracks;             -- Change initial value.
   end Recording;
   --------------------------------------------------------------------------
   procedure Convert (From : in     Analog_File_Type;
                      To   :    out Digital_File_Type) is
   begin
      To.Descriptor := From.Descriptor + 100;            -- Dummy conversion.
      To.Tracks     := Track_Type (From.Wavelength) / 2;
   end Convert;                                     
   --------------------------------------------------------------------------
   function  Validate (File : in Digital_File_Type) return Boolean is
      Result : Boolean := False;
   begin
      if not (File.Tracks /= Max_Tracks) then
         Result := True;
      end if;
      return Result;                     
   end Validate;
   --------------------------------------------------------------------------
   function Valid_Conversion (To : Digital_File_Type) return Boolean is
   begin
      return (To.Descriptor = 100) and (To.Tracks = (Min_Tracks / 2));
   end Valid_Conversion;
   --------------------------------------------------------------------------
   function Valid_Initial (From : Analog_File_Type) return Boolean is
   begin
      return (From.Wavelength = Min_Wavelength);     -- Validate initial 
   end Valid_Initial;                                -- conditions.  

end CA11007_0.CA11007_1.CA11007_2;     -- Grandchild package body Digital
