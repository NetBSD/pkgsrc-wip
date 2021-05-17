

     --==================================================================--


package body CC30002_2 is

   procedure Set_Shutter_Speed (C: in out Aperture_Camera) is
      use CC30002_0;
   begin
      -- Artificial for testing purposes.
      C.TC_Shutter_Called := Body_Of_Actual;
   end Set_Shutter_Speed;

   procedure Focus (C: in out Aperture_Camera) is
      use CC30002_0;
   begin
      -- Artificial for testing purposes.
      C.TC_Focus_Called := Body_Of_Actual;
   end Focus;

end CC30002_2;
