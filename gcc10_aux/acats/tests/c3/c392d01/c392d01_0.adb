

     --==================================================================--


package body C392D01_0 is

   procedure Focus (C     : in out Zoom_Camera;
                    Depth : in     F392D00.Depth_Of_Field) is
   begin
      -- Artificial for testing purposes.
      C.DOF := 83;
   end Focus;

   -----------------------------------------------------------
   -- Indirect call to F392D00.Self_Test since the main does not know 
   -- that Zoom_Camera is a private extension of F392D00.Basic_Camera.
   procedure Self_Test (C : in out Zoom_Camera'Class) is
   begin
      F392D00.Self_Test (C);
      -- ...Additional self-testing.
   end Self_Test;

   -----------------------------------------------------------
   function TC_Correct_Result (C : Zoom_Camera;
                               D : F392D00.Depth_Of_Field;
                               S : F392D00.Shutter_Speed) return Boolean is
      use type F392D00.Depth_Of_Field;
      use type F392D00.Shutter_Speed;
   begin
      return (C.DOF = D and C.Shutter = S);
   end TC_Correct_Result;

end C392D01_0;
