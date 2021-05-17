
  --==================================================================--

with Report;
with CDE0003_1;
procedure CDE0003 is

begin
   Report.Test ("CDE0003", "Check that actuals for generic formal " &
                "types and for formal subprograms with formal untagged " &
                "incomplete parameters do not need to be frozen at " &
                "instantiation.");

   if CDE0003_1.Pkg.Call_F (CDE0003_1.Z) /= CDE0003_1.F (CDE0003_1.Z) or else
      CDE0003_1.Pkg.Call_F (CDE0003_1.C) /= CDE0003_1.F (CDE0003_1.C) then
      Report.Failed
        ("Wrong result for generic function call with incomplete type");
   end if;

   CDE0003_1.Pkg.Call_P (CDE0003_1.C);

   if not CDE0003_1.Success then
      Report.Failed
        ("Wrong result for generic procedure call with incomplete type");
   end if;

   Report.Result;
end CDE0003;
