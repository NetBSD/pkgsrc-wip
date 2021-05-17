

     --==================================================================--


with C730001_0; use C730001_0;
with C730001_1; use C730001_1;
package C730001_2 is

   type Alarm_Type  is (Buzzer, Radio, Both);
   type Video_Type  is (None, TV_Monitor, Wall_Projection);

   type Alarm_Clock is new Clock with private;
   -- Inherits proc Set_Display (C   : in out Clock;
   --                            Disp: in     Display_Kind := Digital); -- (A)
   --
   -- Would also inherit other general clock operations (if present).


   type Conference_Room_Phone is new Office_Phone with record
      Display : Video_Type := TV_Monitor;
   end record;

   procedure Answer (CP : in out Conference_Room_Phone;
                     CI : in     Indicator_Type := Modem);


   function TC_Get_Display              (C: Alarm_Clock) return Display_Kind;
   function TC_Get_Display_Illumination (C: Alarm_Clock) 
     return Illumination_Type;

private

   -- ...however, certain of the wall clock's operations (Set_Display, in 
   -- this example) improve on the implementations provided for the general
   -- clock. We want to call the improved implementations, so we
   -- derive from Wall_Clock in the private part.

   type Alarm_Clock is new Wall_Clock with record
      Alarm : Alarm_Type := Buzzer;
   end record;

   -- Inherits proc Set_Display (WC: in out Wall_Clock;
   --                            D : in     Display_Kind := Analog);    -- (B)

   -- The implicit Set_Display at (B) overrides the implicit Set_Display at 
   -- (A), but only within the scope of the full view. 
   --
   -- Outside the scope of the full view, only (A) is visible, so calls
   -- from outside the scope will get the formal parameter names and default
   -- from (A). Both inside and outside the scope, however, the body executed
   -- will be that corresponding to Set_Display of the parent type.

end C730001_2;
