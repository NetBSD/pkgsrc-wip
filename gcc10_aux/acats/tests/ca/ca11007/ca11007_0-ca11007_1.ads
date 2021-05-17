
     --=================================================================--

package CA11007_0.CA11007_1 is                 -- Child package Analog

   type    Analog_File_Type is new File_Type with private;

private

   type Wavelength_Type is new File_Measure_Type;

   Min_Wavelength : constant Wavelength_Type := Wavelength_Type'First;

   type Analog_File_Type is new File_Type with          -- Parent type.
      record                                           
         Wavelength : Wavelength_Type := Min_Wavelength;
      end record;

end CA11007_0.CA11007_1;                        -- Child package Analog
