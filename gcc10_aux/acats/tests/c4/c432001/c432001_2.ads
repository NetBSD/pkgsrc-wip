
with C432001_0;
with C432001_1;
package C432001_2 is

   -- All types herein are nonprivate extensions, since aggregates
   -- cannot be given for private extensions
   
   type N_N_N is new C432001_1.N_N with record
      Sample_On_Loan : Boolean;
   end record;

   function Check (Rec : in N_N_N;
                   N   : in Natural;
                   E   : in C432001_0.Eras;
                   P   : in C432001_1.Periods;
                   B   : in Boolean) return Boolean;

   type N_P_N is new C432001_1.N_P with record
      Sample_On_Loan : Boolean;
   end record;

   function Check (Rec : in N_P_N;
                   B   : Boolean) return Boolean;

   type P_N_N is new C432001_1.P_N with record
      Sample_On_Loan : Boolean;
   end record;

   function Check (Rec : in P_N_N;
                   P   : in C432001_1.Periods;
                   B   : Boolean) return Boolean;

   type P_P_N is new C432001_1.P_P with record
      Sample_On_Loan : Boolean;
   end record;

   function Check (Rec : in P_P_N;
                   B   : Boolean) return Boolean;

end C432001_2;
