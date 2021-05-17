

     --==================================================================--


package body CXF2A01_0 is

               ---=---=---=---=---=---=---=---=---=---=---

   function Add (Left, Right : Micro) return Micro is
   begin
      return (Left + Right); -- Decimal fixed addition.
   end Add;

   function Subtract (Left, Right : Micro) return Micro is
   begin
      return (Left - Right); -- Decimal fixed subtraction.
   end Subtract;

               ---=---=---=---=---=---=---=---=---=---=---

   function Add (Left, Right : Money) return Money is
   begin
      return (Left + Right); -- Decimal fixed addition.
   end Add;

   function Subtract (Left, Right : Money) return Money is
   begin
      return (Left - Right); -- Decimal fixed subtraction.
   end Subtract;

               ---=---=---=---=---=---=---=---=---=---=---

   function Add (Left, Right : Cash) return Cash is
   begin
      return (Left + Right); -- Decimal fixed addition.
   end Add;

   function Subtract (Left, Right : Cash) return Cash is
   begin
      return (Left - Right); -- Decimal fixed subtraction.
   end Subtract;

               ---=---=---=---=---=---=---=---=---=---=---

   function Add (Left, Right : Broad) return Broad is
   begin
      return (Left + Right); -- Decimal fixed addition.
   end Add;

   function Subtract (Left, Right : Broad) return Broad is
   begin
      return (Left - Right); -- Decimal fixed subtraction.
   end Subtract;

               ---=---=---=---=---=---=---=---=---=---=---

end CXF2A01_0;
