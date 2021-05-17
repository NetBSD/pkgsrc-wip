

     --===================================================================--


with FC54A00;
package BC54A05_1 is

--
-- General access-to-variable types to be passed as actuals:
--

   -- Formal private (array) designated type:

   type Acc_String         is access all String;
   type Acc_Same_String    is access all FC54A00.Same_String;
   type Acc_Msg10          is access all FC54A00.Msg10;
   type Acc_Msg20          is access all FC54A00.Msg20;
   type Acc_Msg_Nonstat    is access all FC54A00.Msg_Nonstatic;


   -- Generic formal (tagged private) designated type:

   type Acc_FD_Tag         is access all FC54A00.Tag;
   type Acc_FD_New_Tag     is access all FC54A00.New_Tag;
   type Acc_FD_Tag_Class   is access all FC54A00.Tag'Class;
   type Acc_FD_Tag25       is access all FC54A00.Tag25;
   type Acc_FD_Tag_Twenty  is access all FC54A00.Tag_Twenty;


end BC54A05_1;
