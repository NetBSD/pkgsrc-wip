
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_5;
package B460002_5_InstanceL0 is new B460002_5
  (Designated_Type     => B460002_0.Tagged_Type,
   Formal_Operand_Type => B460002_0.External_Operand_Type_L0,
   Formal_Operand      => B460002_0.Operand_L0,
   Formal_Target_Type  => B460002_0.External_Target_Type_L0);         -- OK.
