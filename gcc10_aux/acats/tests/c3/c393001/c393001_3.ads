
with C393001_1,C393001_2;
package C393001_3 is
  
  type Ground_Fault is new C393001_2.Basic_Breaker with private;

  function Construct( Voltage : C393001_2.Voltages; Amperage : C393001_2.Amps
)
    return Ground_Fault;

  procedure Set_Trip( The_Breaker : in out Ground_Fault;
                      Capacitance : in     Integer );

private
  type Ground_Fault is new C393001_2.Basic_Breaker with record
    Capacitance : Integer;
  end record;
end C393001_3;
