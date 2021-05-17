
------------------------------------------------------------------- C390003

with Report;
with C390003_1;
with C390003_2;
with C390003_3;
with C390003_4;
procedure C390003 is

  package Vehicle        renames C390003_1;  use Vehicle;
  package Motivators     renames C390003_2;
  package Special_Trucks renames C390003_3;
  package James_Bond     renames C390003_4;

  -- The cast, in order of complexity:

  Pennys_Bike : Motivators.Bicycle;
  Weekender   : Motivators.Tandem;
  Qs_Moped    : Motivators.Motorcycle;
  Ms_Limo     : Motivators.Car;
  Yard_Van    : Motivators.Truck(8);
  Specter_X   : Special_Trucks.Auto_Carrier;
  Gen_II      : James_Bond.Q_Machine;


  -- Check compatibility with the corresponding class wide type.

  procedure Vehicle_Shop( It  : in out Vehicle.Object'Class;
                          Key : in     Vehicle.TC_Keys ) is

    -- Check that Subtype'Class is defined for tagged subtypes.
    procedure Bike_Shop( Bike: in out Motivators.Bicycle'Class ) is
    begin
        -- Dispatch to appropriate TC_Validate
      Vehicle.TC_Validate( Bike, Key );
    end Bike_Shop;

  begin
    Vehicle.TC_Validate( It, Key );
    if Vehicle.Wheels( It ) = 2 then
      Bike_Shop( It );  -- only call Bike_Shop when It has 2 wheels
    end if;
  end Vehicle_Shop;

begin  -- Main test procedure.

  Report.Test ("C390003", "Check that for a subtype S of a tagged type " &
               "T, S'Class denotes a class-wide subtype.  Check that " &
               "T'Tag denotes the tag of the type T, and that, for a " &
               "class-wide tagged type X, X'Tag denotes the tag of X.  " &
               "Check that the tags of stand alone objects, record and " &
               "array components, aggregates, and formal parameters " &
               "identify their type. Check that the tag of a value of a " &
               "formal parameter is that of the actual parameter, even " &
               "if the actual is passed by a view conversion" );

--     Check that the tags of stand alone objects, record and array
--     components, aggregates, and formal parameters identify their type.
--     Check that the tag of a value of a formal parameter is that of the
--     actual parameter, even if the actual is passed by a view conversion.

  Vehicle_Shop( Pennys_Bike,          Veh );
  Vehicle_Shop( Weekender,            Tand );
  Vehicle_Shop( Qs_Moped,             MC );
  Vehicle_Shop( Ms_Limo,              Car );
  Vehicle_Shop( Yard_Van,             Truk );
  Vehicle_Shop( Specter_X,            Heavy );
  Vehicle_Shop( Specter_X.Payload(1), Car );
  Vehicle_Shop( Gen_II,               Q );
  Vehicle_Shop( Gen_II.Car_Part,      Car );
  Vehicle_Shop( Gen_II.Bike_Part,     MC );

  Vehicle.TC_Validate( Pennys_Bike, Vehicle.Object'Tag );
  Vehicle.TC_Validate( Weekender,   Motivators.Tandem'Tag );
  Vehicle.TC_Validate( Qs_Moped,    Motivators.Motorcycle'Tag );
  Vehicle.TC_Validate( Ms_Limo,     Motivators.Car'Tag );
  Vehicle.TC_Validate( Yard_Van,    Motivators.Truck'Tag );
  Vehicle.TC_Validate( Specter_X,   Special_Trucks.Auto_Carrier'Tag );
  Vehicle.TC_Validate( Specter_X.Payload(1), Motivators.Car'Tag );
  Vehicle.TC_Validate( Gen_II,              James_Bond.Q_Machine'Tag );
  Vehicle.TC_Validate( Gen_II.Car_Part,     Motivators.Car'Tag );
  Vehicle.TC_Validate( Gen_II.Bike_Part,    Motivators.Motorcycle'Tag );

-- Check the tag generated for an aggregate.

  Rentals: declare
    Mikes_Rental : Vehicle.Object'Class :=
                     Vehicle.Object'( 3, (Good, Flat, Worn));
    Diannes_Car  : Vehicle.Object'Class :=
                      Motivators.Tandem'( Wheels      => 2, 
                                          Wheel_State => (Good, Good) );
    Jims_Bike    : Vehicle.Object'Class :=
                      Motivators.Motorcycle'( Pennys_Bike
                                              with Displacement => 350 );
    Bills_Limo   : Vehicle.Object'Class :=
                      Motivators.Car'( Wheels       => 4,
                                       Wheel_State  => (others => Good),
                                       Displacement => 282 );
    Alans_Car    : Vehicle.Object'Class :=
                      Motivators.Truck'( 18, (others => Worn),
                                         Tare => 5_500 );
    Pats_Truck   : Vehicle.Object'Class := Specter_X;
    Keiths_Car   : Vehicle.Object'Class := Gen_II;
    Isaacs_Bus   : Vehicle.Object'Class := Keiths_Car;

  begin
    Vehicle.TC_Validate( Mikes_Rental, Vehicle.Object'Tag );
    Vehicle.TC_Validate( Diannes_Car,  Motivators.Tandem'Tag );
    Vehicle.TC_Validate( Jims_Bike,    Motivators.Motorcycle'Tag );
    Vehicle.TC_Validate( Bills_Limo,   Motivators.Car'Tag );
    Vehicle.TC_Validate( Alans_Car,    Motivators.Truck'Tag );
    Vehicle.TC_Validate( Pats_Truck,   Special_Trucks.Auto_Carrier'Tag );
    Vehicle.TC_Validate( Keiths_Car,   James_Bond.Q_Machine'Tag );
  end Rentals;

-- Check the tag of parameters.
-- Check that the tag is not affected by view conversion.

  Vehicle.TC_Validate( Vehicle.Object( Gen_II  ), James_Bond.Q_Machine'Tag );
  Vehicle.TC_Validate( Vehicle.Object( Ms_Limo ), Motivators.Car'Tag );
  Vehicle.TC_Validate( Motivators.Bicycle( Weekender ),
                       Motivators.Tandem'Tag );
  Vehicle.TC_Validate( Motivators.Bicycle( Gen_II.Bike_Part ),
                       Motivators.Motorcycle'Tag );

  Report.Result;

end C390003;
