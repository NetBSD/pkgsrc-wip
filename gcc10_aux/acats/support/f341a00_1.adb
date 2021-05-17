

     --=================================================================--


package body F341A00_1 is

   -- Overridden primitive operation.

   procedure Open (A : in out Account) is
      Check_Guarantee : Bank.Dollar_Amount :=  10.00;
      Initial_Deposit : Bank.Dollar_Amount := 100.00;
   begin
      A.Current_Balance := Initial_Deposit;
      A.Overdraft_Fee   := Check_Guarantee;
   end Open;

end F341A00_1;
