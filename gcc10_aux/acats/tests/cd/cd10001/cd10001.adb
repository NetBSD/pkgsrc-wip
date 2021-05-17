
------------------------------------------------------------------- CD10001

with Report;
with CD10001_0;

procedure CD10001 is

begin  -- Main test procedure.

  Report.Test ("CD10001", "Check that representation items containing " &
                          "nonstatic expressions are supported in the " &
                          "case that the representation item is a name " &
                          "that statically denotes a constant declared " &
                          "before the entity" );

  CD10001_0.TC_Check_Values;

  Report.Result;

end CD10001;
