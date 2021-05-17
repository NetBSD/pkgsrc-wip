

     --==================================================================--


with CXF2A02_0.CXF2A02_1;

with Report;
procedure CXF2A02 is
   package Data renames CXF2A02_0.CXF2A02_1;

   use type CXF2A02_0.Micro;
   use type CXF2A02_0.Basic;
   use type CXF2A02_0.Broad;

   Micro_Expected : constant CXF2A02_0.Micro := 1.0;
   Basic_Expected : constant CXF2A02_0.Basic := 1.0;
   Broad_Expected : constant CXF2A02_0.Broad := 1.0;

   Micro_Actual   : CXF2A02_0.Micro;
   Basic_Actual   : CXF2A02_0.Basic;
   Broad_Actual   : CXF2A02_0.Broad;
begin

   Report.Test ("CXF2A02", "Check decimal multiplication and division, " &
                "where the operand and result types are the same");

               ---=---=---=---=---=---=---=---=---=---=---

   Micro_Actual := 0.0;
   Micro_Actual := Data.Test_Micro_Ops (1.0,
                                        Data.Micro_Mult_Operator_Table,
                                        Data.Micro_Mult_Operand_Table);

   if Micro_Actual /= Micro_Expected then
      Report.Failed ("Wrong result for type Micro multiplication");
   end if;


   Micro_Actual := 0.0;
   Micro_Actual := Data.Test_Micro_Ops (1.0,
                                        Data.Micro_Div_Operator_Table,
                                        Data.Micro_Div_Operand_Table);

   if Micro_Actual /= Micro_Expected then
      Report.Failed ("Wrong result for type Micro division");
   end if;

               ---=---=---=---=---=---=---=---=---=---=---

   Basic_Actual := 0.0;
   Basic_Actual := Data.Test_Basic_Ops (1.0,
                                        Data.Basic_Mult_Operator_Table,
                                        Data.Basic_Mult_Operand_Table);

   if Basic_Actual /= Basic_Expected then
      Report.Failed ("Wrong result for type Basic multiplication");
   end if;


   Basic_Actual := 0.0;
   Basic_Actual := Data.Test_Basic_Ops (1.0,
                                        Data.Basic_Div_Operator_Table,
                                        Data.Basic_Div_Operand_Table);

   if Basic_Actual /= Basic_Expected then
      Report.Failed ("Wrong result for type Basic division");
   end if;

               ---=---=---=---=---=---=---=---=---=---=---

   Broad_Actual := 0.0;
   Broad_Actual := Data.Test_Broad_Ops (1.0,
                                        Data.Broad_Mult_Operator_Table,
                                        Data.Broad_Mult_Operand_Table);

   if Broad_Actual /= Broad_Expected then
      Report.Failed ("Wrong result for type Broad multiplication");
   end if;


   Broad_Actual := 0.0;
   Broad_Actual := Data.Test_Broad_Ops (1.0,
                                        Data.Broad_Div_Operator_Table,
                                        Data.Broad_Div_Operand_Table);

   if Broad_Actual /= Broad_Expected then
      Report.Failed ("Wrong result for type Broad division");
   end if;

               ---=---=---=---=---=---=---=---=---=---=---

   Report.Result;

end CXF2A02;
