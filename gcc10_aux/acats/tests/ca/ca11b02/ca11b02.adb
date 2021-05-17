

--=======================================================================--

with FA11B00.CA11B02_0;      -- Application_Two_Widget
                             -- implicitly with Application_One_Widget.
with Report;

procedure CA11B02 is
                             
   package Application_One_Widget renames FA11B00;

   package Application_Two_Widget renames FA11B00.CA11B02_0;

   use Application_One_Widget ;
   use Application_Two_Widget ;

   type Emulator_Widget is new App2_Widget;   -- Derived record of 
                                              -- parent type.

   White_Widget, Amber_Widget : Emulator_Widget;


begin

   Report.Test ("CA11B02", "Check that a type derived in client of a " &
                "public child inherits primitive operations from parent");

   App1_Widget_Specific_Oper (C => White, L => "Line Editor    ",
                              The_Widget => White_Widget, I => 10);
                                  -- Inherited from Application_One_Widget.
   If White_Widget.Color /= White or
     White_Widget.Id /= Widget_ID (Report.Ident_Int (10)) or
     White_Widget.Label  /= "Line Editor    " 
   then
      Report.Failed ("Incorrect result for White_Widget");
   end if;

   -- perform an App2_Widget specific operation.

   App2_Widget_Specific_Op1 (White_Widget, S => (100, 200));

   If White_Widget.Size.X_Length /= 100 or
     White_Widget.Size.Y_Length /= 200
   then
      Report.Failed ("Incorrect size for White_Widget");
   end if;

   App1_Widget_Specific_Oper (Amber_Widget, 5, Amber, "Screen Editor  ");  
                                  -- Inherited from Application_One_Widget.

   -- perform an App2_Widget specific operations.

   App2_Widget_Specific_Op1 (S => (1024,100), The_Widget => Amber_Widget);  
   App2_Widget_Specific_Op2 (Amber_Widget, (1024, 760));

   If Amber_Widget.Color /= Amber or
     Amber_Widget.Id /= Widget_ID (Report.Ident_Int (5)) or 
     Amber_Widget.Label  /= "Screen Editor  " or
     Amber_Widget.Size /= (1024,100) or 
     Amber_Widget.Location.X_Location /= 1024 or
     Amber_Widget.Location.Y_Location /= 760
   then
      Report.Failed ("Incorrect result for Amber_Widget");
   end if;

   Report.Result;

end CA11B02;
