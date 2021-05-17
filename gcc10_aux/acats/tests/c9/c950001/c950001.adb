
     --==================================================================--

with C950001_1;
with Report;
procedure C950001 is
   Success : Boolean;
begin
   Report.Test ("C950001", "Check that primitive procedures of synchronized " &
                "interfaces with a Synchronization aspect can be completed " &
                "by a procedure, protected procedure or entry as specified, " &
                "and check correct mutual exclusion");

   begin
      C950001_1.Monitor.Signal_Started;
      C950001_1.Monitor.Wait_Ready (Success);

      if not Success then
         Report.Failed ("Counter did not have expected number of updates");
      end if;

   exception
      when others =>
         Report.Failed ("Unexpected exception");
   end;

   Report.Result;
end C950001;
