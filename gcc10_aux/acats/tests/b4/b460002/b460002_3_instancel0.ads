
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_3;
package B460002_3_InstanceL0 is new B460002_3
  (Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
   Formal_AccDisc          => B460002_0.AccDisc_L0);                  -- OK.
