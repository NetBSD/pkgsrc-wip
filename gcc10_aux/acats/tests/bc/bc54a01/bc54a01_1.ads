

     --===================================================================--


with FC54A00;
package BC54A01_1 is

--
-- Access-to-subprogram types to be passed as actuals:
--

   -- Discrete types:

   type Discrete_Diff_Range is access procedure
     (A : access FC54A00.Positives);

   type Discrete_Same_Range is access procedure
     (A : access FC54A00.Numerals_Static);

   type Discrete_Nonstatic_Same_Range is access procedure
     (A : access FC54A00.Numerals_Nonstatic);

   type Discrete_Nonstatic_Dupl_Constr is access procedure
     (A : access FC54A00.Pos_Dupl_Nonstatic);

   type Discrete_Nonstatic_Range_Attr is access procedure
     (A : access FC54A00.Pos_Attr_Nonstatic);


   -- Floating point types:

   type Float_Diff_Type is access function
     (A : access FC54A00.New_Float) return Integer;

   type Float_Diff_Range is access function
     (A : access FC54A00.Float_100) return Integer;

   type Float_Nonconstrained_Subtype is access function
     (A : access FC54A00.Same_Float) return Integer;

   type Float_Has_Same_Range is access function
     (A : access FC54A00.Float_Same_Range) return Integer;


   -- Access types (designated type is tagged):

   type Acc_Tag_Unconstrained_Same_Type is access function
     (A : access FC54A00.Tagged_Ptr) return Boolean;

   type Acc_Tag_Unconstrained_Class_Type is access function
     (A : access FC54A00.Tag_Class_Ptr) return Boolean;

   type Acc_Tag_Constrained_A_Type is access function
     (A : access FC54A00.Msg_Ptr_Static) return Boolean;


end BC54A01_1;
