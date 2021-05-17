
     --=================================================================--

with CA11007_0.CA11007_1.CA11007_2;    -- with Grandchild package Digital
with Report;

procedure CA11007 is

   package Analog  renames CA11007_0.CA11007_1;
   package Digital renames CA11007_0.CA11007_1.CA11007_2;            

   Original_Digital_File,
   Converted_Digital_File : Digital.Digital_File_Type;

   Original_Analog_File : Analog.Analog_File_Type;

begin
   
   -- This code demonstrates how private extensions could be utilized
   -- in child packages to allow for recording on different media.  
   -- The processing contained in the procedures and functions is
   -- "dummy" processing, not intended to perform actual recording,
   -- conversion, or validation operations, but simply to demonstrate 
   -- this type of structural decomposition  as a possible solution to 
   -- a user's design problem.

   Report.Test ("CA11007", "Check that the private part of a grandchild "  &
                           "library unit can utilize its grandparent    "  &
                           "unit's private definition");

   if not Digital.Valid_Initial (Original_Analog_File)
   then
      Report.Failed ("Incorrect initialization of Analog File");
   end if;

   ---

   Digital.Convert (From => Original_Analog_File,        -- Convert file to
                    To   => Converted_Digital_File);     -- digital format.

   if not Digital.Valid_Conversion (To => Converted_Digital_File) then
      Report.Failed ("Incorrect conversion of analog file");
   end if;
             
   ---

   Digital.Recording (Original_Digital_File);            -- Create file in
                                                         -- digital format.
   if not Digital.Validate (Original_Digital_File) then
      Report.Failed ("Incorrect recording of digital file");
   end if;

   Report.Result;

end CA11007; 
