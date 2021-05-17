
with TCTouch;
package body C393010_1 is

  procedure Label( T: Passenger_Ticket ) is
  begin
    -- Appropriate_IO.Put( T.Service );
    TCTouch.Touch('L'); -------------------------------------------------- L
  end Label;

  procedure Print( T: Passenger_Ticket ) is
  begin
    -- call parent print:
    C393010_0.Print( C393010_0.Ticket( T ) );
    case T.Service is
      when First    => -- Appropriate_IO.Put( Meal );
        TCTouch.Touch('F'); ---------------------------------------------- F
      when Business => -- Appropriate_IO.Put( Meal );
        TCTouch.Touch('B'); ---------------------------------------------- B
      when Coach    => -- Appropriate_IO.Put( "BYO" & " peanuts" );
        TCTouch.Touch('C'); ---------------------------------------------- C
    end case;   
  end Print;

  Num : Natural := 1000;

  function Issue( Service : Service_Classes;
                   Flight : Natural;
                     Seat : String;
                     Meal : Menu := Fowl ) return Passenger_Ticket is
  begin
    Num := Num +1;
    case Service is
      when First =>
        return Passenger_Ticket'(Service => First, Flight => Flight,
                       Row_Seat => Seat, Meal => Meal, Serial_Number => Num );
      when Business =>
        return Passenger_Ticket'(Service => Business, Flight => Flight,
                       Row_Seat => Seat, Meal => Meal, Serial_Number => Num );
      when Coach =>
        return Passenger_Ticket'(Service => Coach, Flight => Flight,
                       Row_Seat => Seat, Serial_Number => Num );
    end case;
  end Issue;

  function Issue return Passenger_Ticket is
  begin
    return Issue( Coach, 0, "non" );
  end Issue;

end C393010_1;
