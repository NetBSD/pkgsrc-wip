

     --==================================================================--


package body F392D00 is

   procedure Focus (C     : in out Remote_Camera;
                    Depth : in     Depth_Of_Field) is
   begin
      -- Artificial for testing purposes.
      C.DOF := 46;
   end Focus;

   -----------------------------------------------------------
   procedure Set_Shutter_Speed (C     : in out Remote_Camera;
                                Speed : in     Shutter_Speed) is
   begin
      -- Artificial for testing purposes.
      C.Shutter := Thousand;
   end Set_Shutter_Speed;

   -----------------------------------------------------------
   procedure Self_Test (C: in out Remote_Camera'Class) is
      TC_Dummy_Depth : constant Depth_Of_Field := 23;
      TC_Dummy_Speed : constant Shutter_Speed  := Four_Hundred;
   begin

      -- Test focus at various depths:
      Focus(C, TC_Dummy_Depth);
      -- ...Additional calls to Focus.

      -- Test various shutter speeds:
      Set_Shutter_Speed(C, TC_Dummy_Speed);
      -- ...Additional calls to Set_Shutter_Speed.

   end Self_Test;

end F392D00;
