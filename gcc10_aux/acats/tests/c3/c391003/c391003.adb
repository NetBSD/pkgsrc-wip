
------------------------------------------------------------------- C391003

with C391003_0;    use C391003_0;        -- package Bank
with C391003_1;    use C391003_1;        -- package Interest_Checking;
with C391003_2;    use C391003_2;        -- package Wire_Transfer;
with Report;
with Ada.Exceptions;

procedure C391003 is

   package Bank              renames C391003_0;
   package Interest_Checking renames C391003_1;
   package Wire_Transfers    renames C391003_2;

   B_Acct  : Bank.Account;
   IC_Acct, IC_Acct2 : Interest_Checking.Account;

begin

   Report.Test ("C391003",  "Check that a type can be extended at a " &
                             "different level than the parent type. Check " &
                             "that subprograms overridden for such an " &
                             "extension can be dispatched to, and that the " &
                             "overridden routine can access local variables " &
                             "of the subprogram");

   Open (B_Acct);
   Deposit (B_Acct, 250_00);

   Open (IC_Acct);
   Deposit (IC_Acct, 30_00);  --+20_00 initial deposit.

   Open (IC_Acct2);
   Deposit (IC_Acct2, 280_00); --+20_00 initial deposit.

   -- Try a wire transfer for a platinum account:
   Wire_Transfer (IC_Acct, Amount => 23_00, Kind => Platinum);

   if Balance (IC_Acct) /= 25_00 then
      Report.Failed ("Wrong balance in account after transfer");
   end if;

   -- Try a wire transfer for a premium account:
   Wire_Transfer (IC_Acct2, Amount => 200_00, Kind => Premium);

   if Balance (IC_Acct2) /= 98_00 then
      Report.Failed ("Wrong balance in account after transfer");
   end if;

   -- Try a too-small transfer for a basic account:
   begin
      Wire_Transfer (B_Acct, Amount => 14_00, Kind => Basic);
         -- Should raise Transfer_Failed.
      Report.Failed ("Failed transfer not detected (probably did not " &
           "dispatch to overridden Deposit)");

   exception
      when Wire_Transfers.Transfer_Failed => null;
   end;

   Report.Result;

exception
    when Err:others =>
        Report.Failed ("Stray exception: " &
                        Ada.Exceptions.Exception_Information (Err));
end C391003;
