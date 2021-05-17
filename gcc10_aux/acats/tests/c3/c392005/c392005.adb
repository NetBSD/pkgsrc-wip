

     --==================================================================--


with C392005_0.C392005_1;

with Report;

procedure C392005 is
   Basic_Camera : C392005_0.Remote_Camera;
   Auto_Camera1 : C392005_0.C392005_1.Auto_Speed;
   Auto_Camera2 : C392005_0.C392005_1.Auto_Speed;
   Auto_Depth   : C392005_0.Depth_Of_Field := 67;
   New_Camera1  : C392005_0.C392005_1.New_Camera;
   TC_Expected_Basic_Depth : constant C392005_0.Depth_Of_Field := 46;
   TC_Expected_Auto_Depth  : constant C392005_0.Depth_Of_Field := 57;
   TC_Expected_Basic_Speed : constant C392005_0.Shutter_Speed  
                           := C392005_0.Thousand;
   TC_Expected_Auto_Speed  : constant C392005_0.Shutter_Speed  
                           := C392005_0.Two_Fifty;
   TC_Expected_New_Aper    : constant C392005_0.Aperture 
                           := C392005_0.Sixteen;

   use type C392005_0.Depth_Of_Field;
   use type C392005_0.Shutter_Speed;
   use type C392005_0.Aperture;

begin
   Report.Test ("C392005", "Dispatching for overridden primitive "        &
                "subprograms: private extension declared in child unit, " &
                "parent is tagged private whose full view is tagged record");

-- Call the class-wide operation for Remote_Camera'Class, which itself makes
-- dispatching calls to Focus and Set_Shutter_Speed:


   -- For an object of type Remote_Camera, the dispatching calls should
   -- dispatch to the bodies declared for the root type:
     
   C392005_0.Self_Test(Basic_Camera);

   if C392005_0.TC_Get_Depth (Basic_Camera) /= TC_Expected_Basic_Depth 
     or else C392005_0.TC_Get_Speed (Basic_Camera) /= TC_Expected_Basic_Speed
   then
      Report.Failed ("Calls dispatched incorrectly for root type");
   end if;


   -- For an object of type Auto_Speed, the dispatching calls should
   -- dispatch to the bodies declared for the derived type:
     
   C392005_0.Self_Test(Auto_Camera1);

   if C392005_0.C392005_1.TC_Get_Depth(Auto_Camera1) /= TC_Expected_Auto_Depth

      or
      C392005_0.C392005_1.TC_Get_Speed(Auto_Camera1) /= TC_Expected_Auto_Speed
   then
      Report.Failed ("Calls dispatched incorrectly for derived type");
   end if;

   -- For an object of type Auto_Speed, a non-dispatching call to Focus should

   -- execute the body declared for the derived type (even through it is 
   -- declared in the private part).

   C392005_0.C392005_1.Focus (Auto_Camera2, Auto_Depth);

   if C392005_0.C392005_1.TC_Get_Depth(Auto_Camera2) /= TC_Expected_Auto_Depth

   then
      Report.Failed ("Non-dispatching call to privately overriding " &
                     "subprogram executed the wrong body");
   end if;

   -- For an object of type New_Camera, the initialization using Set_Ap 
   -- should execute the overridden body, not the inherited one.

   if C392005_0.C392005_1.TC_Get_Aper (New_Camera1) /= TC_Expected_New_Aper  
   then
      Report.Failed ("Non-dispatching call to visible overriding " &
                     "subprogram executed the wrong body");
   end if;

   Report.Result;

end C392005;
