

with Report;
with C35A001_0;
procedure C35A001 is

begin  -- Main test procedure.

  Report.Test ("C35A001", "Check that Small can be specified with an " &
                          "aspect specification");

  C35A001_0.TC_Check_Values;

  Report.Result;

end C35A001;
