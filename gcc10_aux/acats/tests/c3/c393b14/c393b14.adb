 -- Alert_Foundation.Public_Child

--=======================================================================--

with Report;
with F393B00.C393B14_1;
procedure C393B14 is
 -- Alert_Foundation.Public_Child;

begin
  Report.Test ("C393B14", "Check that an extended type can be derived " &
                          "from an abstract type");

  F393B00.C393B14_1.Init;
  if not F393B00.C393B14_1.Check_Before then 
    Report.Failed ("Wrong initialization");
  end if;

  F393B00.C393B14_1.Modify;
  if not F393B00.C393B14_1.Check_After then
    Report.Failed ("Wrong results from Handle");
  end if;

  Report.Result;
end C393B14;
