

     --===================================================================--


with FC54A00;
package BC54A03_4 is

--
-- Access-to-subprogram actuals:
--

   -- Tagged types:

   type Tagged_Same_Type is access procedure
     (A : access FC54A00.Tag);

   type Tagged_Diff_Type is access procedure
     (A : access FC54A00.New_Tag);

   type Tagged_Class_Actual is access procedure
     (A : access FC54A00.Tag'Class);

   type Tagged_Nonconstrained_Subtype is access procedure
     (A : access FC54A00.Same_Tag);

   type Tagged_Diff_Constraint is access procedure
     (A : access FC54A00.Tag25);

   type Tagged_Same_Constraint is access procedure
     (A : access FC54A00.Tag_Twenty);

   type Tagged_Nonstatic_Equiv_Constraint is access procedure
     (A : access FC54A00.Tag20_Var_Nonstatic);


   -- Discrete types:

   type Discrete_Same_Type is access function
     (A, B : access FC54A00.Numerals) return Integer;

   type Discrete_Diff_Range is access function
     (A, B : access FC54A00.Positives) return Integer;

   type Discrete_Same_Range is access function
     (A, B : access FC54A00.Numerals_Static) return Integer;

end BC54A03_4;
