

     --==================================================================--


package CXF2002_1 is

   type Money_Radix2 is delta 0.01 digits 11;  -- range -999,999,999.99 ..
   for Money_Radix2'Machine_Radix use 2;       --       +999,999,999.99


   type Money_Radix10 is delta 0.01 digits 11; -- range -999,999,999.99 ..
   for Money_Radix10'Machine_Radix use 10;     --       +999,999,999.99

end CXF2002_1;
