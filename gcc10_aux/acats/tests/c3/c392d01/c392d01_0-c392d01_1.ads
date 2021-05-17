

     --==================================================================--


with F392D00;
package C392D01_0.C392D01_1 is

   type Film_Speed is private;

   type Auto_Speed is new Zoom_Camera with private;

   -- Implicit function TC_Correct_Result (Auto_Speed) declared here.

   procedure Set_Shutter_Speed (C     : in out Auto_Speed;     
                                Speed : in     F392D00.Shutter_Speed); 

   -- This version of Set_Shutter_Speed does NOT override the operation
   -- inherited from Zoom_Camera, because the inherited operation is never
   -- visible (and thus, is never implicitly declared) within the immediate
   -- scope of type Auto_Speed.

   procedure Self_Test (C : in out Auto_Speed'Class);

   -- ...Other operations.

private
   type Film_Speed is (One_Hundred, Two_Hundred, Four_Hundred);

   type Auto_Speed is new Zoom_Camera with record
      ASA : Film_Speed;
   end record;

   -- procedure Focus (C     : in out Auto_Speed;                -- Implicitly
   --                  Depth : in     F392D00.Depth_Of_Field);   -- declared
                                                                 -- here.

end C392D01_0.C392D01_1;
