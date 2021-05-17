 
 with Report;
 with C393007_0;
 with C393007_1;
   -- Alert_system;
 
 procedure C393007 is
   use C393007_0;
   use C393007_1;
 
   Alert_One : C393007_1.Normal_Alert_Type;
 
 begin
   Report.Test ("C393007", "Check that an extended type can be derived " &
                           "from an abstract type");
 
   Handle (Alert_One);
   if not Correct_Time_Stamp (Alert_One) then
     Report.Failed ("Wrong results from procedure Handle");
   end if;
 
   if Log_File /=1 then 
     Report.Failed ("Wrong results");
   end if;
 
   Report.Result;
 
 end C393007;
