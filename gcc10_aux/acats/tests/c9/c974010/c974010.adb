

     --==================================================================--


with Report;
with ImpDef;

with C974010_0;  -- Automated teller machine abstraction.
use  C974010_0;

procedure C974010 is

   Card_Data : ATM_Card_Type;
   TC_Tasking_Error_Handled : Boolean := false;

begin  -- Main program.

   Report.Test ("C974010", "Asynchronous Select: Trigger is a call to a " &
                           "task entry of a task that is already completed");


   declare
      -- Create the task for this transaction
      Keyboard : C974010_0.ATM_Keyboard_Task;
   begin

      -- Ensure the task is already completed before calling
      --
      while not Keyboard'terminated loop
         delay ImpDef.Minimum_Task_Switch;
      end loop;

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
 
         Keyboard.Cancel_Pressed;

         raise Transaction_Canceled;  -- Should not be executed.

      then abort

         -- Since the triggering call is not queued the abortable part
         -- should not be executed.
         --
         Validate_Card (Card_Data);  

      end select;
      --
      -- The propagated exception is re-raised here.

      Perform_Transaction(Card_Data); -- Should not be reached.

   exception
      when Transaction_Canceled =>
         Report.Failed ("Triggering alternative sequence of statements " &
                        "executed");
      when Tasking_Error =>
         -- This is the expected test path
         TC_Tasking_Error_Handled := true;
      when others       =>
         Report.Failed ("Wrong exception raised: ");
   end;

   
   if not TC_Tasking_Error_Handled then
      Report.Failed ("Tasking_Error not properly propagated");
   end if;

   Report.Result;

exception
   when Tasking_Error =>
        Report.Failed ("Tasking_Error propagated to wrong handler");
        Report.Result;


end C974010;
