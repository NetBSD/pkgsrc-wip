
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C391003_1 is

   -- Overridden primitive operations.

   procedure Add_Interest (A : in out Account) is
      Interest_On_Account : Bank.Dollar_Amount
        := Bank.Dollar_Amount( Bank."*"( A.Balance, A.Rate ));
   begin
      Bank.Deposit (Bank.Account(A), Interest_On_Account);
   end Add_Interest;

   procedure Open (A : in out Account) is
      Initial_Deposit : Bank.Dollar_Amount := 20_00;
      Check_Guarantee : Bank.Dollar_Amount := 10_00;
   begin
      Bank.Open (Bank.Account(A));
      A.Overdraft_Fee   := Check_Guarantee;
      A.Rate            := Current_Rate;
      Bank.Deposit (Bank.Account(A), Initial_Deposit);
   end Open;

   procedure Withdrawal     (A : in out Account;
                             X : in     Bank.Dollar_Amount) is
      use type Bank.Dollar_Amount;
   begin
      if X < A.Balance then
         Bank.Withdrawal (Bank.Account(A), X);
      else -- apply overdraft fee.
         Bank.Withdrawal (Bank.Account(A), X);
         Bank.Withdrawal (Bank.Account(A), A.Overdraft_Fee);
      end if;
   end Withdrawal;

end C391003_1;
