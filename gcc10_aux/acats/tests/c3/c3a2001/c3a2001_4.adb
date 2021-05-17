
----------------------------------------------------------------------------

with TCTouch;
package body C3A2001_4 is

  function Construct( Voltage     : C3A2001_2.Voltages;
                      Amperage    : C3A2001_2.Amps )
    return Special_Breaker is
    It: Special_Breaker;
    procedure Set_Root( It: in out C3A2001_2.Basic_Breaker ) is
    begin
      It := C3A2001_2.Construct( Voltage, Amperage );
    end Set_Root;
  begin
    TCTouch.Touch( 'i' ); --------------------------------------------- i
    Set_Root( C3A2001_2.Basic_Breaker( It ) );
    Set_Root( It.Backup );
    return It;
  end Construct;

  function Status_Of( It: C3A2001_1.Breaker ) return C3A2001_1.Status
    renames C3A2001_1.Status_Of;

  procedure Flip ( The_Breaker : in out Special_Breaker ) is
  begin
    TCTouch.Touch( 'j' ); --------------------------------------------- j
    case Status_Of( C3A2001_1.Breaker( The_Breaker )) is
      when C3A2001_1.Power_Off | C3A2001_1.Power_On =>
        C3A2001_2.Flip( C3A2001_2.Basic_Breaker( The_Breaker ) );
      when others =>
        C3A2001_2.Flip( The_Breaker.Backup );
    end case;
  end Flip;

  procedure Trip ( The_Breaker : in out Special_Breaker ) is
  begin
    TCTouch.Touch( 'k' ); --------------------------------------------- k
    case Status_Of( C3A2001_1.Breaker( The_Breaker )) is
      when C3A2001_1.Power_Off => null;
      when C3A2001_1.Power_On  =>
        C3A2001_2.Reset( The_Breaker.Backup );
        C3A2001_2.Trip( C3A2001_2.Basic_Breaker( The_Breaker ) );
      when others =>
        C3A2001_2.Trip( The_Breaker.Backup );
    end case;
  end Trip;

  procedure Reset( The_Breaker : in out Special_Breaker ) is
  begin
    TCTouch.Touch( 'l' ); --------------------------------------------- l
    case Status_Of( C3A2001_1.Breaker( The_Breaker )) is
      when C3A2001_1.Tripped  =>
        C3A2001_2.Reset( C3A2001_2.Basic_Breaker( The_Breaker ));
      when C3A2001_1.Failed  =>
        C3A2001_2.Reset( The_Breaker.Backup );
      when C3A2001_1.Power_On | C3A2001_1.Power_Off =>
        null;
    end case;
  end Reset;

  procedure Fail ( The_Breaker : in out Special_Breaker ) is
  begin
    TCTouch.Touch( 'm' ); --------------------------------------------- m
    case Status_Of( C3A2001_1.Breaker( The_Breaker )) is
      when C3A2001_1.Failed  =>
        C3A2001_2.Fail( The_Breaker.Backup );
      when others => 
        C3A2001_2.Fail( C3A2001_2.Basic_Breaker( The_Breaker ));
        C3A2001_2.Reset( The_Breaker.Backup );
    end case;
  end Fail;

  function Status_Of( The_Breaker : Special_Breaker )
    return C3A2001_1.Status is
  begin
    TCTouch.Touch( 'n' ); --------------------------------------------- n
    case Status_Of( C3A2001_1.Breaker( The_Breaker )) is
      when C3A2001_1.Power_On  => return C3A2001_1.Power_On;
      when C3A2001_1.Power_Off => return C3A2001_1.Power_Off;
      when others =>
        return C3A2001_2.Status_Of( The_Breaker.Backup );
    end case;
  end Status_Of;

  function On_Backup( The_Breaker : Special_Breaker ) return Boolean is
    use C3A2001_2;
    use type C3A2001_1.Status;
  begin
    return Status_Of(Basic_Breaker(The_Breaker)) = C3A2001_1.Tripped
        or Status_Of(Basic_Breaker(The_Breaker)) = C3A2001_1.Failed;
  end On_Backup;

end C3A2001_4;
