

     --==================================================================--


with B3A2012_0;
with B3A2012_1;
package B3A2012_2 is
  new B3A2012_1 (B3A2012_0.Tag_Desig,
                 B3A2012_0.Acc_to_Tag_L0,
                 B3A2012_0.TObj_L0,
                 B3A2012_0.Acc_to_Tag_L0,
                 B3A2012_0.Comp_L0.C,
                 B3A2012_0.Acc_to_Tag_L0,
                 B3A2012_0.Derf_L0.all);                     -- OK. {7:1;1}
