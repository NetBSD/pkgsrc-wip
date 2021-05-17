
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_1;
package B460002_1_InstanceL0 is new B460002_1
  (Designated_Type         => B460002_0.Tagged_Type,
   Formal_Operand_Type     => B460002_0.External_Operand_Type_L0,
   Formal_Operand          => B460002_0.Operand_L0,
   Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
   Formal_AccDisc          => B460002_0.AccDisc_L0);                  -- OK.
