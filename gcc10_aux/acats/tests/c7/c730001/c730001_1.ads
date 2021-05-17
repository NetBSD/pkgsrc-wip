

     --==================================================================--


with C730001_0; use C730001_0;
package C730001_1 is

   type Power_Supply_Type is (Spring, Battery, AC_Current);
   type Speaker_Type      is (None, Present, Adjustable, Stereo);

   type Wall_Clock is new Clock with record
      Power_Source : Power_Supply_Type := Spring;
   end record;

   type Office_Phone is new Phone with record
      Speaker : Speaker_Type := Present;
   end record;

   -- Note: Both procedures below, parameter names and defaults differ from
   --       parent's version.

   -- The Set_Display procedure for type Wall_Clock improves upon the
   -- basic Set_Display procedure of type Clock.

   procedure Set_Display (WC: in out Wall_Clock;
                          D : in     Display_Kind := Analog);

   procedure Answer (OP : in out Office_Phone;
                     OI : in     Indicator_Type := Buzzer);

   -- ...Other wall clock and/or Office_Phone operations (not specified in
   -- this test scenario).

end C730001_1;
