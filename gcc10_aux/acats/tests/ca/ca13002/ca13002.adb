
     --==================================================================--

with CA13002_0.CA13002_1.CA13002_5;     -- Terminal_Driver.VT100.Cursor_Up,
                                        -- implicitly with parent, CA13002_0.
with CA13002_0.CA13002_2.CA13002_5;     -- Terminal_Driver.IBM3270.Cursor_Up.
with CA13002_0.CA13002_3;               -- Terminal_Driver.DOS_ANSI.
with CA13002_0.CA13002_4;               -- Terminal_Driver.WYSE.
with Report;
use  CA13002_0;                         -- All primitive subprograms directly
                                        -- visible.

procedure CA13002 is
   Expected_Calls : constant CA13002_0.TC_Calls_Arr 
                  := ((true,  false, false, false),
                      (false, true , false, false),
                      (false, false, true , false),
                      (false, false, false, true ));
begin
   Report.Test ("CA13002", "Check that two library units and/or subunits " &
                "may have the same simple names if they have distinct " &
                "expanded names");

   -- Note that the leaves all have the same name.
   -- Call the first grandchild.
   CA13002_0.CA13002_1.CA13002_5;       

   -- Call the second grandchild.
   CA13002_0.CA13002_2.CA13002_5;

   -- Call the first subunit.
   CA13002_0.CA13002_3.CA13002_5;

   -- Call the second subunit.
   CA13002_0.CA13002_4.CA13002_5;

   if TC_Calls /= Expected_Calls then
      Report.Failed ("Wrong result");
   end if;  

   Report.Result;

end CA13002;
