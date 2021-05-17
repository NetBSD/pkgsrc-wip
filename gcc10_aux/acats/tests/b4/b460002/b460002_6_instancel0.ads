
               --==============================================--

                                                               -- [ Level = 0 ]
with B460002_0;
with B460002_6;
package B460002_6_InstanceL0 is new B460002_6
  (Designated_Type         => B460002_0.Tagged_Type,
   Formal_Target_Type      => B460002_0.External_Target_Type_L0,
   Formal_Disc_Record_Type => B460002_0.Disc_Record_Type,
   Formal_AccDisc          => B460002_0.AccDisc_L0);                  -- OK.
