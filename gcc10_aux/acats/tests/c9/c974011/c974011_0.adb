

     --==================================================================--


with Report;
package body C974011_0 is

   protected body Key_PO is
      procedure Set (K : Key_Enum) is
      begin
         Current := K;
      end Set;

      function Value return Key_Enum is
      begin
        return Current;
      end Value;
   end Key_PO;


   procedure Listen_For_Input (Key : out Key_Enum) is
   begin
      -- Model the situation where the user does not press cancel thus
      -- allowing validation to complete

      delay TC_Delay_Time;  -- Long enough to force queuing on
                            -- Keyboard.Cancel_Pressed.
    
      Key := Key_PO.Value;

   end Listen_For_Input;



   -- One of these gets created as "Keyboard" for each transaction
   --
   task body ATM_Keyboard_Task is
      Key_Pressed : Key_Enum;
   begin
      loop
                                                           -- Force entry calls
         Listen_For_Input (Key_Pressed);                   -- to be queued,

         select
            when (Key_Pressed = Cancel) =>                 
               accept Cancel_Pressed do                    
                  TC_Rendezvous_Entered := True;
               end Cancel_Pressed;                        

               -- User has cancelled the transaction so we exit the
               -- loop and allow the task to terminate
               exit;
         else
            delay ImpDef.Switch_To_New_Task;
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
      Count := (Count + 1) mod Integer (Card.PIN);

      -- Simulate a validation activity which is longer than the time
      -- taken in Listen_For_Input but not inordinately so.
      delay TC_Delay_Time * 2;

   end Validate_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      if TC_Rendezvous_Entered then
         Report.Failed ("Triggering statement completed");
      end if;
      if Count = 1234 then
         -- Initial value is unchanged
         Report.Failed ("Abortable part did not execute");
      end if;
      if not TC_Abortable_Part_Completed then
         Report.Failed ("Abortable part did not complete");
      end if;
   end Perform_Transaction;


end C974011_0;
