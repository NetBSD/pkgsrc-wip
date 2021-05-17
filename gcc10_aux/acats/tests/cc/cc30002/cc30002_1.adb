

     --==================================================================--


package body CC30002_1 is

   procedure Self_Test_NonDisp (C: in out Speed_Camera) is
   begin
      -- Nondispatching calls:
      Focus (C);
      Set_Shutter_Speed (C);
   end Self_Test_NonDisp;

   procedure Self_Test_Disp (C: in out Speed_Camera'Class) is
   begin
      -- Dispatching calls:
      Focus (C);
      Set_Shutter_Speed (C);
   end Self_Test_Disp;

   procedure Set_Shutter_Speed (C: in out Speed_Camera) is
   begin
      -- Artificial for testing purposes.
      C.TC_Shutter_Called := Body_In_Instance;
   end Set_Shutter_Speed;

   procedure Focus (C: in out Speed_Camera) is
   begin
      -- Artificial for testing purposes.
      C.TC_Focus_Called := Body_In_Instance;
   end Focus;

end CC30002_1;
