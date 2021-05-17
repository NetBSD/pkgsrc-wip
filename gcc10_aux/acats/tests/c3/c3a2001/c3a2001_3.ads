
----------------------------------------------------------------------------

with C3A2001_1,C3A2001_2;
package C3A2001_3 is
  use type C3A2001_1.Status;

  type Ground_Fault is new C3A2001_2.Basic_Breaker with private;

  function Construct( Voltage  : C3A2001_2.Voltages;
                      Amperage : C3A2001_2.Amps )
    return Ground_Fault;

  procedure Set_Trip( The_Breaker : in out Ground_Fault;
                      Capacitance : in     Integer );

private
  type Ground_Fault is new C3A2001_2.Basic_Breaker with record
    Capacitance : Integer;
  end record;
end C3A2001_3;
