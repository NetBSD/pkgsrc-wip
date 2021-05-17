

     --===================================================================--


with FC54A00;
package BC54A02_1 is

--
-- Access-to-subprogram types to be passed as actuals:
--

   -- Array types:

   type Array_Unconstrained_Same_Type is access function
     (A : access String) return Boolean;

   type Array_Constrained_Same_Range is access function
     (A : access FC54A00.Msg10) return Boolean;

   type Array_Constrained_Diff_Range is access function
     (A : access FC54A00.Msg20) return Boolean;

   type Array_Constrained_Nonstatic_Type is access function
     (A : access FC54A00.Msg_Nonstatic) return Boolean;

   type Array_Constrained_Nonstatic_Dupl_Constr is access function
     (A : access FC54A00.Msg_Dupl_Nonstatic) return Boolean;


   -- Tagged types:

   type Tagged_Same_Type is access procedure
     (A : access FC54A00.Tag);

   type Tagged_Diff_Type is access procedure
     (A : access FC54A00.New_Tag);

   type Tagged_Class_Actual is access procedure
     (A : access FC54A00.Tag'Class);

   type Tagged_Nonconstrained_Subtype is access procedure
     (A : access FC54A00.Same_Tag);

   type Tagged_Nonstatic_Same_Type is access procedure
     (A : access FC54A00.Tag20_Nonstatic);

   type Tagged_Nonstatic_Dupl_Constraint is access procedure
     (A : access FC54A00.Tag20_Dupl_Nonstatic);

   type Tagged_Nonstatic_No_Constraint is access procedure
     (A : access FC54A00.Tag20_Same_Nonstatic);


end BC54A02_1;
