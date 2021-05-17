

     --==================================================================--


with C831001_Root;
with C831001_0.C831001_1;

with Report;

procedure C831001 is
   Zooming_Camera : C831001_0.Zoom_Camera;
   Auto_Camera1   : C831001_0.C831001_1.Auto_Speed;
   Auto_Camera2   : C831001_0.C831001_1.Auto_Speed;

   TC_Expected_Zoom_Depth : constant C831001_Root.Depth_Of_Field := 83;
   TC_Expected_Auto_Depth : constant C831001_Root.Depth_Of_Field := 83;
   TC_Expected_Depth      : constant C831001_Root.Depth_Of_Field := 83;
   TC_Expected_Dark_Depth : constant C831001_Root.Depth_Of_Field := 52;
   TC_Expected_Zoom_Speed : constant C831001_Root.Shutter_Speed
                          := C831001_Root.Thousandth;
   TC_Expected_Auto_Speed : constant C831001_Root.Shutter_Speed
                          := C831001_Root.Thousandth;
   TC_Expected_Speed      : constant C831001_Root.Shutter_Speed
                          := C831001_Root.Two_Fiftith;
   TC_Expected_Dark_Speed : constant C831001_Root.Shutter_Speed
                          := C831001_Root.Four_Hundredth;

   use type C831001_Root.Depth_Of_Field;
   use type C831001_Root.Shutter_Speed;

begin
   Report.Test ("C831001", "Check that overriding indicators can be used on " &
                "subprogram declarations, including expression functions " &
                "and null procedures");



-- Call the class-wide operation (Self_Test) for Zoom_Camera'Class, which
-- itself calls the class-wide operation for Remote_Camera'Class, which
-- in turn makes dispatching calls to Focus and Set_Shutter_Speed:


   -- For an object of type Zoom_Camera, the dispatching call to Focus should
   -- dispatch to the body explicitly declared for Zoom_Camera. The dispatching
   -- to Set_Shutter_Speed should dispatch to the body declared for
   -- Remote_Camera:

   C831001_0.Self_Test(Zooming_Camera);

   if not C831001_0.TC_Correct_Result (Zooming_Camera,
                                       TC_Expected_Zoom_Depth,
                                       TC_Expected_Zoom_Speed)
   then
      Report.Failed ("Calls dispatched incorrectly for tagged private type");
   end if;

   C831001_0.Set_Exposure(Zooming_Camera, C831001_Root.Dark);

   if not C831001_0.TC_Correct_Result (Zooming_Camera,
                                       TC_Expected_Zoom_Depth,
                                       TC_Expected_Zoom_Speed)
   then
      Report.Failed ("Static call to explicit subprogram executed " &
                     "the wrong body");
   end if;

   if C831001_0.TC_Shutter (Zooming_Camera) /= TC_Expected_Zoom_Speed then
      Report.Failed ("Original Getter not used by dispatching call");
   end if;

   -- For an object of type Auto_Speed, the dispatching call to Focus should
   -- dispatch to the body explicitly declared for Zoom_Camera. The dispatching
   -- call to Set_Shutter_Speed should dispatch to the body explicitly declared
   -- for Remote_Camera:

   C831001_0.Self_Test(Auto_Camera1);

   if not C831001_0.C831001_1.TC_Correct_Result (
             Auto_Camera1,
             TC_Expected_Auto_Depth,
             TC_Expected_Auto_Speed)
   then
      Report.Failed ("Calls dispatched incorrectly for private extension");
   end if;

   -- Call to Self_Test from C831001_0.C831001_1 invokes the dispatching call
   -- to Focus which should dispatch to the body explicitly declared for
   -- Zoom_Camera. The dispatching call to Set_Shutter_Speed should dispatch
   -- to the body explicitly declared for Auto_Speed:

   C831001_0.C831001_1.Self_Test(Auto_Camera2);

   if not C831001_0.C831001_1.TC_Correct_Result (Auto_Camera2,
                                                 TC_Expected_Depth,
                                                 TC_Expected_Speed)
   then
      Report.Failed ("Call to explicit subprogram executed the wrong body");
         -- Note: We use "Pred" in the above to account for the overridden
         -- Getter.
   end if;

   C831001_0.C831001_1.Set_Exposure(Auto_Camera2, C831001_Root.Dark);

   if not C831001_0.C831001_1.TC_Correct_Result (Auto_Camera2,
                                                 TC_Expected_Dark_Depth,
                                                 TC_Expected_Dark_Speed)
   then
      Report.Failed ("Static call to explicit subprogram executed " &
                     "the wrong body");
   end if;

   if C831001_0.TC_Shutter (Auto_Camera2) /=
      C831001_Root.Shutter_Speed'Pred (TC_Expected_Dark_Speed) then
      Report.Failed ("Overridden Getter not used by dispatching call");
   end if;

   Report.Result;

end C831001;
