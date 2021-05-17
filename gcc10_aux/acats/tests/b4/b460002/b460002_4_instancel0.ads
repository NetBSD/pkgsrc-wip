
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_4;
package B460002_4_InstanceL0 is new B460002_4
  (Designated_Type     => B460002_0.Tagged_Type,
   Formal_Operand_Type => B460002_0.External_Operand_Type_L0);        -- OK.
