
----------------------------------------------------------------- C393001_2

with C393001_1;
package C393001_2 is

  type Basic_Breaker is new C393001_1.Breaker with private;

  type Voltages is ( V12, V110, V220, V440 );
  type Amps     is ( A1, A5, A10, A25, A100 );

  function Construct( Voltage : Voltages; Amperage : Amps )
    return Basic_Breaker;

  procedure Flip ( The_Breaker : in out Basic_Breaker );
  procedure Trip ( The_Breaker : in out Basic_Breaker );
  procedure Reset( The_Breaker : in out Basic_Breaker );
private
  type Basic_Breaker is new C393001_1.Breaker with record
    Voltage_Level : Voltages := V110;
    Amperage      : Amps;
  end record;
end C393001_2;
