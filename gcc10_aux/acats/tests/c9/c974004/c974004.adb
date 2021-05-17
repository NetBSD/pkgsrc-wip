

     --==================================================================--


with Report;

with C974004_0;  -- Automated teller machine abstraction.
use  C974004_0;

procedure C974004 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974004", "Asynchronous Select: Trigger is queued on a " &
                           "task entry and is completed first by an " &
                           "exception");

   Read_Card (Card_Data);

   begin

      declare
         -- Create the task for this transaction
         Keyboard : C974004_0.ATM_Keyboard_Task;
      begin

         --                                    --
         -- Asynchronous select is tested here --
         --                                    --

         select
            Keyboard.Cancel_Pressed;     -- Entry call initially queued, so
                                         -- abortable part starts.

            raise Transaction_Canceled;  -- Should not be executed.
         then abort
            Validate_Card (Card_Data);   -- Keyboard.Cancel_Pressed is accepted
                                         -- and propagates an exception before
                                         -- this call finishes; it is then
                                         -- aborted.

            -- Check that the whole of the abortable part is aborted, not
            -- just the statement in the abortable part that was executing
            -- at the time
            Report.Failed ("Abortable part not aborted");
         end select;
                                         -- The propagated exception is
                                         -- re-raised here; control passes to
                                         -- the exception handler.

         Perform_Transaction(Card_Data); -- Should not be reached.
      exception
         when Transaction_Canceled =>
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed");
         when Propagated_From_Task =>
            -- This is the expected test path
            if Count = 1234 then
               -- Initial value is unchanged
               Report.Failed ("Abortable part did not execute");
            end if;
         when Tasking_Error  =>
            Report.Failed ("Tasking_Error raised");
         when others  =>
            Report.Failed ("Wrong exception raised"); 
      end;

   exception
      when Propagated_From_Task =>
         Report.Failed ("Correct exception raised at wrong level");
      when  others  =>
         Report.Failed ("Wrong exception raised at wrong level");
   end;

   Report.Result;

end C974004;
