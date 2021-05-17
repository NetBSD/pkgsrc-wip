
     --==================================================================--

with C540001_1;
generic               

   type Formal_Int_Type is new C540001_1.Small_Int;

   with function Formal_Func return Formal_Int_Type;

package C540001_4 is

   procedure Gen_Assign_Mixed (P : out C540001_1.Mixed);

end C540001_4;
