

     --==================================================================--


package body C831001_0.C831001_1 is

   procedure Set_Shutter_Speed (C     : in out Auto_Speed;
                                Speed : in     C831001_Root.Shutter_Speed) is
   begin
      -- Artificial for testing purposes.
      TC_Set_Params (C, Get_Depth_of_Field (C), C831001_Root.Two_Fiftith);
   end Set_Shutter_Speed;

   -------------------------------------------------------
   procedure Self_Test (C : in out Auto_Speed'Class) is
   begin
      -- Artificial for testing purposes.
      Set_Shutter_Speed (C, C831001_Root.Thousandth);
      Focus (C, 27);
   end Self_Test;

   -------------------------------------------------------
   procedure Set_Exposure (C : in out Auto_Speed;
                           X : in     C831001_Root.Exposure) is
   begin
      if C831001_Root."=" (X, C831001_Root.Dark) then
         -- Artificial for testing purposes.
         TC_Set_Params (C, 52, C831001_Root.Four_Hundredth);
      end if;
   end Set_Exposure;


end C831001_0.C831001_1;
