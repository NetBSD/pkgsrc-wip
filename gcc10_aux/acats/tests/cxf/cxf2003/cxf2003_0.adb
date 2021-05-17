

     --==================================================================--


package body CXF2003_0 is

   procedure Multiply_And_Truncate (Balance : in out Decimal_Fixed_1;
                                    Factor  : in     Decimal_Fixed_2) is
      Interest : Decimal_Fixed_1;
   begin
      Interest := Factor * Balance;      -- Fixed-fixed multiplication.
      Balance  := Balance + Interest;
   end Multiply_And_Truncate;


   procedure Divide_And_Truncate (Balance : in out Decimal_Fixed_1;
                                  Divisor : in     Decimal_Fixed_2) is
      Interest : Decimal_Fixed_1;
   begin
      Interest := Balance / Divisor;     -- Fixed-fixed division.
      Balance  := Balance + Interest;
   end Divide_And_Truncate;


   procedure Multiply_And_Round (Balance : in out Decimal_Fixed_1;
                                 Factor  : in     Decimal_Fixed_2) is
      Interest : Decimal_Fixed_1;
   begin
                                         -- Fixed-fixed multiplication.
      Interest := Decimal_Fixed_1'Round ( Factor * Balance );
      Balance  := Balance + Interest;
   end Multiply_And_Round;


   procedure Divide_And_Round (Balance : in out Decimal_Fixed_1;
                               Divisor : in     Decimal_Fixed_2) is
      Interest : Decimal_Fixed_1;
   begin
                                         -- Fixed-fixed division.
      Interest := Decimal_Fixed_1'Round ( Balance / Divisor );
      Balance  := Balance + Interest;
   end Divide_And_Round;

end CXF2003_0;
