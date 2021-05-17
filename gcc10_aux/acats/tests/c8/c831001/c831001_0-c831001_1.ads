

     --==================================================================--


with C831001_Root;
package C831001_0.C831001_1 is

   type Film_Speed is private;

   type Auto_Speed is new Zoom_Camera with private;

   -- Implicit procedure Set_Exposure and
   -- function TC_Correct_Result (Auto_Speed) declared here.

   not overriding
   procedure Set_Shutter_Speed (C     : in out Auto_Speed;
                                Speed : in     C831001_Root.Shutter_Speed);

   -- This version of Set_Shutter_Speed does NOT override the operation
   -- inherited from Zoom_Camera, because the inherited operation is never
   -- visible (and thus, is never implicitly declared) within the immediate
   -- scope of type Auto_Speed.

   procedure Self_Test (C : in out Auto_Speed'Class);

   -- ...Other operations.

private
   type Film_Speed is (One_Hundred, Two_Hundred, Four_Hundredth);

   type Auto_Speed is new Zoom_Camera with record
      ASA : Film_Speed;
   end record;

   -- procedure Focus (C     : in out Auto_Speed;
   --                  Depth : in     C831001_Root.Depth_Of_Field);
   --     Implicitly declared here, along with Get_Depth_of_Field and
   --     Get_Shutter_Speed.)

   overriding
   function Get_Shutter_Speed (C : in Auto_Speed)
      return C831001_Root.Shutter_Speed is
      (C831001_Root.Shutter_Speed'Pred(Get_Shutter_Speed(Zoom_Camera(C))));

   overriding
   procedure Set_Exposure (C : in out Auto_Speed;
                           X : in     C831001_Root.Exposure);

end C831001_0.C831001_1;
