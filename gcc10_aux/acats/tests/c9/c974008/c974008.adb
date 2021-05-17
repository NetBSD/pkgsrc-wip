

     --==================================================================--


with Report;
with ImpDef;

with C974008_0;  -- Automated teller machine abstraction.
use  C974008_0;

procedure C974008 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974008", "Asynchronous Select: Trigger is a call to a " &
                           "waiting task entry and completes immediately");

   Read_Card (Card_Data);

   declare
      -- Create the task for this transaction
      Keyboard : C974008_0.ATM_Keyboard_Task;    
   begin

      -- Ensure task is waiting at the accept
      -- This is the time required to activate another task and allow it
      -- to run to its first accept statement.
      --
      delay ImpDef.Switch_To_New_Task;

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
         Keyboard.Cancel_Pressed;      -- Entry call is executed immediately

         raise Transaction_Canceled;   -- This is executed after Validate_Card
                                       -- is aborted.
      then abort

         -- In other similar tests Validate_Card is called here.  In this 
         -- test we just check to see if the abortable part is called at
         -- all.  Since the triggering call is not queued the abortable 
         -- part should not be started
         --
         Report.Failed ("Abortable part started");

      end select;

      Perform_Transaction (Card_Data); -- Should not be reached.
   exception
      when Transaction_Canceled =>

         if not Triggering_Statement_Completed then
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed but triggering statement not complete");
         end if;

   end;

   Report.Result;

end C974008;
