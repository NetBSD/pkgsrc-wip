

     --==================================================================--

with Report;
with C432004_0;
with C432004_1;
with C432004_2;
use  C432004_1;
use  C432004_2;

procedure C432004 is

   -- Variety of extension aggregates.

   -- Default values for the components of SampleType_A 
   -- (Era => Cenozoic, Loc => null).
   Sample_B  :  SampleType_B 
             := (C432004_0.SampleType_A with Period => Devonian);

   -- Default values from SampleType_A (Era => Cenozoic, Loc => null).
   Sample_D1 :  SampleType_D
             := (C432004_0.SampleType_A with Period => Cambrian,
                                     Sample_On_Loan => True);

   -- Default values from SampleType_A and SampleType_B
   -- (Era => Cenozoic, Loc => null, Period => Quaternary).
   Sample_D2 :  SampleType_D
             := (SampleType_B with Sample_On_Loan => True);

   -- Default values from SampleType_A and SampleType_C
   -- (Era => Cenozoic, Loc => null, Period => Quaternary).
   Sample_E  :  SampleType_E
             := (SampleType_C with null record);

   -- Default value from SampleType_F (Era => Mesozoic).
   Sample_I1 :  SampleType_I
             := (C432004_0.SampleType_F with Period => Tertiary,
                 Loc => new C432004_0.Drawers'(Building => 9),
                 Sample_On_Loan => False);

   -- Default values from SampleType_F and SampleType_G
   -- (Era => Mesozoic, Period => Jurassic, Loc => null).
   Sample_I2 :  SampleType_I
             := (SampleType_G with Sample_On_Loan => False);

   -- Default values from SampleType_H (Era => Mesozoic, Period => Jurassic).
   Sample_J  :  SampleType_J
             := (SampleType_H with Sample_On_Loan => False);

   use type C432004_0.Eras;
   use type C432004_0.Location;

begin

   Report.Test ("C432004", "Check that the type of an extension aggregate "  &
                "may be derived from the type of the ancestor part through " &
                "multiple record extensions");

   if Sample_B /= (C432004_0.Cenozoic, null, Devonian) then
      Report.Failed ("Object of record extension of abstract ancestor, " &
                     "SampleType_B, failed content check");
   end if;

   -------------------
   if Sample_D1 /= (Era => C432004_0.Cenozoic, Loc => null, 
                    Period => Cambrian, Sample_On_Loan => True) then
      Report.Failed ("Object 1 of record extension of record extension, "  & 
                     "of abstract ancestor, SampleType_D, failed content " &
                     "check");
   end if;

   -------------------
   if Sample_D2 /= (C432004_0.Cenozoic, null, Quaternary, True) then
      Report.Failed ("Object 2 of record extension of record extension, "  & 
                     "of abstract ancestor, SampleType_D, failed content " &
                     "check");
   end if;
   -------------------
   if Sample_E.Era /= C432004_0.Cenozoic or 
      Sample_E.Loc /= null               or
      not TC_Correct_Result (Sample_E, Quaternary) then
         Report.Failed ("Object of record extension of abstract private " & 
                        "extension of abstract ancestor, SampleType_E, "  &
                        "failed content check");
   end if;

   -------------------
   if not C432004_0.TC_Correct_Result (Sample_I1, C432004_0.Mesozoic) or
     Sample_I1.Period         /= Tertiary                             or
     Sample_I1.Loc.Building   /= 9                                    or
     Sample_I1.Sample_On_Loan /= False                                then
       Report.Failed ("Object 1 of record extension of abstract record " &
                      "extension of abstract private ancestor, "         &
                      "SampleType_I, failed content check");
   end if;

   -------------------
   if not C432004_0.TC_Correct_Result (Sample_I2, C432004_0.Mesozoic) or  
     Sample_I2.Period         /= Jurassic                             or
     Sample_I2.Loc            /= null                                 or
     Sample_I2.Sample_On_Loan /= False                                then
       Report.Failed ("Object 2 of record extension of abstract record " &
                      "extension of abstract private ancestor, "         &
                      "SampleType_I, failed content check");
   end if;

   -------------------
   if not TC_Correct_Result (Sample_J,
                             Jurassic,
                             C432004_0.Mesozoic) or
     Sample_J.Sample_On_Loan /= False            then
        Report.Failed ("Object of record extension of private extension " &
                       "of abstract private ancestor, SampleType_J, "     &
                       "failed content check");
   end if;

   Report.Result;

end C432004;
