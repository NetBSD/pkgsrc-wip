
     --==================================================================--

with C432004_0;
with C432004_1;
package C432004_2 is

   -- All types herein are record extensions, since aggregates
   -- cannot be given for private extensions
   
   type SampleType_D is new C432004_1.SampleType_B with record
      Sample_On_Loan : Boolean := False;
   end record;

   type SampleType_E is new C432004_1.SampleType_C 
     with null record;

   type SampleType_I is new C432004_1.SampleType_G with record
      Sample_On_Loan : Boolean := True;
   end record;

   type SampleType_J is new C432004_1.SampleType_H with record
      Sample_On_Loan : Boolean := True;
   end record;

end C432004_2;
