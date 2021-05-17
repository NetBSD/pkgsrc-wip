

     --==================================================================--


with Report;

with C974005_0;  -- Automated teller machine abstraction.
use  C974005_0;

procedure C974005 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974005", "ATC: trigger is queued but task terminates" &
                             " before call is serviced");

   Read_Card (Card_Data);

   begin

      declare
         Keyboard : C974005_0.ATM_Keyboard_Task;
      begin

         --                                    --
         -- Asynchronous select is tested here --
         --                                    --

         select
            Keyboard.Cancel_Pressed;      -- Entry call initially queued, so
                                          -- abortable part starts.

                                          -- Tasking_Error raised here when
                                          -- Keyboard completes before entry
                                          -- call can be accepted, and before
                                          -- abortable part completes.

            raise Transaction_Canceled;   -- Should not be executed.
         then abort
            Validate_Card (Card_Data);    -- Keyboard task completes before
                                          -- Keyboard.Cancel_Pressed is
                                          -- accepted, and before this call
                                          -- finishes. Tasking_Error is raised
                                          -- at the point of the entry call,
                                          -- and this call is aborted.
            -- Check that the whole of the abortable part is aborted, not just
            -- the statement in the abortable part that was executing at
            -- the time
            Report.Failed ("Abortable part not aborted");
         end select;
         Perform_Transaction (Card_Data); -- Should not be reached.
      exception
         when Transaction_Canceled =>
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed");
         when Tasking_Error        =>
            if Count = 1234 then
               Report.Failed ("Abortable part did not execute");
            end if;
         when others       =>
            Report.Failed ("Wrong exception raised");
      end;

   exception
      when Tasking_Error        =>
         Report.Failed ("Correct exception raised at wrong level");
      when others       =>
         Report.Failed ("Wrong exception raised at wrong level");
   end;

   Report.Result;

end C974005;
