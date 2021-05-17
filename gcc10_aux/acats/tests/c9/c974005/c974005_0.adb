

     --==================================================================--


with Report;
with ImpDef;

package body C974005_0 is


   procedure Listen_For_Input (Key : out Key_Enum) is
   begin
      -- Simulate the situation where a user waits a bit for the card to
      -- be validated, then presses a transaction key (NOT Cancel).

      -- Delay long enough to force queuing of Keyboard.Cancel_Pressed.
      delay ImpDef.Clear_Ready_Queue;

      if Report.Equal (3, 3) then  -- Always true.
         Key := Deposit;           -- Cancel is NOT pressed.
      end if;
   end Listen_For_Input;


   task body ATM_Keyboard_Task is
      Key_Pressed : Key_Enum := None;
   begin

      -- Note: no loop. If the user does not press Cancel, the task completes.
      -- In this model of the keyboard monitor, the user only gets one chance
      -- to cancel the card validation.
                                                            -- Force entry
         Listen_For_Input (Key_Pressed);                    -- calls to be
                                                            -- queued, but do
                                                            -- NOT set guard
                                                            -- to true.
      select
         when (Key_Pressed = Cancel) =>                     -- Guard is false,
            accept Cancel_Pressed do                        -- so entry call
               Report.Failed ("Accept statement executed"); -- remains queued.
            end Cancel_Pressed;
      else                                                  -- Else alternative
         Key_Pressed := None;                               -- executed, then
      end select;                                           -- task ends.
   exception
      when others => 
         Report.Failed ("Unexpected exception in ATM_Keyboard_Task"); 
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

         -- Synch Point to allow transfer of control to Keyboard task
         -- during this simulation
         delay ImpDef.Minimum_Task_Switch;

         exit when not Report.Equal (Count, Count);    -- Always false.
      end loop;
   end Validate_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Exception not re-raised immediately following " &
                     "asynchronous select");
      if Count = 1234 then
         -- Additional analysis added to aid developers
         Report.Failed ("Abortable part did not execute");
      end if;
   end Perform_Transaction;


end C974005_0;
