-----------------------------------------------------------------------------

with Report;

with C3A0009_0, C3A0009_1; 
with TCTouch;
procedure C3A0009 is

   package Push_Buttons    renames C3A0009_0;
   package Emergency_Items renames C3A0009_1;
      
   Black_Button : Push_Buttons.Alert_Button;
   Alert_Ptr    : Push_Buttons.Button_Action_Ptr;

begin

   Report.Test ("C3A0009", "Check that subprogram references may be passed "
                         & "as parameters using access-to-subprogram types. "
                         & "Check that the passed subprograms may be "
                         & "invoked from within the called subprogram");


   Push_Buttons.Push( Black_Button );
   Push_Buttons.Alert( Black_Button ).all;

   TCTouch.Validate( "PDAd", "Default operation set" );

   -- Call inherited operations Set_Response and Push to set 
   -- Emergency value in the extension.
   Push_Buttons.Set_Response (Black_Button, Emergency_Items.Emergency'Access);
 

   Push_Buttons.Push( Black_Button );
   Push_Buttons.Alert( Black_Button ).all;

   TCTouch.Validate( "SPEAd", "Altered Response set" );

   -- Call primitive operation to set action value in the extension.
   Push_Buttons.Replace_Action( Black_Button );


   Push_Buttons.Push( Black_Button );
   Push_Buttons.Alert( Black_Button ).all;

   TCTouch.Validate( "RPEAr", "Altered Action set" );

   Report.Result;
end C3A0009;
