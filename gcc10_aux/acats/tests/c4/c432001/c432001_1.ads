
with C432001_0;
package C432001_1 is

   type Periods is
      (Aphebian, Helikian, Hadrynian,
       Cambrian, Ordovician, Silurian, Devonian, Carboniferous, Permian,
       Triassic, Jurassic, Cretaceous,
       Tertiary, Quaternary);

   type N_N is new C432001_0.N with record
      Period : Periods := C432001_1.Quaternary;
   end record;

   function Check (Rec : in N_N;
                   N   : in Natural;
                   E   : in C432001_0.Eras;
                   P   : in Periods) return Boolean;

   type N_P is new C432001_0.N with private;

   function Check (Rec : in N_P) return Boolean;

   type P_N is new C432001_0.P with record
      Period : Periods := C432001_1.Jurassic;
   end record;

   function Check (Rec : in P_N;
                   P   : in Periods) return Boolean;

   type P_P is new C432001_0.P with private;

   function Check (Rec : in P_P) return Boolean;

   type P_P_Null is new C432001_0.P with null record;  

private

   type N_P is new C432001_0.N with record
      Period : Periods := C432001_1.Quaternary;
   end record;

   type P_P is new C432001_0.P with record
      Period : Periods := C432001_1.Jurassic;
   end record;

end C432001_1;
