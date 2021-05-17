
----------------------------------------------------------------- C390003_1

with Report;
with Ada.Tags;
package body C390003_1 is -- Vehicle

  function "="(A,B: Ada.Tags.Tag) return Boolean renames Ada.Tags."=";

  procedure TC_Validate( It: Object; Key: TC_Keys ) is
  begin
    if Key /= Veh then
      Report.Failed("Expected Veh Key");
    end if;
  end TC_Validate;

  procedure TC_Validate( It: Object'Class; The_Tag: Ada.Tags.Tag ) is
  begin
    if It'Tag /= The_Tag then
      Report.Failed("Unexpected Tag for classwide formal");
    end if;
  end TC_Validate;

  procedure Create( The_Vehicle : in out Object; Tyres : in States ) is
  begin
    The_Vehicle.Wheel_State := ( others => Tyres );
  end Create;

  function  Wheels( The_Vehicle : Object ) return Positive is
  begin
    return The_Vehicle.Wheels;
  end Wheels;

  procedure Rotate( The_Vehicle : in out Object ) is
    Push : States;
    Pulled : States
         := The_Vehicle.Wheel_State(The_Vehicle.Wheel_State'Last);
  begin
    for Finger in
        The_Vehicle.Wheel_State'First..The_Vehicle.Wheel_State'Last loop
      Push := The_Vehicle.Wheel_State(Finger);
      The_Vehicle.Wheel_State(Finger) := Pulled;
      Pulled := Push;
    end loop;
  end Rotate;

end C390003_1; -- Vehicle;
