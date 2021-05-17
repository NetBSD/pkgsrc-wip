
     --==================================================================--

package body C432004_0 is

   function TC_Correct_Result (Rec : SampleType_F'Class;
                               E   : Eras) return Boolean is
   begin
      return (Rec.Era = E);
   end TC_Correct_Result;

end C432004_0;
