

     --==================================================================--


with Report;
with ImpDef;

package body C974004_0 is


   procedure Listen_For_Input (Key : out Key_Enum) is
   begin
      -- Simulate the situation where a user waits a bit for the card to
      -- be validated, then presses cancel before it completes.

      -- Delay long enough to force queuing of Keyboard.Cancel_Pressed.
      delay ImpDef.Clear_Ready_Queue;

      if Report.Equal (3, 3) then  -- Always true.
         Key := Cancel;
      end if;
   end Listen_For_Input;


   -- One of these gets created as "Keyboard" for each transaction
   --
   task body ATM_Keyboard_Task is
      Key_Pressed : Key_Enum := None;
   begin
      loop
                                               -- Force entry calls to be
         Listen_For_Input (Key_Pressed);       -- queued, then set guard to
                                               -- true.
         select
            when (Key_Pressed = Cancel) =>     -- Guard is now true, so accept
               accept Cancel_Pressed do        -- queued entry call.
                  null;  --:::: user code for cancel
                  -- Now simulate an unexpected exception arising in the
                  -- user code
                  raise Propagated_From_Task;  -- Propagate an exception.
                  
               end Cancel_Pressed;

               Report.Failed 
                          ("Exception not propagated in ATM_Keyboard_Task");
               
               -- User has canceled the transaction so we exit the
               -- loop and allow the task to terminate
               exit;
         else
            Key_Pressed := None;
         end select;
      end loop;
   exception
      when Propagated_From_Task =>
          null;  -- This is the expected test behavior
      when others =>
          Report.Failed ("Unexpected Exception in ATM_Keyboard_Task");
   end ATM_Keyboard_Task;



   procedure Read_Card (Card : in out ATM_Card_Type) is
   begin
      Card.Number := 9999;
      Card.PIN    := 111;
   end Read_Card;


   procedure Validate_Card (Card : in ATM_Card_Type) is
   begin
      -- Simulate an exceedingly long validation activity.
      loop                                             -- Infinite loop.
         Count := (Count + 1) mod Integer (Card.PIN);
         -- Synch. point to allow transfer of control to Keyboard
         -- task during this simulation
         delay ImpDef.Minimum_Task_Switch;
         exit when not Report.Equal (Count, Count);    -- Always false.
      end loop;
   end Validate_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Exception not re-raised immediately following " &
                     "asynchronous select");
      if Count = 1234 then
         -- Initial value is unchanged
         Report.Failed ("Abortable part did not execute");
      end if;
   end Perform_Transaction;


end C974004_0;
