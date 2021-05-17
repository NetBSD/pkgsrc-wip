
with TCTouch;
package body C393010_2 is

  procedure Label( T: Charter ) is
  begin
    -- Appropriate_IO.Put( "Excursion Fare" );
    TCTouch.Touch('X'); -------------------------------------------------- X
  end Label;

  Num : Natural := 4000;

  function Issue return Charter is
  begin
    Num := Num +1;
    return Charter'(Service => C393010_1.Coach, Flight => 1001,
                       Row_Seat => "OPN", Serial_Number => Num );
  end Issue;

  function Issue( Service : C393010_1.Service_Classes;
                   Flight : Natural;
                     Seat : String;
                     Meal : C393010_1.Menu ) return Charter is
  begin
    return Issue;
  end Issue;

end C393010_2;
