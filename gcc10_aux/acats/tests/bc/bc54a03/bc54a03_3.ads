

     --===================================================================--


with FC54A00;
with BC54A03_0;
with BC54A03_1;
package BC54A03_3 is

--
-- Support declarations for indirection cases:
--

   -- Tagged private case (one level of indirection):

   package Len_Inst  is new BC54A03_0 (FC54A00.Lengths);

   package Tag_Indef is new BC54A03_1 (Len_Inst, FC54A00.Tag);
   package Tag_Class is new BC54A03_1 (Len_Inst, FC54A00.Tag'Class);
   package Tag_Def   is new BC54A03_1 (Len_Inst, FC54A00.Tag20);
   package Tag_Nonst is new BC54A03_1 (Len_Inst, FC54A00.Tag20_Nonstatic);


   -- Tagged discrete case (two levels of indirection):

   type Tag_Rec is tagged null record;

   package Dis_Numerals      is new BC54A03_0 (FC54A00.Numerals);
   package Dis_Static        is new BC54A03_1 (Dis_Numerals, Tag_Rec);

   package Dis_Pos_Nonstatic is new BC54A03_0 (FC54A00.Positive_Nonstatic);
   package Dis_Nonstatic     is new BC54A03_1 (Dis_Pos_Nonstatic, Tag_Rec);


end BC54A03_3;
