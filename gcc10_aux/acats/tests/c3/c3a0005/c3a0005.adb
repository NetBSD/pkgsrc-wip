

-----------------------------------------------------------------------------

with TCTouch;
with Report;

with C3A0005_0;

procedure C3A0005 is

   Big_Red_Button : aliased C3A0005_0.Button;

begin

   Report.Test ("C3A0005", "Check that access to subprogram may be "
                         & "stored within data structures, and that the "
                         & "access to subprogram can subsequently be called");

   C3A0005_0.Push (Big_Red_Button'Access);
   TCTouch.Validate("PD", "Using default value");
   TCTouch.Assert( C3A0005_0.Default_Call, "Default Call" );

   -- set Emergency value in Button.Response
   C3A0005_0.Set_Response(Big_Red_Button'Access, C3A0005_0.Emergency'Access);

   C3A0005_0.Push (Big_Red_Button'Access);
   TCTouch.Validate("SPE", "After set to Emergency value");
   TCTouch.Assert( C3A0005_0.Emergency_Call, "Emergency Call");

   Report.Result;

end C3A0005;
