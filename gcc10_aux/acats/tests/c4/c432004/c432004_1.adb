
     --==================================================================--

package body C432004_1 is

   function TC_Correct_Result (Rec : SampleType_C'Class;
                               P   : Periods) return Boolean is
   begin
      return (Rec.Period = P);
   end TC_Correct_Result;

   -------------------------------------------------------------
   function TC_Correct_Result (Rec : SampleType_H'Class;
                               P   : Periods;
                               E   : C432004_0.Eras) return Boolean is
   begin
      return (Rec.Period = P) and C432004_0.TC_Correct_Result (Rec, E);
   end TC_Correct_Result;

end C432004_1;
