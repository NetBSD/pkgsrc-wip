

     --==================================================================--


with FXF2A00;
package CXF2A01_0.CXF2A01_1 is

               ---=---=---=---=---=---=---=---=---=---=---

   type Micro_Ops   is array (FXF2A00.Optr_Range) of Micro_Optr_Ptr;
   type Micro_Opnds is array (FXF2A00.Opnd_Range) of Micro;

   Micro_Optr_Table_Cancel : Micro_Ops   := ( Micro_Add, Micro_Sub,
                                              Micro_Add, Micro_Sub,
                                              Micro_Add, Micro_Sub );

   Micro_Optr_Table_Cumul  : Micro_Ops   := ( others => Micro_Add );

   Micro_Opnd_Table_Cancel : Micro_Opnds := ( 0.001025000235111997,
                                              0.000000000000000003,
                                              0.724902903219925400,
                                              0.000459228020000011,
                                              0.049832104921096533 );

   Micro_Opnd_Table_Cumul  : Micro_Opnds := ( 0.000002309540000000,
                                              0.000000278060000000,
                                              0.000000000000070000,
                                              0.000010003000000000,
                                              0.000000023090000000 );

   function Test_Micro_Ops is new FXF2A00.Operations_Loop
     (Decimal_Fixed  => Micro,
      Operator_Ptr   => Micro_Optr_Ptr,
      Operator_Table => Micro_Ops,
      Operand_Table  => Micro_Opnds);

               ---=---=---=---=---=---=---=---=---=---=---

   type Money_Ops   is array (FXF2A00.Optr_Range) of Money_Optr_Ptr;
   type Money_Opnds is array (FXF2A00.Opnd_Range) of Money;

   Money_Optr_Table_Cancel : Money_Ops   := ( Money_Add, Money_Add,
                                              Money_Sub, Money_Add,
                                              Money_Sub, Money_Sub );

   Money_Optr_Table_Cumul  : Money_Ops   := ( others => Money_Sub );

   Money_Opnd_Table_Cancel  : Money_Opnds := (       127.10,
                                                    5600.44,
                                                       0.05,
                                                  189662.78,
                                               226900402.99  );

   Money_Opnd_Table_Cumul   : Money_Opnds := (        17.99,
                                                     500.41,
                                                      92.78,
                                                       0.38,
                                                    2942.99  );

   function Test_Money_Ops is new FXF2A00.Operations_Loop
     (Decimal_Fixed  => Money,
      Operator_Ptr   => Money_Optr_Ptr,
      Operator_Table => Money_Ops,
      Operand_Table  => Money_Opnds);

               ---=---=---=---=---=---=---=---=---=---=---

   type Cash_Ops   is array (FXF2A00.Optr_Range) of Cash_Optr_Ptr;
   type Cash_Opnds is array (FXF2A00.Opnd_Range) of Cash;

   Cash_Optr_Table_Cancel : Cash_Ops   := ( Cash_Add, Cash_Add,
                                            Cash_Sub, Cash_Add,
                                            Cash_Sub, Cash_Sub );

   Cash_Optr_Table_Cumul  : Cash_Ops   := ( others => Cash_Add );

   Cash_Opnd_Table_Cancel : Cash_Opnds := (       127.10,
                                                 5600.44,
                                                    0.05,
                                               189662.78,
                                            226900402.99  );

   Cash_Opnd_Table_Cumul  : Cash_Opnds := (         3.33,
                                               100056.14,
                                                   22.87,
                                                 3901.55,
                                                  111.21  );

   function Test_Cash_Ops is new FXF2A00.Operations_Loop
     (Decimal_Fixed  => Cash,
      Operator_Ptr   => Cash_Optr_Ptr,
      Operator_Table => Cash_Ops,
      Operand_Table  => Cash_Opnds);

               ---=---=---=---=---=---=---=---=---=---=---

   type Broad_Ops   is array (FXF2A00.Optr_Range) of Broad_Optr_Ptr;
   type Broad_Opnds is array (FXF2A00.Opnd_Range) of Broad;

   Broad_Optr_Table_Cancel : Broad_Ops   := ( Broad_Sub, Broad_Add,
                                              Broad_Add, Broad_Sub,
                                              Broad_Sub, Broad_Add );

   Broad_Optr_Table_Cumul  : Broad_Ops   := ( others => Broad_Sub );

   Broad_Opnd_Table_Cancel : Broad_Opnds := (         1.000009092,
                                              732919479.445022293,
                                                  89662.787000006,
                                                    660.101010133,
                                                1121127.999905594  );

   Broad_Opnd_Table_Cumul  : Broad_Opnds := (        12.000450223,
                                                    479.430320780,
                                                      0.003492096,
                                                      8.112888400,
                                                   1002.994937800  );

   function Test_Broad_Ops is new FXF2A00.Operations_Loop
     (Decimal_Fixed  => Broad,
      Operator_Ptr   => Broad_Optr_Ptr,
      Operator_Table => Broad_Ops,
      Operand_Table  => Broad_Opnds);

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2A01_0.CXF2A01_1;
