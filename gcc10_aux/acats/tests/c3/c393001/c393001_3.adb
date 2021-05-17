
----------------------------------------------------------------- C393001_3

with TCTouch;
package body C393001_3 is

  function Construct( Voltage  : C393001_2.Voltages; ------------------ g
                      Amperage : C393001_2.Amps )
    return Ground_Fault is

    It : Ground_Fault;

    procedure Set_Root( It: in out C393001_2.Basic_Breaker ) is
    begin
      It := C393001_2.Construct( Voltage, Amperage );
    end Set_Root;

  begin
    TCTouch.Touch( 'g' );
    Set_Root( C393001_2.Basic_Breaker( It ) );
    It.Capacitance := 0;
    return It;
  end Construct;

  procedure Set_Trip( The_Breaker : in out Ground_Fault; -------------- h
                      Capacitance : in     Integer ) is
  begin
    TCTouch.Touch( 'h' );
    The_Breaker.Capacitance := Capacitance;
  end Set_Trip;

end C393001_3;
