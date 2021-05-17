
------------------------------------------------------------------- C393B12

with C393B12_1.C393B12_2;
with Report;
procedure C393B12 is

  use type C393B12_1.Status;

  package Alt_Alert renames C393B12_1.C393B12_2;

  GA : Alt_Alert.Generic_Alert_Type;

begin
  Report.Test ("C393B12",  "Check that an extended type can be derived " &
                           "from an abstract type");

  if Alt_Alert.Query_Status (GA) /= C393B12_1.Low then
    Report.Failed ("Wrong initialization");
  end if;

  Alt_Alert.Handle (GA);
  if Alt_Alert.Query_Status (GA) /= C393B12_1.High then
    Report.Failed ("Wrong results from Handle");
  end if;

  Report.Result;

end C393B12;
