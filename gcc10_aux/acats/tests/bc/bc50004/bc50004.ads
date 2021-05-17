

     --==================================================================--


with BC50004_0;
with BC50004_1;
package BC50004 is

   package Ordinary_OK_Actual is new BC50004_1.Ordinary_Fixed_Formal
      (Formal_Ordinary_Fixed => BC50004_0.Ordinary_Fixed);            -- OK.

   package Ordinary_Bad_Actual is new BC50004_1.Ordinary_Fixed_Formal
      (BC50004_0.Decimal_Fixed);                                      -- ERROR:
                                      -- Actual is decimal; formal is ordinary.


   package Decimal_OK_Actual is new BC50004_1.Decimal_Fixed_Formal
      (BC50004_0.Decimal_Fixed);                                      -- OK.

   package Decimal_Bad_Actual is new BC50004_1.Decimal_Fixed_Formal
      (Formal_Decimal_Fixed => BC50004_0.Ordinary_Fixed);             -- ERROR:
                                      -- Actual is ordinary; formal is decimal.

end BC50004;
