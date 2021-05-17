

     --==================================================================--


with Report;
package body C974010_0 is



   -- One of these gets created as "Keyboard" for each transaction
   --
   task body ATM_Keyboard_Task is
      TC_Suicide  : exception;
      Key_Pressed : Key_Enum := None;
   begin
      raise TC_Suicide;   -- Simulate early, unexpected termination

      accept Cancel_Pressed do        -- queued entry call.
         null;  --:::: user code for cancel
                 
      end Cancel_Pressed;

   exception
      when TC_Suicide =>
         null;  -- This is the expected test behavior
      when others =>
          Report.Failed ("Unexpected Exception in ATM_Keyboard_Task");
   end ATM_Keyboard_Task;

   procedure Validate_Card (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Abortable part was executed");
   end Validate_Card;


   procedure Perform_Transaction (Card : in ATM_Card_Type) is
   begin
      Report.Failed ("Exception not re-raised immediately following " &
                     "asynchronous select");
   end Perform_Transaction;


end C974010_0;
