
with TCTouch;
package body C393001_4 is

  function Construct( Voltage     : C393001_2.Voltages; --------------- i
                      Amperage    : C393001_2.Amps )
    return Special_Breaker is
    It: Special_Breaker;
    procedure Set_Root( It: in out C393001_2.Basic_Breaker ) is
    begin
      It := C393001_2.Construct( Voltage, Amperage );
    end Set_Root;
  begin
    TCTouch.Touch( 'i' );
    Set_Root( C393001_2.Basic_Breaker( It ) );
    Set_Root( It.Backup );
    return It;
  end Construct;

  function Status_Of( It: C393001_1.Breaker ) return C393001_1.Status
    renames C393001_1.Status_Of;

  procedure Flip ( The_Breaker : in out Special_Breaker ) is ---------- j
  begin
    TCTouch.Touch( 'j' );
    case Status_Of( C393001_1.Breaker( The_Breaker )) is
      when C393001_1.Power_Off | C393001_1.Power_On =>
        C393001_2.Flip( C393001_2.Basic_Breaker( The_Breaker ) );
      when others =>
        C393001_2.Flip( The_Breaker.Backup );
    end case;
  end Flip;

  procedure Trip ( The_Breaker : in out Special_Breaker ) is ---------- k
  begin
    TCTouch.Touch( 'k' );
    case Status_Of( C393001_1.Breaker( The_Breaker )) is
      when C393001_1.Power_Off => null;
      when C393001_1.Power_On  =>
        C393001_2.Reset( The_Breaker.Backup );
        C393001_2.Trip( C393001_2.Basic_Breaker( The_Breaker ) );
      when others =>
        C393001_2.Trip( The_Breaker.Backup );
    end case;
  end Trip;

  procedure Reset( The_Breaker : in out Special_Breaker ) is ---------- l
  begin
    TCTouch.Touch( 'l' );
    case Status_Of( C393001_1.Breaker( The_Breaker )) is
      when C393001_1.Tripped  =>
        C393001_2.Reset( C393001_2.Basic_Breaker( The_Breaker ));
      when C393001_1.Failed  =>
        C393001_2.Reset( The_Breaker.Backup );
      when C393001_1.Power_On | C393001_1.Power_Off =>
        null;
    end case;
  end Reset;

  procedure Fail ( The_Breaker : in out Special_Breaker ) is ---------- m
  begin
    TCTouch.Touch( 'm' );
    case Status_Of( C393001_1.Breaker( The_Breaker )) is
      when C393001_1.Failed  =>
        C393001_2.Fail( The_Breaker.Backup );
      when others => 
        C393001_2.Fail( C393001_2.Basic_Breaker( The_Breaker ));
        C393001_2.Reset( The_Breaker.Backup );
    end case;
  end Fail;

  function Status_Of( The_Breaker : Special_Breaker ) ----------------- n
    return C393001_1.Status is
  begin
    TCTouch.Touch( 'n' );
    case Status_Of( C393001_1.Breaker( The_Breaker )) is
      when C393001_1.Power_On  => return C393001_1.Power_On;
      when C393001_1.Power_Off => return C393001_1.Power_Off;
      when others =>
        return C393001_2.Status_Of( The_Breaker.Backup );
    end case;
  end Status_Of;

  function On_Backup( The_Breaker : Special_Breaker ) return Boolean is
    use C393001_2;
    use type C393001_1.Status;
  begin
    return Status_Of(Basic_Breaker(The_Breaker)) = C393001_1.Tripped
        or Status_Of(Basic_Breaker(The_Breaker)) = C393001_1.Failed;
  end On_Backup;

end C393001_4;
