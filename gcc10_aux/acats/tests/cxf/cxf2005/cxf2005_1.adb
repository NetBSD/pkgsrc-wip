

     --==================================================================--


package body CXF2005_1 is

               ---=---=---=---=---=---=---=---=---=---=---

   function Factor (Rate   : Interest_Rate;
                    Interval : Integer) return Money_Radix2 is
   begin
      return Money_Radix2( Rate / Interval );
   end Factor;

               ---=---=---=---=---=---=---=---=---=---=---

   function Factor (Rate   : Interest_Rate;
                    Interval : Integer) return Money_Radix10 is
   begin
      return Money_Radix10( Rate / Interval );
   end Factor;

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2005_1;
