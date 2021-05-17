
----------------------------------------------------------------------------

with Report;
with TCTouch;
with C3A2001_5;
procedure C3A2001 is

begin  -- Main test procedure.

  Report.Test ("C3A2001", "Check that an abstract type can be declared " &
               "and used.  Check actual subprograms dispatch correctly" );

  -- This Validate call must be _after_ the call to Report.Test
  TCTouch.Validate( "cgcicc", "Adding" );

  C3A2001_5.Flipper( C3A2001_5.Short );
  TCTouch.Validate( "jbdbdbdb", "Flipping" );

  C3A2001_5.Tripper( C3A2001_5.Short );
  TCTouch.Validate( "kbfbeee", "Tripping" );

  C3A2001_5.Restore( C3A2001_5.Short );
  TCTouch.Validate( "lbfbfbfb", "Restoring" );

  C3A2001_5.Failure( C3A2001_5.Short );
  TCTouch.Validate( "mbafbaa", "Circuits Failing" );

  Report.Result;

end C3A2001;
