
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C450001_0 is

  procedure Loop_Check is
    Counter_Check : Natural := 0;
  begin
    for Ever in Unsigned_8_Bit loop
      Counter_Check := Report.Ident_Int(Counter_Check) + 1;
      if Counter_Check > 2**8 then
        Report.Failed("Unsigned_8_Bit loop overrun");
        exit;
      end if;
    end loop;

    if Counter_Check < 2**8 then
      Report.Failed("Unsigned_8_Bit loop underrun");
    end if;

    Counter_Check := 0;

    for Never in Unsigned_Edge_8 loop
      Counter_Check := Report.Ident_Int(Counter_Check) + 1;
      if Counter_Check > Shy_By_One then
        Report.Failed("Unsigned_Edge_8 loop overrun");
        exit;
      end if;
    end loop;

    if Counter_Check < Shy_By_One then
      Report.Failed("Unsigned_Edge_8 loop underrun");
    end if;

    Counter_Check := 0;

    for Getful in reverse Unsigned_Over_8 loop
      Counter_Check := Report.Ident_Int(Counter_Check) + 1;
      if Counter_Check > Heavy_By_Two then
        Report.Failed("Unsigned_Over_8 loop overrun");
        exit;
      end if;
    end loop;

    if Counter_Check < Heavy_By_Two then
      Report.Failed("Unsigned_Over_8 loop underrun");
    end if;

  end Loop_Check;

  function ID( U8B: Unsigned_8_Bit )  return Unsigned_8_Bit is
  begin
    return Unsigned_8_Bit(Report.Ident_Int(Integer(U8B)));
  end ID;

  function ID( UEB: Unsigned_Edge_8 ) return Unsigned_Edge_8 is
  begin
    return Unsigned_Edge_8(Report.Ident_Int(Integer(UEB)));
  end ID;

  function ID( UOB: Unsigned_Over_8 ) return Unsigned_Over_8 is
  begin
    return Unsigned_Over_8(Report.Ident_Int(Integer(UOB)));
  end ID;

end C450001_0;
