

     --==================================================================--


with Report;

with C974006_0;  -- Automated teller machine abstraction.
use  C974006_0;

procedure C974006 is

   Card_Data : ATM_Card_Type;

begin

   Report.Test ("C974006", "ATC: trigger is protected entry call" &
                              " and completes first");

   Read_Card (Card_Data);

   declare
      Keyboard : C974006_0.ATM_Keyboard_Protected;
   begin

      -- Simulate the situation where the user hits cancel before the
      -- validation process can start:
      Keyboard.Read_Key;                 -- Force Keyboard.Cancel_Pressed to
                                         -- be accepted immediately.

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
         Keyboard.Cancel_Pressed;        -- Entry call is accepted immediately,
                                         -- so abortable part does NOT start.

         if not Entry_Body_Executed then -- Executes after entry completes.
            Report.Failed ("Triggering alternative sequence of statements " &
                           "executed before triggering statement complete");
         end if;

         raise Transaction_Canceled;     -- Control passes to exception
                                         -- handler.
      then abort
         Validate_Card (Card_Data);      -- Should not be executed.
      end select;
      Perform_Transaction (Card_Data);   -- Should not be reached.
   exception
      when Transaction_Canceled =>
         null;
   end;

   Report.Result;

end C974006;
