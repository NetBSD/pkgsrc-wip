
     --==================================================================--

with FA13A00_1.CA13A02_4;         -- Outside Elevator Button Operations
                                  -- implicitly with Basic Elevator
                                  -- Operations
with Report;

procedure CA13A02 is

begin

   Report.Test ("CA13A02", "Check that subunits declared in generic child " &
                "units of a public parent have the same visibility into " & 
                "its parent, its parent's siblings, and packages on " &
                "which its parent depends");

-- Going from floor one to penthouse.

   Going_To_Penthouse:
   declare
      -- Declare instance of the child generic elevator package for penthouse.
 
      package Call_Elevator_Pkg is new FA13A00_1.CA13A02_4 
        (FA13A00_1.Penthouse);

      use Call_Elevator_Pkg;

      Call_Button_Light : Light;

   begin

      Call_Button_Light := Call_Elevator (Express);

      if not FA13A00_1.TC_Operation or Call_Button_Light /= Express then
         Report.Failed ("Incorrect elevator operation going to penthouse");
      end if;

   end Going_To_Penthouse;

-- Going from penthouse to basement.

   Going_To_Basement:
   declare
      -- Declare instance of the child generic elevator package for basement.
 
      package Call_Elevator_Pkg is new FA13A00_1.CA13A02_4 
        (FA13A00_1.Basement);

      use Call_Elevator_Pkg;

      Call_Button_Light : Light;

   begin

      Call_Button_Light := Call_Elevator (Down);

      if not FA13A00_1.TC_Operation or Call_Button_Light /= Down then
         Report.Failed ("Incorrect elevator operation going to basement");
      end if;

   end Going_To_Basement;
  
-- Going from basement to floor three.

   Going_To_Floor3:
   declare
      -- Declare instance of the child generic elevator package for floor 
      -- three.
 
      package Call_Elevator_Pkg is new FA13A00_1.CA13A02_4 
        (FA13A00_1.Floor3);

      use Call_Elevator_Pkg;

      Call_Button_Light : Light;

   begin

      Call_Button_Light := Call_Elevator (Up);

      if not FA13A00_1.TC_Operation or Call_Button_Light /= Up then
         Report.Failed ("Incorrect elevator operation going to floor 3");
      end if;

   end Going_To_Floor3;
  
-- Going from floor three to floor two.

   Going_To_Floor2:
   declare
      -- Declare instance of the child generic elevator package for floor two.
 
      package Call_Elevator_Pkg is new FA13A00_1.CA13A02_4 
        (FA13A00_1.Floor2);

      use Call_Elevator_Pkg;

      Call_Button_Light : Light;

   begin

      Call_Button_Light := Call_Elevator (Up);

      if not FA13A00_1.TC_Operation or Call_Button_Light /= Up then
         Report.Failed ("Incorrect elevator operation going to floor 2");
      end if;

   end Going_To_Floor2;
  
-- Going to floor one.

   Going_To_Floor1:
   declare
      -- Declare instance of the child generic elevator package for floor one.
 
      package Call_Elevator_Pkg is new FA13A00_1.CA13A02_4 
        (FA13A00_1.Floor1);

      use Call_Elevator_Pkg;

      Call_Button_Light : Light;

   begin
      -- Calling elevator from floor one.

      FA13A00_1.Current_Floor := FA13A00_1.Floor1;

      Call_Button_Light := Call_Elevator (Down);

      if not FA13A00_1.TC_Operation or Call_Button_Light /= Down then
         Report.Failed ("Incorrect elevator operation going to floor 1");
      end if;

   end Going_To_Floor1;

   Report.Result;

end CA13A02;
