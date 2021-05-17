

     --=================================================================--


with F341A00_0;            -- package Bank
with F341A00_1;            -- package Checking
with C341A03_0;            -- generic function Audit
with Report;

procedure C341A03 is

   package Bank     renames F341A00_0;
   package Checking renames F341A00_1;

   Current_Checking_Accounts : constant := 3;

   Checking_Acct1 : aliased Checking.Account := (Current_Balance => 10.00,
                                                 Overdraft_Fee   =>  5.00);
   Checking_Acct2 : aliased Checking.Account := (Current_Balance => 20.00,
                                                 Overdraft_Fee   =>  5.00);
   Checking_Acct3 : aliased Checking.Account := (Current_Balance => 30.00,
                                                 Overdraft_Fee   =>  5.00);

   type ATM_Card is access all Checking.Account'Class;

   -- Declare array of accesses to class-wide objects.
   Account_Array : array (1 .. Current_Checking_Accounts) of 
     ATM_Card := (Checking_Acct1'Access, 
                  Checking_Acct2'Access, 
                  Checking_Acct3'Access);
begin  -- C341A03

   Report.Test ("C341A03",  "Check that an object of one class-wide type " &
                            "can initialize a class-wide object of a "   &
                            "different type when the operation is embedded " &
                            "in a generic unit" );

   Audit_Checking_Accounts:
   declare
      Balance_In_Checking_Accounts : Bank.Dollar_Amount := 0.00;
      -- Instantiate with a specific extended type.
      function Checking_Audit is new C341A03_0 (Checking.Account);
      use type Bank.Dollar_Amount;
   begin

      for I in 1 .. Current_Checking_Accounts loop
         Balance_In_Checking_Accounts := Balance_In_Checking_Accounts + 
           Checking_Audit (Account_Array (I).all);
      end loop;

      if Balance_In_Checking_Accounts /= 60.00 then
         Report.Failed ("Incorrect initialization of class-wide object");
      end if;

   end Audit_Checking_Accounts;

   Report.Result;

end C341A03;
