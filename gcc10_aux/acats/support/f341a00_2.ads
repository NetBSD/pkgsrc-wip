

     --=================================================================--


with F341A00_0;  -- package Bank
with F341A00_1;  -- package Checking

package F341A00_2 is    -- package Interest_Checking 

   package Bank     renames F341A00_0;
   package Checking renames F341A00_1;

   subtype Interest_Rate is Bank.Dollar_Amount digits 4;  

   Current_Rate : Interest_Rate := 0.030;

   type Account is new Checking.Account with
      record
         Rate : Interest_Rate;
      end record;

   -- "Twice" inherited primitive operations (Bank.Account, Checking.Account)
   -- procedure Deposit       (A : in out Account; X : in Bank.Dollar_Amount);
   -- procedure Withdrawal    (A : in out Account; X : in Bank.Dollar_Amount);
   -- function  Balance       (A : in     Account) return Bank.Dollar_Amount;
   -- procedure Service_Charge(A : in out Account);

   -- Overridden primitive operations.
   procedure Add_Interest (A : in out Account);
   procedure Open         (A : in out Account);

end F341A00_2;
