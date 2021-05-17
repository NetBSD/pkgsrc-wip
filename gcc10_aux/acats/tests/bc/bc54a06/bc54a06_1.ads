

     --===================================================================--


with FC54A00;
package BC54A06_1 is

--
-- Access-to-variable types to be passed as actuals:
--

   -- Note that some are pool-specific, and others are general. The actual
   -- corresponding to a pool-specific formal may be either general or
   -- pool-specific. 


   -- Tagged (pool-specific) designated type:

   type Acc_Tag            is access     FC54A00.Tag;
   type Acc_Same_Tag       is access all FC54A00.Same_Tag;
   type Acc_Tag20          is access     FC54A00.Tag20;
   type Acc_Tag25          is access all FC54A00.Tag25;
   type Acc_Tag_Nonstat    is access     FC54A00.Tag20_Nonstatic;
   type Acc_Tag_Du_Nonstat is access all FC54A00.Tag20_Dupl_Nonstatic;
   type Acc_Tag_Va_Nonstat is access     FC54A00.Tag20_Var_Nonstatic;



   -- Formal discrete (general) designated type:

   type Acc_Num            is access     FC54A00.Numerals;
   type Acc_New_Num        is access all FC54A00.New_Numerals;
   type Acc_Pos            is access     FC54A00.Positives;
   type Acc_Num_Nonstat    is access all FC54A00.Numerals_Nonstatic;


end BC54A06_1;
