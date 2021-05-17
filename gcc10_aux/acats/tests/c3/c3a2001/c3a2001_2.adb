
----------------------------------------------------------------------------

with TCTouch;
package body C3A2001_2 is
  function Construct( Voltage : Voltages; Amperage : Amps )
    return Basic_Breaker is
    It : Basic_Breaker;
  begin
    TCTouch.Touch( 'c' ); --------------------------------------------- c
    It.Amperage := Amperage;
    It.Voltage_Level := Voltage;
    C3A2001_1.Set( It, C3A2001_1.Power_Off );
    return It;
  end Construct;

  procedure Flip ( The_Breaker : in out Basic_Breaker ) is
  begin
    TCTouch.Touch( 'd' ); --------------------------------------------- d
    case Status_Of( The_Breaker ) is
      when C3A2001_1.Power_Off =>
        C3A2001_1.Set( The_Breaker, C3A2001_1.Power_On );
      when C3A2001_1.Power_On =>
        C3A2001_1.Set( The_Breaker, C3A2001_1.Power_Off );
      when C3A2001_1.Tripped | C3A2001_1.Failed  => null;
    end case;
  end Flip;

  procedure Trip ( The_Breaker : in out Basic_Breaker ) is
  begin
    TCTouch.Touch( 'e' ); --------------------------------------------- e
    C3A2001_1.Set( The_Breaker, C3A2001_1.Tripped );
  end Trip;

  procedure Reset( The_Breaker : in out Basic_Breaker ) is
  begin
    TCTouch.Touch( 'f' ); --------------------------------------------- f
    case Status_Of( The_Breaker ) is
      when C3A2001_1.Power_Off | C3A2001_1.Tripped =>
        C3A2001_1.Set( The_Breaker, C3A2001_1.Power_On );
      when C3A2001_1.Power_On  | C3A2001_1.Failed  => null;
    end case;
  end Reset;

end C3A2001_2;
