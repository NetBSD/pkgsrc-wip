

     --=================================================================--


with F341A00_0;

package F341A00_1 is    -- package Checking

   package Bank renames F341A00_0;

   type Account is new Bank.Account with 
      record
         Overdraft_Fee : Bank.Dollar_Amount;
      end record;


   -- Inherited primitive operations.
   -- procedure Deposit       (A : in out Account; X : in Bank.Dollar_Amount);
   -- procedure Withdrawal    (A : in out Account; X : in Bank.Dollar_Amount);
   -- function  Balance       (A : in     Account) return Bank.Dollar_Amount;
   -- procedure Service_Charge(A : in out Account);
   -- procedure Add_Interest  (A : in out Account);

   -- Overridden primitive operation.
   procedure Open (A : in out Account);

end F341A00_1;
