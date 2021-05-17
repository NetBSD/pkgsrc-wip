
----------------------------------------------------------------- C393010_1

with C393010_1;
package C393010_2 is

  type Charter is new C393010_1.Passenger_Ticket( C393010_1.Coach )
    with private;

  function Issue return Charter;

  -- procedure Print( T: Passenger_Ticket );

private
  type Charter is new C393010_1.Passenger_Ticket( C393010_1.Coach )
    with null record;

  -- Check that the dispatching call to the abstract operation will dispatch
  -- to a procedure defined in the private part of a package.
  procedure Label( T: Charter );

  -- an example of a required function the users shouldn't see:
  function Issue( Service : C393010_1.Service_Classes;
                   Flight : Natural;
                     Seat : String;
                     Meal : C393010_1.Menu ) return Charter;

end C393010_2;
