  -- configuration pragmas must occur before the first compilation_unit
  -- of a compilation

------------------------ END OF CONFIGURATION PRAGMAS --------------------

with Report;
package body BA15001_0 is

  procedure Do_Something is
  begin
    Report.Failed( "This message cannot possibly occur" );
  end Do_Something;

end BA15001_0;
