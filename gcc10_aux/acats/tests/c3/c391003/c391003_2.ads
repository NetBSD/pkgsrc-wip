
----------------------------------------------------------------- C391003_2

with C391003_0;             -- with Bank;

package C391003_2 is     -- package Wire_Transfers

   package Bank     renames C391003_0;

   type Account_Kind is (Basic, Premium, Platinum);

   Transfer_Failed : exception;

   procedure Wire_Transfer (Source : in out Bank.Account'Class;
                            Amount : in     Bank.Dollar_Amount;
                            Kind   : in     Account_Kind);

end C391003_2;
