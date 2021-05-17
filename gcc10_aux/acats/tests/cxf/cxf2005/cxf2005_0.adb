

     --==================================================================--


package body CXF2005_0 is

   function Multiply (Operand  : Decimal_Fixed;
                      Interval : Integer) return Decimal_Fixed is
   begin
      return Operand * Interval;  -- Fixed-Integer multiplication.
   end Multiply;


   function Divide (Operand  : Decimal_Fixed;
                    Interval : Integer) return Decimal_Fixed is
   begin
      return Operand / Interval;  -- Fixed-Integer division.
   end Divide;

end CXF2005_0;
