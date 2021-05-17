

     --==================================================================--


with C490002_0;  -- Fixed point support.
use  C490002_0;

with Report;
procedure C490002 is
begin
   Report.Test ("C490002", "Rounding of real static expressions: " &
                "ordinary fixed point subtypes");


   -- Literal cases: If the named numbers used to initialize Positive_Fixed
   -- and Negative_Fixed are rounded to an integral multiple of the small
   -- prior to assignment (as expected), then Positive_Fixed and
   -- Negative_Fixed are already integral multiples of the small, and
   -- equal either P_M1 or P_M2 (resp., N_M1 or N_M2). An equality check
   -- can determine in which direction rounding occurred. For example:
   --
   --        if (Positive_Fixed = P_M1) then -- Rounding was toward 0.0.
   --
   -- Check here that the rounding direction is consistent for literals:

   if (Positive_Fixed = P_M1) then
      Fixed_Subtest (0.11433, P_M1, "Positive Fixed: literal");
   else
      Fixed_Subtest (0.11433, P_M2, "Positive Fixed: literal");
   end if;

   if (Negative_Fixed = N_M1) then
      Fixed_Subtest (-467.13988, N_M1, "Negative Fixed: literal");
   else
      Fixed_Subtest (-467.13988, N_M2, "Negative Fixed: literal");
   end if;


   -- Now check that rounding is performed correctly for values between
   -- multiples of the small, according to the value of 'Machine_Rounds:

   if My_Fix'Machine_Rounds then
      Fixed_Subtest (Pos_Exactly_Half,   P_M1, P_M2, "Positive Fixed: = half");
      Fixed_Subtest (More_Pos_Than_Half, P_M2, "Positive Fixed: > half");
      Fixed_Subtest (Less_Pos_Than_Half, P_M1, "Positive Fixed: < half");

      Fixed_Subtest (Neg_Exactly_Half,   N_M1, N_M2, "Negative Fixed: = half");
      Fixed_Subtest (More_Neg_Than_Half, N_M2, "Negative Fixed: > half");
      Fixed_Subtest (Less_Neg_Than_Half, N_M1, "Negative Fixed: < half");
   else
      Fixed_Subtest (Pos_Exactly_Half,   P_M1, "Positive Fixed: = half");
      Fixed_Subtest (More_Pos_Than_Half, P_M1, "Positive Fixed: > half");
      Fixed_Subtest (Less_Pos_Than_Half, P_M1, "Positive Fixed: < half");

      Fixed_Subtest (Neg_Exactly_Half,   N_M1, "Negative Fixed: = half");
      Fixed_Subtest (More_Neg_Than_Half, N_M1, "Negative Fixed: > half");
      Fixed_Subtest (Less_Neg_Than_Half, N_M1, "Negative Fixed: < half");
   end if;


   Report.Result;
end C490002;
