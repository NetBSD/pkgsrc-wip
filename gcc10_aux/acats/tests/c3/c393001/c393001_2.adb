
with TCTouch;
package body C393001_2 is
  function Construct( Voltage : Voltages; Amperage : Amps ) ----------- c
    return Basic_Breaker is
    It : Basic_Breaker;
  begin
    TCTouch.Touch( 'c' );
    It.Amperage := Amperage;
    It.Voltage_Level := Voltage;
    C393001_1.Set( It, C393001_1.Power_Off );
    return It;
  end Construct;

  procedure Flip ( The_Breaker : in out Basic_Breaker ) is ------------ d
  begin
    TCTouch.Touch( 'd' );
    case Status_Of( The_Breaker ) is
      when C393001_1.Power_Off =>
        C393001_1.Set( The_Breaker, C393001_1.Power_On );
      when C393001_1.Power_On =>
        C393001_1.Set( The_Breaker, C393001_1.Power_Off );
      when C393001_1.Tripped | C393001_1.Failed  => null;
    end case;
  end Flip;

  procedure Trip ( The_Breaker : in out Basic_Breaker ) is ------------ e
  begin
    TCTouch.Touch( 'e' );
    C393001_1.Set( The_Breaker, C393001_1.Tripped );
  end Trip;

  procedure Reset( The_Breaker : in out Basic_Breaker ) is ------------ f
  begin
    TCTouch.Touch( 'f' );
    case Status_Of( The_Breaker ) is
      when C393001_1.Power_Off | C393001_1.Tripped =>
        C393001_1.Set( The_Breaker, C393001_1.Power_On );
      when C393001_1.Power_On  | C393001_1.Failed  => null;
    end case;
  end Reset;

end C393001_2;
