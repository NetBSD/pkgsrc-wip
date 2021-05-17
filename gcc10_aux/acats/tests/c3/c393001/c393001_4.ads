
----------------------------------------------------------------- C393001_4

with C393001_1, C393001_2;
package C393001_4 is

  type Special_Breaker is new C393001_2.Basic_Breaker with private;

  function Construct( Voltage     : C393001_2.Voltages;
                      Amperage    : C393001_2.Amps )
    return Special_Breaker;

  procedure Flip ( The_Breaker : in out Special_Breaker );
  procedure Trip ( The_Breaker : in out Special_Breaker );
  procedure Reset( The_Breaker : in out Special_Breaker );
  procedure Fail ( The_Breaker : in out Special_Breaker );

  function Status_Of( The_Breaker : Special_Breaker ) return C393001_1.Status;
  function On_Backup( The_Breaker : Special_Breaker ) return Boolean;

private
  type Special_Breaker is new C393001_2.Basic_Breaker with record
    Backup : C393001_2.Basic_Breaker;
  end record;
end C393001_4;
