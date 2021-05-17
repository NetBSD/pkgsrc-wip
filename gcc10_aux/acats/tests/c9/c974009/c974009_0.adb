

     --==================================================================--


with Report;
package body C974009_0 is



   -- One of these gets created as "Keyboard" for each transaction
   --
   task body ATM_Keyboard_Task is
      Key_Pressed : Key_Enum := None;
   begin
      accept Cancel_Pressed do        -- queued entry call.
         null;  --:::: stub, user code for cancel
         -- Now simulate an unexpected exception arising in the
         -- user code
         raise Propagated_From_Task;  -- Propagate an exception.
                  
       end Cancel_Pressed;

       Report.Failed ("Exception not propagated in ATM_Keyboard_Task");
               
   exception
      when Propagated_From_Task =>
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


end C974009_0;
