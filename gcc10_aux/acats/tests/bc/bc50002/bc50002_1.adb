

     --==================================================================--


package body BC50002_1 is

   procedure Activate (D: in out Local_Device) is
   begin
      -- ... Take action to activate device.
      D.Status := BC50002_0.Open;
   end Activate;

end BC50002_1;
