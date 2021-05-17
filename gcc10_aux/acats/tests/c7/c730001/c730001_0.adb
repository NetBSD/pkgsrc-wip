

     --==================================================================--


package body C730001_0 is

   procedure Set_Display (C   : in out Clock;
                          Disp: in     Display_Kind := Digital) is
   begin
      C.Display      := Disp;
      C.Illumination := Light;
   end Set_Display;

   procedure Answer (The_Phone : in out Phone;
                     Ind       : in     Indicator_Type := Light) is
   begin
      The_Phone.Status    := In_Use;
      The_Phone.Indicator := Ind;
   end Answer;

end C730001_0;
