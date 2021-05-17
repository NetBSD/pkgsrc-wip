

     --==================================================================--


with C490001_0;  -- Floating point support.
use  C490001_0;

with Report;
procedure C490001 is
begin
   Report.Test ("C490001", "Rounding of real static expressions: " &
                "floating point subtypes");


   -- Check that rounding direction is consistent for literals:

   Float_Subtest (12.440193950021943, P_M1, "Positive Float: literal");
   Float_Subtest (-0.692074550952117, N_M1, "Negative Float: literal");


   -- Now check that rounding is performed correctly for values between
   -- machine numbers, according to the value of 'Machine_Rounds:

   if My_Flt'Machine_Rounds then
      Float_Subtest (Pos_Exactly_Half,   P_M1, P_M2, "Positive Float: = half");
      Float_Subtest (More_Pos_Than_Half, P_M2, "Positive Float: > half");
      Float_Subtest (Less_Pos_Than_Half, P_M1, "Positive Float: < half");

      Float_Subtest (Neg_Exactly_Half,   N_M1, N_M2, "Negative Float: = half");
      Float_Subtest (More_Neg_Than_Half, N_M2, "Negative Float: > half");
      Float_Subtest (Less_Neg_Than_Half, N_M1, "Negative Float: < half");
   else
      Float_Subtest (Pos_Exactly_Half,   P_M1, "Positive Float: = half");
      Float_Subtest (More_Pos_Than_Half, P_M1, "Positive Float: > half");
      Float_Subtest (Less_Pos_Than_Half, P_M1, "Positive Float: < half");

      Float_Subtest (Neg_Exactly_Half,   N_M1, "Negative Float: = half");
      Float_Subtest (More_Neg_Than_Half, N_M1, "Negative Float: > half");
      Float_Subtest (Less_Neg_Than_Half, N_M1, "Negative Float: < half");
   end if;


   Report.Result;
end C490001;
