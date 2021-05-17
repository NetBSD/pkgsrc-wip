
     --==================================================================--

with C540001_1;
generic               

   type Formal_Enum_Type is new C540001_1.Enum_Type;

   with function Formal_Func (P : C540001_1.Small_Num) 
     return Formal_Enum_Type is <>;

function C540001_3 (P : C540001_1.Small_Num) return Formal_Enum_Type;
