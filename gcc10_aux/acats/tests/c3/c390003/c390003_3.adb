
----------------------------------------------------------------- C390003_3

with Ada.Tags;
with Report;
package body C390003_3 is -- Special_Trucks

  function "="(A,B: Ada.Tags.Tag)    return Boolean renames Ada.Tags."=";
  function "="(A,B: Vehicle.TC_Keys) return Boolean renames Vehicle."=";

  procedure TC_Validate( It: Auto_Carrier; Key: Vehicle.TC_Keys ) is
  begin
    if Key /= Vehicle.Heavy then
      Report.Failed("Expected Heavy Key");
    end if;
  end TC_Validate;

  procedure Load  ( The_Car : in     Motivators.Car;
                    Onto    : in out Auto_Carrier) is
  begin
    Onto.Load_Count := Onto.Load_Count +1;
    Onto.Payload(Onto.Load_Count) := The_Car;
  end Load;
  procedure Unload( The_Car :    out Motivators.Car;
                    Off_of   : in out Auto_Carrier) is
  begin
    The_Car := Off_of.Payload(Off_of.Load_Count);
    Off_of.Load_Count := Off_of.Load_Count -1;
  end Unload;

end C390003_3;
