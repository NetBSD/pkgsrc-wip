
----------------------------------------------------------------------------

with TCTouch;
package body C3A2001_3 is

  function Construct( Voltage  : C3A2001_2.Voltages;
                      Amperage : C3A2001_2.Amps )
    return Ground_Fault is
  begin
    TCTouch.Touch( 'g' ); --------------------------------------------- g
    return ( C3A2001_2.Construct( Voltage, Amperage )
             with Capacitance => 0 );
  end Construct;


  procedure Set_Trip( The_Breaker : in out Ground_Fault;
                      Capacitance : in     Integer ) is
  begin
    TCTouch.Touch( 'h' ); --------------------------------------------- h
    The_Breaker.Capacitance := Capacitance;
  end Set_Trip;

end C3A2001_3;
