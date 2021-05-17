
------------------------------------------------------------------- CD30004

with Report;
with CD30004_0;

procedure CD30004 is

begin  -- Main test procedure.

  Report.Test ("CD30004", "Check that the unspecified Size of static " &
               "discrete and fixed point subtypes is the number of bits " &
               "needed to represent each value belonging to the subtype " &
               "using an unbiased representation, where space for a sign " &
               "bit is provided only in the event the subtype contains " &
               "negative values.  Check that for first subtypes " &
               "specified Sizes are supported reflecting this " &
               "representation.");

  CD30004_0.TC_Check_Values;

  CD30004_0.TC_Check_Specified_Sizes;

  Report.Result;

end CD30004;
