

     --=================================================--

with CA11019_0,
  -- Main,    
  -- Main.Child is private
     Report;

procedure CA11019 is

   package Main renames CA11019_0;

   Col_1,
   Col_2,
   Col_3 : Main.Data_Collection;

begin

   Report.Test ("CA11019", "Check that body of a (non-generic) package " &
                "may depend on its private generic child");

   -- build a data collection

   for I in 1 .. 10 loop
      Main.Add_1 ( Main.Data_1(I), Col_1);
   end loop;

   if Main.Statistical_Op_1 (Col_1) /= 10 then 
      Report.Failed ("Wrong data_1 value returned");
   end if;

   for I in reverse 10 .. 20 loop
      Main.Add_2 ( Main.Data_2(I * 10), Col_2);
   end loop;

   if Main.Statistical_Op_2 (Col_2) /= 200 then 
      Report.Failed ("Wrong data_2 value returned");
   end if;

   for I in 0 .. 10 loop
      Main.Add_3 ( Main.Data_3(I + 5), Col_3);
   end loop;

   if Main.Statistical_Op_3 (Col_3) /= 15 then 
      Report.Failed ("Wrong data_3 value returned");
   end if;

   Report.Result;

end CA11019;
