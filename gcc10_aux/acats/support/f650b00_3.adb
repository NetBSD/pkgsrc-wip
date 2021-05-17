
with TCTouch;
package body F650B00_3 is
   function Create return Pump is
     Sump : Pump;
   begin
     TCTouch.Touch('h');
     return Sump;
   end Create;

   procedure Set_Rate( A_Pump: in out Pump; To_Rate: Gallons_Per_Revolution)
   is
   begin
     TCTouch.Touch('i');
     A_Pump.GPRPM := To_Rate;
   end Set_Rate;

   function  Rate( Of_Pump: Pump ) return Gallons_Per_Revolution is
   begin
     TCTouch.Touch('j');
     return Of_Pump.GPRPM;
   end Rate;
end F650B00_3;
