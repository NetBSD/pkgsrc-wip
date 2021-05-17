

     --==================================================================--
with Report;

with C974007_0;  -- Automated teller machine abstraction.
use  C974007_0;

procedure C974007 is

   Card_Data : ATM_Card_Type;

begin

   Report.Test ("C974007", "ATC: trigger is protected entry call" &
                              " and abortable part completes first");

   Read_Card (Card_Data);

   declare
      Keyboard : C974007_0.ATM_Keyboard_Protected;
   begin

      --                                    --
      -- Asynchronous select is tested here --
      --                                    --

      select
         Keyboard.Cancel_Pressed;        -- Barrier is never set true, so
                                         -- entry call is queued and never
                                         -- accepted.

         raise Transaction_Canceled;     -- Should not be executed.
      then abort
         Validate_Card (Card_Data);      -- This call completes before
                                         -- Keyboard.Cancel_Pressed can be
                                         -- accepted.
      end select;
      Perform_Transaction (Card_Data);   -- Execution proceeds here after
                                         -- Validate_Card completes.
   exception
      when Transaction_Canceled =>
         Report.Failed ("Triggering alternative sequence of statements " &
                        "executed");
   end;
   
   
   if Triggering_Statement_Executed  then
      Report.Failed ("Triggering statement was executed");
   end if;

   if not Abortable_Part_Executed then
      Report.Failed ("Abortable part not executed");
   end if;

   if not Perform_Transaction_Executed then
      Report.Failed ("Statements following asynchronous select not " &
                     "executed");
   end if;

   Report.Result;

end C974007;
