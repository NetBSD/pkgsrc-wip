
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C391003_2 is

   use type Bank.Dollar_Amount;

   procedure Wire_Transfer (Source : in out Bank.Account'Class;
                            Amount : in     Bank.Dollar_Amount;
                            Kind   : in     Account_Kind) is

      Minimum_Xfer : Bank.Dollar_Amount;
      Maximum_Xfer : Bank.Dollar_Amount;

      type Transfer_Account is new Bank.Account with null record;

      overriding
      procedure Deposit    (A : in out Transfer_Account;
                            X : in     Bank.Dollar_Amount) is
      begin
         Bank.Deposit (Bank.Account(A), X);
         if A.Balance < Minimum_Xfer then
             raise Transfer_Failed with "Too little transferred";
         elsif A.Balance > Maximum_Xfer then
             --raise Transfer_Failed with "Too much transferred";
             Report.Failed ("Too much transferred, limit=" &
                Bank.Dollar_Amount'Image(Maximum_Xfer) &
                "; Balance=" & Bank.Dollar_Amount'Image(A.Balance));
         else
             null; -- Transmit money via ACH.
         end if;
      end Deposit;

      Xfer_Acct : Transfer_Account;

   begin
      case Kind is
         when Basic =>
            Minimum_Xfer :=   25_00;
            Maximum_Xfer :=  100_00;
         when Premium =>
            Minimum_Xfer :=   12_00;
            Maximum_Xfer :=  200_00;
         when Platinum =>
            Minimum_Xfer :=   10_00;
            Maximum_Xfer :=  300_00;
      end case;
      Open (Xfer_Acct); -- Zeros balance.

      Bank.Transfer (Source => Source,
                     Target => Xfer_Acct,
                     Amount => Amount);

      if Balance (Xfer_Acct) /= Amount then
         Report.Failed ("Wrong balance transferred - Balance=" &
            Bank.Dollar_Amount'Image(Balance (Xfer_Acct)));
      end if;
   end Wire_Transfer;

end C391003_2;
