
----------------------------------------------------------------- C391003_1

with C391003_0;             -- with Bank;

package C391003_1 is     -- package Interest_Checking

   package Bank     renames C391003_0;

   subtype Interest_Rate is Bank.Dollar_Amount range 0..100; -- was digits 4;

   Current_Rate : Interest_Rate := 0_02;

   type Account is new Bank.Account with
      record
         Overdraft_Fee : Bank.Dollar_Amount;
         Rate : Interest_Rate;
      end record;

   overriding
   procedure Add_Interest (A : in out Account);

   overriding
   procedure Open         (A : in out Account);

   overriding
   procedure Withdrawal     (A : in out Account;
                             X : in     Bank.Dollar_Amount);

   -- Inherited primitive operations (from Bank.Account)
   -- procedure Deposit        (A : in out Account;
   --                           X : in     Bank.Dollar_Amount);
   -- function  Balance        (A : in     Account) return Bank.Dollar_Amount;
   -- procedure Service_Charge (A : in out Account);

end C391003_1;
