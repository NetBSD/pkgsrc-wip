

     --==================================================================--


with Report;
package body C974008_0 is


   procedure Listen_For_Input (Key : out Key_Enum) is
   begin
      -- Simulate the situation where the user presses the cancel key
      -- before the card is validated

      -- press the cancel key immediately
      Key := Cancel;

   end Listen_For_Input;



   -- One of these gets created as "Keyboard" for each transaction
   --
   task body ATM_Keyboard_Task is
      Key_Pressed : Key_Enum := None;
   begin
      -- NOTE:   Normal usage for this routine would be the loop with 
      --         the select statement included.  This particular test
      --         requires that the task be waiting at the accept 
      --         for the call.  To ensure that this is the case the 
      --         extraneous commands are commented out (we leave them
      --         in this form to show the reader the surrounds to the 
      --         fragment of code remaining)
 
      -- loop
                                         
         Listen_For_Input (Key_Pressed); 
                                         
         -- select
            -- when (Key_Pressed = Cancel) =>                 -- Guard is now
               accept Cancel_Pressed do                    -- true, so accept
                  Triggering_Statement_Completed := True;  -- queued entry
               end Cancel_Pressed;                         -- call.

               -- User has cancelled the transaction so we exit the
               -- loop and allow the task to terminate
               -- exit;
         -- else
            -- Key_Pressed := None;
         -- end select;

      -- end loop;
   exception
      when others =>
          Report.Failed ("Unexpected Exception in ATM_Keyboard_Task");
   end ATM_Keyboard_Task;



   procedure Read_Card (Card : in out ATM_Card_Type) is
   begin
      Card.Number := 9999;
      Card.PIN    := 111;
   end Read_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Triggering alternative sequence of statements " &
                     "not executed");
      if not Triggering_Statement_Completed then
         Report.Failed ("Triggering statement did not complete");
      end if;
   end Perform_Transaction;


end C974008_0;
