
------------------------------------------------------------------- C393001

with Report, TCTouch;
with C393001_1, C393001_2, C393001_3, C393001_4;
procedure C393001 is
 
  procedure Flipper( The_Circuit : in out C393001_1.Breaker'Class ) is
  begin
      C393001_1.Flip( The_Circuit );
  end Flipper;

  procedure Tripper( The_Circuit : in out C393001_1.Breaker'Class ) is
  begin
      C393001_1.Trip( The_Circuit );
  end Tripper;

  procedure Restore( The_Circuit : in out C393001_1.Breaker'Class ) is
  begin
      C393001_1.Reset( The_Circuit );
  end Restore;

  procedure Failure( The_Circuit : in out C393001_1.Breaker'Class ) is
  begin
      C393001_1.Fail( The_Circuit );
  end Failure;

  Short : C393001_1.Breaker'Class -- Basic_Breaker
          := C393001_2.Construct( C393001_2.V440, C393001_2.A5 );
  Sharp : C393001_1.Breaker'Class -- Ground_Fault
          := C393001_3.Construct( C393001_2.V110, C393001_2.A1 );
  Shock : C393001_1.Breaker'Class -- Special_Breaker
          := C393001_4.Construct( C393001_2.V12,  C393001_2.A100 );

begin  -- Main test procedure.

  Report.Test ("C393001", "Check that an abstract type can be declared " &
               "and used.  Check actual subprograms dispatch correctly" );

  TCTouch.Validate( "cgcicc", "Declaration" );

  Flipper( Short );
  TCTouch.Validate( "db", "Flipping Short" );
  Flipper( Sharp );
  TCTouch.Validate( "db", "Flipping Sharp" );
  Flipper( Shock );
  TCTouch.Validate( "jbdb", "Flipping Shock" );

  Tripper( Short );
  TCTouch.Validate( "e", "Tripping Short" );
  Tripper( Sharp );
  TCTouch.Validate( "e", "Tripping Sharp" );
  Tripper( Shock );
  TCTouch.Validate( "kbfbe", "Tripping Shock" );

  Restore( Short );
  TCTouch.Validate( "fb", "Restoring Short" );
  Restore( Sharp );
  TCTouch.Validate( "fb", "Restoring Sharp" );
  Restore( Shock );
  TCTouch.Validate( "lbfb", "Restoring Shock" );

  Failure( Short );
  TCTouch.Validate( "a", "Shock Failing" );
  Failure( Sharp );
  TCTouch.Validate( "a", "Shock Failing" );
  Failure( Shock );
  TCTouch.Validate( "mbafb", "Shock Failing" );

  Report.Result;

end C393001;
