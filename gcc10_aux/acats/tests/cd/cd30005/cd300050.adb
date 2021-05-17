
------------------------------------------------------------------- CD300050

with Report;
with CD30005_0;

procedure CD300050 is

begin  -- Main test procedure.

  Report.Test ("CD30005",
               "Check that Address clauses are supported for imported " &
               "subprograms" );
   
--      Check that Address clauses are supported for imported subprograms.

  CD30005_0.TC_Check_Imports;

  Report.Result;

end CD300050;
