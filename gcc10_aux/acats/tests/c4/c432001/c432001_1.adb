
with Report;
package body C432001_1 is

   function Check (Rec : in N_N;
                   N   : in Natural;
                   E   : in C432001_0.Eras;
                   P   : in Periods) return Boolean is
   begin
      if not C432001_0.Check (C432001_0.N (Rec), N, E) then
         Report.Failed ("Conversion to parent type of " &
                        "nonprivate portion of " &
                        "nonprivate extension failed");
      end if;
      return Rec.Period = P;
   end Check;
   

   function Check (Rec : in N_P) return Boolean is
   begin
      if not C432001_0.Check (C432001_0.N (Rec), 1, C432001_0.Cenozoic) then
         Report.Failed ("Conversion to parent type of " &
                        "nonprivate portion of " &
                        "private extension failed");
      end if;
      return Rec.Period = C432001_1.Quaternary;
   end Check;

   function Check (Rec : in P_N;
                   P   : in Periods) return Boolean is
   begin
      if not C432001_0.Check (C432001_0.P (Rec)) then
         Report.Failed ("Conversion to parent type of " &
                        "private portion of " &
                        "nonprivate extension failed");
      end if;
      return Rec.Period = P;
   end Check;

   function Check (Rec : in P_P) return Boolean is
   begin
      if not C432001_0.Check (C432001_0.P (Rec)) then
         Report.Failed ("Conversion to parent type of " &
                        "private portion of " &
                        "private extension failed");
      end if;
      return Rec.Period = C432001_1.Jurassic;
   end Check;

end C432001_1;
