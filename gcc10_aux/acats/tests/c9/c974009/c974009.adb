

     --==================================================================--


with Report;
with ImpDef;

with C974009_0;  -- Automated teller machine abstraction.
use  C974009_0;

procedure C974009 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974009", "Asynchronous Select: Trigger is a call to a " &
                           "task entry, is not queued and is completed " &
                           "first by an exception");


   begin

      declare
         -- Create the task for this transaction
         Keyboard : C974009_0.ATM_Keyboard_Task;
      begin

         -- Ensure task is waiting a the accept so the call is not queued
         -- This is the time required to activate another task and allow it
         -- to run to its first accept statement
         -- 
         delay ImpDef.Switch_To_New_Task;

         --                                    --
         -- Asynchronous select is tested here --
         --                                    --

         select
 
            Keyboard.Cancel_Pressed;

            raise Transaction_Canceled;  -- Should not be executed.
         then abort
            Validate_Card (Card_Data);   -- Keyboard.Cancel_Pressed is accepted
                                         -- and propagates an exception before
                                         -- this call is executed
         end select;

         -- The propagated exception is re-raised here.
         Perform_Transaction(Card_Data); -- Should not be reached.

      exception
         when Transaction_Canceled =>
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed");
         when Propagated_From_Task =>
            null;  -- This is the expected test path
         when others =>
            Report.Failed ("Wrong exception raised");
      end;

   exception
      when others =>
            Report.Failed ("Unexpected exception raised");
   end;

   Report.Result;

end C974009;
