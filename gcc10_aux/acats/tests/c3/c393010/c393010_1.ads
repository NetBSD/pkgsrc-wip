
----------------------------------------------------------------- C393010_1

with C393010_0;
package C393010_1 is

  type Service_Classes is (First, Business, Coach);

  type Menu is (Steak, Lobster, Fowl, Vegan);

  -- Check that an extended type can be derived from an abstract type.
  type Passenger_Ticket(Service : Service_Classes) is
    new C393010_0.Ticket with record
      Row_Seat : String(1..3);
      case Service is
        when First | Business => Meal : Menu;
        when Coach => null;
      end case;
  end record;

  function Issue return Passenger_Ticket;
  function Issue( Service : Service_Classes;
                   Flight : Natural;
                     Seat : String;
                     Meal : Menu := Fowl ) return Passenger_Ticket;

  procedure Label( T: Passenger_Ticket );

  procedure Print( T: Passenger_Ticket );

end C393010_1;
