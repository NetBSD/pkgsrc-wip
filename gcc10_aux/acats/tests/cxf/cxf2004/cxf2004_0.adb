

     --==================================================================--


package body CXF2004_0 is

   procedure Multiply_And_Truncate (Balance : in out Decimal_Fixed;
                                    Factor  : in     Ordinary_Fixed) is
      Interest : Decimal_Fixed;
   begin
      Interest := Factor * Balance;      -- Fixed-fixed multiplication.
      Balance  := Balance + Interest;
   end Multiply_And_Truncate;


   procedure Divide_And_Truncate (Balance : in out Decimal_Fixed;
                                  Divisor : in     Ordinary_Fixed) is
      Interest : Decimal_Fixed;
   begin
      Interest := Balance / Divisor;     -- Fixed-fixed division.
      Balance  := Balance + Interest;
   end Divide_And_Truncate;


   procedure Multiply_And_Round (Balance : in out Decimal_Fixed;
                                 Factor  : in     Ordinary_Fixed) is
      Interest : Decimal_Fixed;
   begin
                                         -- Fixed-fixed multiplication.
      Interest := Decimal_Fixed'Round ( Factor * Balance );
      Balance  := Balance + Interest;
   end Multiply_And_Round;


   procedure Divide_And_Round (Balance : in out Decimal_Fixed;
                               Divisor : in     Ordinary_Fixed) is
      Interest : Decimal_Fixed;
   begin
                                         -- Fixed-fixed division.
      Interest := Decimal_Fixed'Round ( Balance / Divisor );
      Balance  := Balance + Interest;
   end Divide_And_Round;

end CXF2004_0;
