

     --==================================================================--


with B3A2011_0;
with B3A2011_1;
package B3A2011_2 is
  new B3A2011_1 (B3A2011_0.Tag_Desig,
                 B3A2011_0.Acc_to_Tag_L0,
                 B3A2011_0.TObj1_L0,
                 B3A2011_0.Acc_to_Tag_L0,
                 B3A2011_0.TObj2_L0,
                 B3A2011_0.Acc_to_Tag_L0,
                 B3A2011_0.TObj3_L0);                        -- OK. {7:1;1}
