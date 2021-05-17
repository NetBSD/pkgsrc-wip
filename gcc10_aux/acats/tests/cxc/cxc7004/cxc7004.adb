

with CXC7004_0;
with Report;
procedure CXC7004 is
   V : Integer;
begin
   Report.Test ("CXC7004", "Check that Ada.Task_Identification.Is_Callable " &
                "returns the correct results for the environment task");
   delay 2.5;
   V := 2;
   CXC7004_0.Operate_On_It (V);
   if V /= 4 then
      Report.Failed ("Incorrect result returned from Operate_On_It");
   end if;
   delay 2.5;
   -- Now, let the main subprogram exit. It should start waiting for the
   -- task in the body of CXC7004_0. The test's result is reported by that
   -- task.

end CXC7004;
