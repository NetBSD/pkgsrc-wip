

     --==================================================================--


package BC50004_1 is

   generic
      type Formal_Ordinary_Fixed is delta <>;
   package Ordinary_Fixed_Formal is end;

   generic
      type Formal_Decimal_Fixed is delta <> digits <>;
   package Decimal_Fixed_Formal is end;

end BC50004_1;
