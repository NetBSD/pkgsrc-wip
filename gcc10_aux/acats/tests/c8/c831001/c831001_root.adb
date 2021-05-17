

     --==================================================================--


package body C831001_Root is

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
      C.Shutter := Thousandth;
   end Set_Shutter_Speed;

   -----------------------------------------------------------
   procedure Self_Test (C: in out Remote_Camera'Class) is
      TC_Dummy_Depth : constant Depth_Of_Field := 23;
      TC_Dummy_Speed : constant Shutter_Speed  := Four_Hundredth;
   begin

      -- Test focus at various depths:
      Focus(C, TC_Dummy_Depth);
      -- ...Additional calls to Focus.

      -- Test various shutter speeds:
      Set_Shutter_Speed(C, TC_Dummy_Speed);
      -- ...Additional calls to Set_Shutter_Speed.

   end Self_Test;

   -----------------------------------------------------------
   procedure TC_Set_Params (C     : in out Remote_Camera;
                            Depth : in     Depth_Of_Field;
                            Speed : in     Shutter_Speed) is
   begin
      C := (DOF => Depth, Shutter => Speed);
   end TC_Set_Params;

end C831001_Root;
