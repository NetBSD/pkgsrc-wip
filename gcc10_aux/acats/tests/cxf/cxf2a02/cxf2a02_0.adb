

     --==================================================================--


package body CXF2A02_0 is

               ---=---=---=---=---=---=---=---=---=---=---

   function Multiply (Left, Right : Micro) return Micro is
   begin
      return (Left * Right); -- Decimal fixed multiplication.
   end Multiply;

   function Divide (Left, Right : Micro) return Micro is
   begin
      return (Left / Right); -- Decimal fixed division.
   end Divide;

               ---=---=---=---=---=---=---=---=---=---=---

   function Multiply (Left, Right : Basic) return Basic is
   begin
      return (Left * Right); -- Decimal fixed multiplication.
   end Multiply;

   function Divide (Left, Right : Basic) return Basic is
   begin
      return (Left / Right); -- Decimal fixed division.
   end Divide;

               ---=---=---=---=---=---=---=---=---=---=---

   function Multiply (Left, Right : Broad) return Broad is
   begin
      return (Left * Right); -- Decimal fixed multiplication.
   end Multiply;

   function Divide (Left, Right : Broad) return Broad is
   begin
      return (Left / Right); -- Decimal fixed division.
   end Divide;

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2A02_0;
