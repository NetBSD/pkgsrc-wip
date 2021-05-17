
with Report;
with C452005_A;
with C452005_B; use C452005_B;
procedure C452005 is

   use all type C452005_A.Kind_Type;

   use type C452005_A.Nonlim_Data_Type;

   Lim_One : Lim_List := (1 => (Data, 12),
                          others => (Kind => Data_End, Value => <>));

   Lim_Two : Lim_List := (1 => (Data, 15), 2 => (Data, 66),
                          others => (Kind => Data_End, Value => <>));

   Lim_Mess: Lim_List := (1 => (Data, 12), 4 => (Data, 4),
                          others => (Kind => Data_End, Value => <>));

   Nonlim_One : Nonlim_List := (1 => (Data, 12),
                                others => (Kind => Data_End, Value => <>));

   Nonlim_Two : Nonlim_List := (1 => (Data, 15), 2 => (Data, 66),
                                others => (Kind => Data_End, Value => <>));

   Nonlim_Mess: Nonlim_List := (1 => (Data, 12), 4 => (Data, 4),
                                others => (Kind => Data_End, Value => <>));

   Nonlim_Updated : Nonlim_List := Nonlim_One;

begin

   Report.Test
     ("C452005",
      "Check that a membership with a limited array tested type uses " &
      "primitive equality to evaluate the tests for expression choices, " &
      "while a nonlimited array tested type uses predefined equality");

   -- Check that primitive equality works as expected:
   if Lim_One = Lim_Mess then
      null;
   else
      Report.Failed ("Bad limited equality (1)");
   end if;

   if Nonlim_One = Nonlim_Mess then
      null;
   else
      Report.Failed ("Bad nonlimited equality (1)");
   end if;

   Append (Nonlim_Updated, (Data, 66));

   if Nonlim_Updated(2) = (Data, 66) then
      null;
   else
      Report.Failed ("Bad nonlimited append (2)");
   end if;
   if Nonlim_Updated /= Nonlim_Two then
      null;
   else
      Report.Failed ("Bad nonlimited equality(2)");
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

   if Lim_Two not in Lim_One | Lim_Mess then
      null; -- OK.
   else
      Report.Failed ("Wrong limited result (4)");
   end if;
   if Nonlim_Two in Nonlim_One | Nonlim_Mess then
      Report.Failed ("Wrong nonlimited result (4)");
   else
      null; -- OK.
   end if;

   -- Interesting cases:
   if Lim_Mess in Lim_Two | Lim_One then
      null; -- OK. (Must use primitive equality)
   else
      Report.Failed ("Wrong limited result (5)");
   end if;

   if Nonlim_Mess not in Nonlim_Two | Nonlim_One then
      null; -- OK. (Must use predefined equality)
   else
      Report.Failed ("Wrong nonlimited result (5)");
   end if;

   if Nonlim_Updated in Nonlim_One | Nonlim_Two then
      Report.Failed ("Wrong nonlimited result (6)");
   else
      null; -- OK.
   end if;

   Report.Result;

end C452005;
