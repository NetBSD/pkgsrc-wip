

     --==================================================================--


with Report;

with C974003_0;  -- Automated teller machine abstraction.
use  C974003_0;

procedure C974003 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974003", "Asynchronous Select: Trigger is queued on a " &
                            "task entry and completes first");

   Read_Card (Card_Data);

   declare
      -- Create the task for this transaction
      Keyboard : C974003_0.ATM_Keyboard_Task;    
   begin

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
         Keyboard.Cancel_Pressed;      -- Entry call is initially queued, so
                                       -- abortable part starts.

         raise Transaction_Canceled;   -- This is executed after Validate_Card
                                       -- is aborted.
      then abort
         Validate_Card (Card_Data);    -- Keyboard.Cancel_Pressed is accepted
                                       -- and completes before this call
                                       -- finishes; it is then aborted.

         -- Check that the whole of the abortable part is aborted, not
         -- just the statement in the abortable part that was executing
         -- at the time
         Report.Failed ("Abortable part not aborted");

      end select;

      Perform_Transaction (Card_Data); -- Should not be reached.
   exception
      when Transaction_Canceled =>
         if not TC_Triggering_Statement_Completed then
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed but triggering statement not complete");
         end if;
         if TC_Count = 1234 then
            -- Initial value is unchanged
            Report.Failed ("Abortable part did not execute");
         end if;
   end;

   Report.Result;

end C974003;
