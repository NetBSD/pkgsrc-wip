
with CA21002_Pure2, CA21002_Preelab2, Report;
procedure CA21002 is
   Val : Integer := Report.Ident_Int (4);
begin
   Report.Test ("CA21002", "Check that the categorization aspects Pure and " &
                           "Preelaborate can be specified by a constant in " &
                           "another package. Check that the categorization " &
                           "aspects Pure and Preelaborate can specified as " &
                           "False, in which case they have no effect");

   CA21002_Preelab2.Hex (Val);
   if Val /= 24 then
      Report.Failed ("Wrong result - Hex (1)");
   end if;

   Val := CA21002_Pure2.Quad (12);
   if Val /= 48 then
      Report.Failed ("Wrong result - Quad (1)");
   end if;

   Val := Report.Ident_Int (52);
   CA21002_Preelab2.Hex (Val);
   if Val /= 312 then
      Report.Failed ("Wrong result - Hex (2)");
   end if;

   Report.Result;
end CA21002;
