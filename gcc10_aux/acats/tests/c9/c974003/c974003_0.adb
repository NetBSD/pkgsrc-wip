

     --==================================================================--


with Report;
with ImpDef;

package body C974003_0 is


   procedure Listen_For_Input (Key : out Key_Enum) is
   begin
      -- Model the situation where the user waits a bit for the card to
      -- be validated, then presses cancel before it completes.

      -- Delay long enough to force queuing of Keyboard.Cancel_Pressed.
      delay ImpDef.Minimum_Task_Switch;

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
                                                           -- Force entry calls
         Listen_For_Input (Key_Pressed);                   -- to be queued,
                                                           -- then set guard to
                                                           -- true.
         select
            when (Key_Pressed = Cancel) =>                 -- Guard is now
               accept Cancel_Pressed do                    -- true, so accept
                  TC_Triggering_Statement_Completed := True;  -- queued entry
               end Cancel_Pressed;                         -- call.

               -- User has cancelled the transaction so we exit the
               -- loop and allow the task to terminate
               exit;
         else
            Key_Pressed := None;
         end select;

      end loop;
   exception
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
         TC_Count := (TC_Count + 1) mod Integer (Card.PIN);
         -- Synch. point to allow transfer of control to Keyboard
         -- task during this simulation
         delay ImpDef.Minimum_Task_Switch;
         exit when not Report.Equal (TC_Count, TC_Count);    -- Always false.
      end loop;
   end Validate_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Triggering alternative sequence of statements " &
                     "not executed");
      if not TC_Triggering_Statement_Completed then
         Report.Failed ("Triggering statement did not complete");
      end if;
      if TC_Count = 1234 then
         -- Initial value is unchanged
         Report.Failed ("Abortable part did not execute");
      end if;
   end Perform_Transaction;


end C974003_0;
