
     --==================================================================--

with C432004_0;
package C432004_1 is

   type Periods is
      (Aphebian, Helikian, Hadrynian,
       Cambrian, Ordovician, Silurian, Devonian, Carboniferous, Permian,
       Triassic, Jurassic, Cretaceous,
       Tertiary, Quaternary);

   type SampleType_B is new C432004_0.SampleType_A with record
      Period : Periods := Quaternary;
   end record;

   type SampleType_C is abstract new C432004_0.SampleType_A with private;

   -- The following function is needed to verify the values of the
   -- extension's private components.
   function TC_Correct_Result (Rec : SampleType_C'Class;
                               P   : Periods) return Boolean;

   type SampleType_G is abstract new C432004_0.SampleType_F with record
      Period : Periods := Jurassic;
      Loc    : C432004_0.Location;
   end record;

   type SampleType_H is new C432004_0.SampleType_F with private;

   -- The following function is needed to verify the values of the
   -- extension's private components.
   function TC_Correct_Result (Rec : SampleType_H'Class;
                               P   : Periods;
                               E   : C432004_0.Eras) return Boolean;

private
   type SampleType_C is abstract new C432004_0.SampleType_A with record
      Period : Periods := Quaternary;
   end record;

   type SampleType_H is new C432004_0.SampleType_F with record
      Period : Periods := Jurassic;
   end record;

end C432004_1;
