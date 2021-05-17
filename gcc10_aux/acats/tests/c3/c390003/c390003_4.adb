
----------------------------------------------------------------- C390003_4

with Report, Ada.Tags;
package body C390003_4 is -- James_Bond

  function "="(A,B: Ada.Tags.Tag)    return Boolean renames Ada.Tags."=";
  function "="(A,B: Vehicle.TC_Keys) return Boolean renames Vehicle."=";

  procedure TC_Validate( It: Q_Machine; Key: Vehicle.TC_Keys ) is
  begin
    if Key /= Vehicle.Q then
      Report.Failed("Expected Q Key");
    end if;
  end TC_Validate;

end C390003_4;
