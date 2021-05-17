
with Report;
with TCTouch;
with C393012_0;
with C393012_1;
procedure C393012 is

  package Rt renames C393012_0;
  package Tx renames C393012_1;

  type Tix is access Rt.Ticket'Class;
  type Itinerary is array(Positive range 1..3) of Tix;

-- Outbound and Inbound itineraries provide different orderings of mixtures
-- of Economy and First_Class.  Not that that should make any difference...

  Outbound : Itinerary := ( 1 => new Tx.Economy'( 5335,  5, 'B' ),
                            2 => new Tx.First'  (   67,  1, 'J', Tx.L ),
                            3 => new Tx.Economy'(  345, 37, 'C' ) );

  Inbound  : Itinerary := ( 1 => new Tx.First'  (  456,  4, 'F', Tx.SN ),
                            2 => new Tx.Economy'(   68, 12, 'D' ),
                            3 => new Tx.Economy'( 5336,  6, 'A' ) );

-- Each call to Display uses a parameter that is a type conversion
-- to the abstract type Ticket.

  procedure TC_Convert( I: Itinerary; Leg1,Leg2,Leg3: String ) is
  begin
    if Rt.Display( Rt.Ticket( I(1).all ) ) /= Leg1 then
      Report.Failed( Rt.Display( Rt.Ticket( I(1).all ) ) & " /= " & Leg1 );
    end if;
    if Rt.Display( Rt.Ticket( I(2).all ) ) /= Leg2 then
      Report.Failed( Rt.Display( Rt.Ticket( I(2).all ) ) & " /= " & Leg2 );
    end if;
    if Rt.Display( Rt.Ticket( I(3).all ) ) /= Leg3 then
      Report.Failed( Rt.Display( Rt.Ticket( I(3).all ) ) & " /= " & Leg3 );
    end if;
  end TC_Convert;

-- Each call to Display uses a parameter that is not a type conversion

  procedure TC_Match( I: Itinerary; Leg1,Leg2,Leg3: String ) is
  begin
    if Rt.Display( I(1).all ) /= Leg1 then
      Report.Failed( Rt.Display( I(1).all ) & " /= " & Leg1 );
    end if;
    if Rt.Display( I(2).all ) /= Leg2 then
      Report.Failed( Rt.Display( I(2).all ) & " /= " & Leg2 );
    end if;
    if Rt.Display( I(3).all ) /= Leg3 then
      Report.Failed( Rt.Display( I(3).all ) & " /= " & Leg3 );
    end if;
  end TC_Match;

begin  -- Main test procedure.

   Report.Test ("C393012", "Check that a non-abstract subprogram of an "
                         & "abstract type can be called with a "
                         & "controlling operand that is a type "
                         & "conversion to the abstract type.  "
                         & "Check that converting to the class-wide type "
                         & "of an abstract type inside an operation of "
                         & "that type causes a redispatch" );

  -- Test conversions to abstract type

   TC_Convert( Outbound, "Fl: 5335 K Seat: 5B",
                         "Fl: 67 FL Seat: 1J",
                         "Fl: 345 K Seat: 37C" );

   TCTouch.Validate( "TeTfTe", "Outbound flight (converted)" );

   TC_Convert( Inbound, "Fl: 456 FSN Seat: 4F",
                        "Fl: 68 K Seat: 12D",
                        "Fl: 5336 K Seat: 6A" );

   TCTouch.Validate( "TfTeTe", "Inbound flight (converted)" );

  -- Test without conversions to abstract type

   TC_Match( Outbound, "Fl: 5335 K Seat: 5B",
                       "Fl: 67 FL Seat: 1J",
                       "Fl: 345 K Seat: 37C" );

   TCTouch.Validate( "ETeFTfETe", "Outbound flight" );

   TC_Match( Inbound, "Fl: 456 FSN Seat: 4F",
                       "Fl: 68 K Seat: 12D",
                       "Fl: 5336 K Seat: 6A" );

   TCTouch.Validate( "FTfETeETe", "Inbound flight" );

   Report.Result;

end C393012;
