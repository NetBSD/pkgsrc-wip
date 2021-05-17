
with Report;
package body C3A0013_3 is

  procedure TC_Validate( It     : Truck;
                         TC_ID  : Character) is
  begin
    if TC_ID /= 'T' then
      Report.Failed("Dispatched to Truck");
    end if;
    if Wheels( It ) /= 3 then
      Report.Failed("Not a Truck");
    end if;
  end TC_Validate;

  function  Gear_Factor( It : Truck ) return Natural is
  begin
    return C3A0013_1.Gear_Factor( C3A0013_1.Vehicle( It ) )*3;
  end Gear_Factor;

end C3A0013_3;
