
--=======================================================================--

with FA11B00.CA11B01_0.CA11B01_1; -- Application_Three_Widget, 
                                  -- implicitly with Application_Two_Widget,
                                  -- implicitly with Application_Three_Widget.
with Report;

procedure CA11B01 is

   package Application_One_Widget renames FA11B00;
   package Application_Two_Widget renames FA11B00.CA11B01_0;
   package Application_Three_Widget renames FA11B00.CA11B01_0.CA11B01_1;

   use Application_One_Widget;
   use Application_Two_Widget;
   use Application_Three_Widget;

begin

   Report.Test ("CA11B01", "Check that a type derived in a public " &
                "child inherits primitive operations from parent");

   Application_One_Subtest:
   declare
      White_Widget : App1_Widget;

   begin
      -- perform an App1_Widget specific operation.
      App1_Widget_Specific_Oper (C => White, L => "Line Editor    ",
                                 The_Widget => White_Widget, I => 10);

      If White_Widget.Color /= White or
        White_Widget.Id /= Widget_ID 
          (Report.Ident_Int (10)) or
            White_Widget.Label  /= "Line Editor    " then
              Report.Failed ("Incorrect result for White_Widget");
      end if;

   end Application_One_Subtest;
   ---------------------------------------------------------------
   Application_Two_Subtest:
   declare
      Amber_Widget : App2_Widget;

   begin
      App1_Widget_Specific_Oper (Amber_Widget, I => 11, 
                                 C => Amber, L => "Alarm_Clock    ");  
                                 -- Inherited from Application_One_Widget.
                                           
      -- perform an App2_Widget specific operation.
      App2_Widget_Specific_Oper (The_Widget => Amber_Widget, Loc => (380,512));

      If Amber_Widget.Color /= Amber or
        Amber_Widget.Id /= Widget_ID (Report.Ident_Int (11)) or
            Amber_Widget.Label  /= "Alarm_Clock    " or
              Amber_Widget.Location /= (380,512) then
                Report.Failed ("Incorrect result for Amber_Widget");
      end if;

   end Application_Two_Subtest;
   ---------------------------------------------------------------
   Application_Three_Subtest:
   declare
      Green_Widget : App3_Widget;

   begin
      App1_Widget_Specific_Oper (Green_Widget, 100, Green, 
                                 "Screen Editor  ");  
                                   -- Inherited (inherited) from Basic_Widget.

      -- perform an App2_Widget specific operation.
      App2_Widget_Specific_Oper (Loc => (1024,760), 
                                 The_Widget => Green_Widget);
                                    -- Inherited from App_1_Widget.

      -- perform an App3_Widget specific operation.
      App3_Widget_Specific_Oper (Green_Widget, S => (100,100));

      If Green_Widget.Color /= Green or
        Green_Widget.Id /= Widget_ID (Report.Ident_Int (100)) or
          Green_Widget.Label  /= "Screen Editor  " or
            Green_Widget.Location /= (1024,760) or
              Green_Widget.Size /= (100,100) then
                Report.Failed ("Incorrect result for Green_Widget");
      end if;

   end Application_Three_Subtest;

   Report.Result;

end CA11B01;
