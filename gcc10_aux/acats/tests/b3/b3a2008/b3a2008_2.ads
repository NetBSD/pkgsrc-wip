

     --==================================================================--


with B3A2008_0;
with B3A2008_1;
package B3A2008_2 is
  new B3A2008_1 (B3A2008_0.New_Tagged_Rec,
                 B3A2008_0.Acc_NTag_L0,
                 B3A2008_0.Rec,
                 B3A2008_0.Acc1_Rec_L0,
                 B3A2008_0.Acc2_Rec_L0);                     -- OK. {5:1;1}
