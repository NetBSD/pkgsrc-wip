

     --==================================================================--


package CXF2005_1 is

               ---=---=---=---=---=---=---=---=---=---=---

   type Interest_Rate is delta 0.001 range 0.0 .. 1_000.0;
   for Interest_Rate'Small use 0.001;            -- Power of 10.

               ---=---=---=---=---=---=---=---=---=---=---

   type Money_Radix2 is delta 0.01 digits 11;    -- range -999,999,999.99 ..
   for Money_Radix2'Machine_Radix use 2;         --       +999,999,999.99

   function Factor (Rate     : Interest_Rate;
                    Interval : Integer) return Money_Radix2;

               ---=---=---=---=---=---=---=---=---=---=---

   type Money_Radix10 is delta 0.01 digits 11;   -- range -999,999,999.99 ..
   for Money_Radix10'Machine_Radix use 10;       --       +999,999,999.99

   function Factor (Rate   : Interest_Rate;
                    Interval : Integer) return Money_Radix10;

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2005_1;
