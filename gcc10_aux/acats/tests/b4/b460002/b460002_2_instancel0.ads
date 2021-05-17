
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_2;
package B460002_2_InstanceL0 is new B460002_2
  (Designated_Type    => B460002_0.Tagged_Type,
   Formal_Target_Type => B460002_0.External_Target_Type_L0);          -- OK.
