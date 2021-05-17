

     --==================================================================--


with CC30002_0;
package CC30002_2 is

   type Aperture_Camera is new CC30002_0.Camera with record
      FStop: Natural;
      -- ...Other components.
   end record;

   procedure Set_Shutter_Speed (C: in out Aperture_Camera);
   procedure Focus (C: in out Aperture_Camera);

end CC30002_2;
