

     --==================================================================--


package body C831001_0 is

   procedure Focus (C     : in out Zoom_Camera;
                    Depth : in     C831001_Root.Depth_Of_Field) is
   begin
      -- Artificial for testing purposes.
      TC_Set_Params (C, 83, Get_Shutter_Speed (C));
   end Focus;

   -----------------------------------------------------------
   -- Indirect call to C831001_Root.Self_Test since the main does not know
   -- that Zoom_Camera is a private extension of C831001_Root.Basic_Camera.
   procedure Self_Test (C : in out Zoom_Camera'Class) is
   begin
      C831001_Root.Self_Test (C);
      -- ...Additional self-testing.
   end Self_Test;

   -----------------------------------------------------------
   function TC_Correct_Result (C : Zoom_Camera;
                               D : C831001_Root.Depth_Of_Field;
                               S : C831001_Root.Shutter_Speed)
             return Boolean is
      use type C831001_Root.Depth_Of_Field;
      use type C831001_Root.Shutter_Speed;
   begin
      return (Get_Depth_of_Field(C) = D and Get_Shutter_Speed(C) = S);
   end TC_Correct_Result;

end C831001_0;
