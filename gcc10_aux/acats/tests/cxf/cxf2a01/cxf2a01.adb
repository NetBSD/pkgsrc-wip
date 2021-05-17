

     --==================================================================--


with CXF2A01_0.CXF2A01_1;

with Report;
procedure CXF2A01 is
   package Data renames CXF2A01_0.CXF2A01_1;

   use type CXF2A01_0.Micro;
   use type CXF2A01_0.Money;
   use type CXF2A01_0.Cash;
   use type CXF2A01_0.Broad;

   Micro_Cancel_Expected : constant CXF2A01_0.Micro := 0.0;
   Money_Cancel_Expected : constant CXF2A01_0.Money := 0.0;
   Cash_Cancel_Expected  : constant CXF2A01_0.Cash  := 0.0;
   Broad_Cancel_Expected : constant CXF2A01_0.Broad := 0.0;

   Micro_Cumul_Expected  : constant CXF2A01_0.Micro :=  0.075682140420000000;
   Money_Cumul_Expected  : constant CXF2A01_0.Money := -21327300.00;
   Cash_Cumul_Expected   : constant CXF2A01_0.Cash  :=  624570600.00;
   Broad_Cumul_Expected  : constant CXF2A01_0.Broad := -9015252.535794000;

   Micro_Actual   : CXF2A01_0.Micro;
   Money_Actual   : CXF2A01_0.Money;
   Cash_Actual    : CXF2A01_0.Cash;
   Broad_Actual   : CXF2A01_0.Broad;
begin

   Report.Test ("CXF2A01", "Check decimal addition and subtraction");


               ---=---=---=---=---=---=---=---=---=---=---


   Micro_Actual := Data.Test_Micro_Ops (0.0,
                                        Data.Micro_Optr_Table_Cancel,
                                        Data.Micro_Opnd_Table_Cancel);

   if Micro_Actual /= Micro_Cancel_Expected then
      Report.Failed ("Wrong cancellation result for type Micro");
   end if;

                       ---=---=---=---=---=---=---


   Micro_Actual := Data.Test_Micro_Ops (0.0,
                                        Data.Micro_Optr_Table_Cumul,
                                        Data.Micro_Opnd_Table_Cumul);

   if Micro_Actual /= Micro_Cumul_Expected then
      Report.Failed ("Wrong cumulation result for type Micro");
   end if;


               ---=---=---=---=---=---=---=---=---=---=---


   Money_Actual := Data.Test_Money_Ops (0.0,
                                        Data.Money_Optr_Table_Cancel,
                                        Data.Money_Opnd_Table_Cancel);

   if Money_Actual /= Money_Cancel_Expected then
      Report.Failed ("Wrong cancellation result for type Money");
   end if;

                       ---=---=---=---=---=---=---


   Money_Actual := Data.Test_Money_Ops (0.0,
                                        Data.Money_Optr_Table_Cumul,
                                        Data.Money_Opnd_Table_Cumul);

   if Money_Actual /= Money_Cumul_Expected then
      Report.Failed ("Wrong cumulation result for type Money");
   end if;


               ---=---=---=---=---=---=---=---=---=---=---


   Cash_Actual := Data.Test_Cash_Ops (0.0,
                                      Data.Cash_Optr_Table_Cancel,
                                      Data.Cash_Opnd_Table_Cancel);

   if Cash_Actual /= Cash_Cancel_Expected then
      Report.Failed ("Wrong cancellation result for type Cash");
   end if;


                       ---=---=---=---=---=---=---


   Cash_Actual := Data.Test_Cash_Ops (0.0,
                                      Data.Cash_Optr_Table_Cumul,
                                      Data.Cash_Opnd_Table_Cumul);

   if Cash_Actual /= Cash_Cumul_Expected then
      Report.Failed ("Wrong cumulation result for type Cash");
   end if;


               ---=---=---=---=---=---=---=---=---=---=---


   Broad_Actual := Data.Test_Broad_Ops (0.0,
                                        Data.Broad_Optr_Table_Cancel,
                                        Data.Broad_Opnd_Table_Cancel);

   if Broad_Actual /= Broad_Cancel_Expected then
      Report.Failed ("Wrong cancellation result for type Broad");
   end if;


                       ---=---=---=---=---=---=---


   Broad_Actual := Data.Test_Broad_Ops (0.0,
                                        Data.Broad_Optr_Table_Cumul,
                                        Data.Broad_Opnd_Table_Cumul);

   if Broad_Actual /= Broad_Cumul_Expected then
      Report.Failed ("Wrong cumulation result for type Broad");
   end if;


               ---=---=---=---=---=---=---=---=---=---=---


   Report.Result;

end CXF2A01;
