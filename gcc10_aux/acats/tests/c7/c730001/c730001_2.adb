

     --==================================================================--


package body C730001_2 is

   procedure Answer (CP : in out Conference_Room_Phone;
                     CI : in     Indicator_Type := Modem)is
   begin
      CP.Status    := Conference;
      CP.Indicator := CI;
   end Answer;


   function TC_Get_Display (C: Alarm_Clock) return Display_Kind is
   begin
      return C.Display;
   end TC_Get_Display;


   function TC_Get_Display_Illumination (C: Alarm_Clock) 
     return Illumination_Type is
   begin
      return C.Illumination;
   end TC_Get_Display_Illumination;

end C730001_2;
