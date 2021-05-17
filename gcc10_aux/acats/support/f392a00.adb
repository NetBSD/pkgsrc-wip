

     --=================================================================--


package body F392A00 is

   --
   -- Primitive operations for Bank_Account.
   --

   procedure Increment_Bank_Reserve (Acct : in Bank_Account) is
   begin
      Bank_Reserve := Bank_Reserve + Acct.Balance;
   end Increment_Bank_Reserve;

   procedure Assign_Representative (Acct : in Bank_Account) is
   begin
      Daily_Representative := Teller;
   end Assign_Representative;

   procedure Increment_Counters (Acct : in Bank_Account) is
   begin
      Number_Of_Accounts (Bank)  := Number_Of_Accounts (Bank) + 1;
      Number_Of_Accounts (Total) := Number_Of_Accounts (Total) + 1;
   end Increment_Counters;

   procedure Open (Acct : in out Bank_Account) is
   begin
      Acct.Balance := Opening_Balance;
   end Open;


   --
   -- Overridden operations for Savings_Account type.
   --

   procedure Assign_Representative (Acct : in Savings_Account) is
   begin
      Daily_Representative := Manager;
   end Assign_Representative;

   procedure Increment_Counters (Acct : in Savings_Account) is
   begin
      Number_Of_Accounts (Savings) := Number_Of_Accounts (Savings) + 1;
      Number_Of_Accounts (Total)   := Number_Of_Accounts (Total) + 1;
   end Increment_Counters;

   procedure Open (Acct : in out Savings_Account) is
   begin
      Open (Bank_Account(Acct));
      Acct.Rate := Current_Rate;
      Acct.Balance := 2.0 * Opening_Balance;
   end Open;
     

   --
   -- Overridden operation for Preferred_Account type.
   --
                     
   procedure Increment_Counters (Acct : in Preferred_Account) is
   begin
      Number_Of_Accounts (Preferred) := Number_Of_Accounts (Preferred) + 1;
      Number_Of_Accounts (Total)     := Number_Of_Accounts (Total) + 1;
   end Increment_Counters;

   procedure Open (Acct : in out Preferred_Account) is
   begin
      Open (Savings_Account(Acct));
      Acct.Minimum_Balance := Preferred_Minimum_Balance;
      Acct.Balance := Acct.Minimum_Balance;
   end Open;

   --
   -- Function used to verify Open operation for Preferred_Account objects.
   --

   function Verify_Open (Acct : in Preferred_Account) return Boolean is
   begin                                                    
      return (Acct.Balance         = Preferred_Minimum_Balance and
              Acct.Rate            = Current_Rate              and
              Acct.Minimum_Balance = Preferred_Minimum_Balance);
   end Verify_Open;

end F392A00;
