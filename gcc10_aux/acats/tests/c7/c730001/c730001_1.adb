

     --==================================================================--


package body C730001_1 is

   -- Note: This body is the one that should be executed in the test block
   --       below, not the version of the body corresponding to type Clock.

   procedure Set_Display (WC: in out Wall_Clock;
                          D : in     Display_Kind := Analog) is
   begin
      WC.Display      := D;
      WC.Illumination := Phosphorescence;
   end Set_Display;


   procedure Answer (OP : in out Office_Phone;
                     OI : in     Indicator_Type := Buzzer) is
   begin
      OP.Status    := Call_Waiting;
      OP.Indicator := OI;
   end Answer;

end C730001_1;
