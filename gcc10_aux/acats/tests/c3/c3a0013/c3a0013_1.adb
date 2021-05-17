
with Report;
package body C3A0013_1 is

  procedure Create    ( It : in out Vehicle; 
                        Wheels : Natural := 4 ) is
  begin
    It.Wheels   := Wheels;
    It.Speed    := 0;
  end Create;

  procedure Accelerate( It : in out Vehicle ) is
  begin
    It.Speed := It.Speed + Gear_Factor( It.Power_Train.Within.all );
  end Accelerate;

  procedure Decelerate( It : in out Vehicle ) is
  begin
    It.Speed := It.Speed - Gear_Factor( It.Power_Train.Within.all );
  end Decelerate;

  procedure Stop      ( It : in out Vehicle ) is
  begin
    It.Speed := 0;
    It.Power_Train.Engaged := False;
  end Stop;

  function  Gear_Factor( It : Vehicle ) return Natural is
  begin
    return It.Power_Train.Gear;
  end Gear_Factor;

  function  Speed     ( It : Vehicle ) return Natural is
  begin
    return It.Speed;
  end Speed;

  function  Wheels     ( It : Vehicle ) return Natural is
  begin
    return It.Wheels;
  end Wheels;

  -- formal tagged parameters are implicitly aliased

  procedure TC_Validate( It : in out Vehicle; Speed_Trap : Natural ) is
    License: Vehicle_ID := It'Unchecked_Access;
  begin
    if Speed( License.all ) /= Speed_Trap then
      Report.Failed("Speed Trap: expected: " & Natural'Image(Speed_Trap));
    end if;
  end TC_Validate;

  procedure TC_Validate( It     : Vehicle;
                         TC_ID  : Character) is
  begin
    if TC_ID /= 'V' then
      Report.Failed("Dispatched to Vehicle");
    end if;
    if Wheels( It ) /= 1 then
      Report.Failed("Not a Vehicle");
    end if;
  end TC_Validate;

  procedure Up_Shift( It: in out Vehicle ) is
  begin
    It.Power_Train.Gear    := It.Power_Train.Gear +1;
    It.Power_Train.Engaged := True;
    Accelerate( It );
  end Up_Shift;
end C3A0013_1;
