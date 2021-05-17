

     --===================================================================--


with FC54A00;
package BC54A04_1 is

--
-- Access-to-constant types to be passed as actuals:
--

   -- Discrete (integer) designated type:

   type Acc_Pos            is access constant FC54A00.Positives;
   type Acc_Same_Num       is access constant FC54A00.Same_Numerals;
   type Acc_Num_Nonstat    is access constant FC54A00.Numerals_Nonstatic;
   type Acc_Pos_Du_Nonstat is access constant FC54A00.Pos_Dupl_Nonstatic;


   -- Array designated type:

   type Acc_String         is access constant String;
   type Acc_New_String     is access constant FC54A00.New_String;
   type Acc_Msg20          is access constant FC54A00.Msg20;
   type Acc_Msg_Nonstat    is access constant FC54A00.Msg_Nonstatic;
   type Acc_Msg_Sa_Nonstat is access constant FC54A00.Msg_Same_Nonstatic;


end BC54A04_1;
