
with Report;
with C452006_A; use C452006_A;
procedure C452006 is

   Lim_One : Lim_Handle := Create (1);

   Lim_Two : Lim_Handle := Create (2);

   Lim_Another_One : Lim_Handle := Create (1);

   Nonlim_One : Nonlim_Handle := Create (1);

   Nonlim_Two : Nonlim_Handle := Create (2);

   Nonlim_Another_One : Nonlim_Handle := Create (1);

begin

   Report.Test
     ("C452006",
      "Check that a membership with a private type whose full type " &
      "is an access type uses the correct equality to evaluate the tests " &
      "for expression choices");

   -- Check that primitive equality works as expected:
   if Lim_One = Lim_Another_One then
      null;
   else
      Report.Failed ("Bad limited equality (1)");
   end if;
   if Lim_One /= Null_Lim_Handle then
      null;
   else
      Report.Failed ("Bad limited equality (2)");
   end if;

   if Nonlim_One = Nonlim_Another_One then
      null;
   else
      Report.Failed ("Bad nonlimited equality (1)");
   end if;
   if Nonlim_One /= Null_Nonlim_Handle then
      null;
   else
      Report.Failed ("Bad nonlimited equality (2)");
   end if;

   -- Simple cases:
   if Lim_One in Lim_One | Lim_Two then
      null; -- OK.
   else
      Report.Failed ("Wrong limited result (3)");
   end if;
   if Nonlim_One not in Nonlim_One | Nonlim_Two then
      Report.Failed ("Wrong nonlimited result (3)");
   else
      null; -- OK.
   end if;

   if Null_Lim_Handle not in Lim_One | Lim_Two then
      null; -- OK.
   else
      Report.Failed ("Wrong limited result (4)");
   end if;
   if Null_Nonlim_Handle in Nonlim_One | Nonlim_Two then
      Report.Failed ("Wrong nonlimited result (4)");
   else
      null; -- OK.
   end if;

   -- Interesting cases:
   if Lim_Another_One in Null_Lim_Handle | Lim_One then
      -- This case was confirmed by AI12-0328-1.
      --Report.Comment ("Limited membership uses primitive equality (5)");
      null; -- OK.
   else
      Report.Failed ("Wrong: limited membership uses predefined equality (5)");
   end if;

   if Nonlim_Another_One not in Null_Nonlim_Handle | Nonlim_One then
      null; -- OK. (Must use predefined equality)
   else
      Report.Failed ("Wrong: nonlimited membership uses " &
                     "primitive equality (5)");
   end if;

   Report.Result;

end C452006;
