

     --=================================================================--


package body F341A00_2 is

   -- Overridden primitive operations.

   procedure Add_Interest (A : in out Account) is
      use type Bank.Dollar_Amount;
      Interest_On_Account : Bank.Dollar_Amount
                          := Bank.Dollar_Amount(A.Current_Balance * A.Rate);
   begin
      A.Current_Balance := A.Current_Balance + Interest_On_Account;
   end Add_Interest;

   procedure Open (A : in out Account) is
      Initial_Deposit : Bank.Dollar_Amount := 1000.00;
   begin
      Checking.Open (Checking.Account (A));
      A.Current_Balance := Initial_Deposit;
      A.Rate            := Current_Rate;
   end Open;

end F341A00_2;
