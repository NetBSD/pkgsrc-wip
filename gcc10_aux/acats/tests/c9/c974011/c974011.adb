

     --==================================================================--


with Report;

with C974011_0;  -- Automated teller machine abstraction.
use  C974011_0;

procedure C974011 is

   Card_Data : ATM_Card_Type;

begin  -- Main program.

   Report.Test ("C974011", "Asynchronous Select: Trigger is queued on a " &
                            "task entry and the abortable part " &
                            "completes first");

   Read_Card (Card_Data);

   declare
      -- Create the task for this transaction
      Keyboard : C974011_0.ATM_Keyboard_Task;    
   begin

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
      
         Keyboard.Cancel_Pressed;      -- Entry call is initially queued, so
                                       -- abortable part starts.
         raise Transaction_Canceled;   -- This would be executed if we
                                       -- completed the rendezvous
      then abort
      
         Validate_Card (Card_Data);
         TC_Abortable_Part_Completed := true;

      end select;

      Perform_Transaction (Card_Data); 


      -- Now clear the entry barrier to allow the rendezvous to complete
      -- if the triggering call has not been cancelled 
      Key_PO.Set (Cancel);
      --
      delay TC_Delay_Time;  -- to allow it all to take place

      if TC_Rendezvous_Entered then 
         Report.Failed ("Triggering Call was not cancelled");
      end if;
      
      abort Keyboard;    -- clean up.  (Note: the task will only exit the
                         -- loop and terminate if the call hanging on the 
                         -- entry is executed.)  

   exception
      when Transaction_Canceled =>
         Report.Failed ("Triggering alternative sequence of statements " &
                           "executed");
      when Others =>
         Report.Failed ("Unexpected exception in the Main");
   end;

   Report.Result;
       
end C974011;
