
with Report;
package body C3A0013_2 is

  procedure TC_Validate( It     : Car;
                         TC_ID  : Character ) is
  begin
    if TC_ID /= 'C' then
      Report.Failed("Dispatched to Car");
    end if;
    if Wheels( It ) /= 4 then
      Report.Failed("Not a Car");
    end if;
  end TC_Validate;

  function  Gear_Factor( It : Car ) return Natural is
  begin
    return C3A0013_1.Gear_Factor( C3A0013_1.Vehicle( It ) )*2;
  end Gear_Factor;

end C3A0013_2;
