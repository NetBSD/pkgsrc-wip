
with Report;
package body C432001_2 is

   -- direct access to operator
   use type C432001_1.Periods;


   function Check (Rec : in N_N_N;
                   N   : in Natural;
                   E   : in C432001_0.Eras;
                   P   : in C432001_1.Periods;
                   B   : in Boolean) return Boolean is
   begin
      if not C432001_1.Check (C432001_1.N_N (Rec), N, E, P) then
         Report.Failed ("Conversion to parent " &
                        "nonprivate type extension " &
                        "failed");
      end if;
      return Rec.Sample_On_Loan = B;
   end Check;
   

   function Check (Rec : in N_P_N;
                   B   : Boolean) return Boolean is
   begin
      if not C432001_1.Check (C432001_1.N_P (Rec)) then
         Report.Failed ("Conversion to parent " &
                        "private type extension " &
                        "failed");
      end if;
      return Rec.Sample_On_Loan = B;
   end Check;

   function Check (Rec : in P_N_N;
                   P   : in C432001_1.Periods;
                   B   : Boolean) return Boolean is
   begin
      if not C432001_1.Check (C432001_1.P_N (Rec), P) then
         Report.Failed ("Conversion to parent " &
                        "nonprivate type extension " &
                        "failed");
      end if;
      return Rec.Sample_On_Loan = B;
   end Check;

   function Check (Rec : in P_P_N;
                   B   : Boolean) return Boolean is
   begin
      if not C432001_1.Check (C432001_1.P_P (Rec)) then
         Report.Failed ("Conversion to parent " &
                        "private type extension " &
                        "failed");
      end if;
      return Rec.Sample_On_Loan = B;
   end Check;

end C432001_2;
