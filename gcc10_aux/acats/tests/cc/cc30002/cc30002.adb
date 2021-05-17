

     --==================================================================--


with CC30002_0;
with CC30002_1;
with CC30002_2;
with CC30002_3; -- Instance.

with Report;
procedure CC30002 is

   package Speed_Cameras renames CC30002_3;

   use CC30002_0;

   TC_Camera1: Speed_Cameras.Speed_Camera;
   TC_Camera2: Speed_Cameras.Speed_Camera'Class := TC_Camera1;
   TC_Camera3: Speed_Cameras.Speed_Camera;
   TC_Camera4: Speed_Cameras.Speed_Camera;

begin
   Report.Test ("CC30002", "Check that an explicit declaration in the "      &
                "private part of an instance does not override an implicit " &
                "declaration in the instance, unless the corresponding "     &
                "explicit declaration in the generic overrides a "           &
                "corresponding implicit declaration in the generic. Check "  &
                "for primitive subprograms of tagged types");

--
-- Check non-dispatching calls outside instance:
--

   -- Non-overriding primitive operation:

   Speed_Cameras.Set_Shutter_Speed (TC_Camera1);
   if TC_Camera1.TC_Shutter_Called /= Body_Of_Actual then
      Report.Failed ("Wrong body executed: non-dispatching call to " &
                     "Set_Shutter_Speed outside instance");
   end if;


   -- Overriding primitive operation:

   Speed_Cameras.Focus (TC_Camera1);
   if TC_Camera1.TC_Focus_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: non-dispatching call to " &
                     "Focus outside instance");
   end if;


--
-- Check dispatching calls outside instance:
--

   -- Non-overriding primitive operation:

   Speed_Cameras.Set_Shutter_Speed (TC_Camera2);
   if TC_Camera2.TC_Shutter_Called /= Body_Of_Actual then
      Report.Failed ("Wrong body executed: dispatching call to " &
                     "Set_Shutter_Speed outside instance");
   end if;


   -- Overriding primitive operation:

   Speed_Cameras.Focus (TC_Camera2);
   if TC_Camera2.TC_Focus_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: dispatching call to " &
                     "Focus outside instance");
   end if;



--
-- Check non-dispatching calls within instance:
--

   Speed_Cameras.Self_Test_NonDisp (TC_Camera3);

   -- Non-overriding primitive operation:

   if TC_Camera3.TC_Shutter_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: non-dispatching call to " &
                     "Set_Shutter_Speed inside instance");
   end if;

   -- Overriding primitive operation:

   if TC_Camera3.TC_Focus_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: non-dispatching call to " &
                     "Focus inside instance");
   end if;



--
-- Check dispatching calls within instance:
--

   Speed_Cameras.Self_Test_Disp (TC_Camera4);

   -- Non-overriding primitive operation:

   if TC_Camera4.TC_Shutter_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: dispatching call to " &
                     "Set_Shutter_Speed inside instance");
   end if;

   -- Overriding primitive operation:

   if TC_Camera4.TC_Focus_Called /= Body_In_Instance then
      Report.Failed ("Wrong body executed: dispatching call to " &
                     "Focus inside instance");
   end if;

   Report.Result;
end CC30002;
