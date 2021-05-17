

     --==================================================================--

package body C840001_0 is

   function "**" (Left: Precision_Float; Right: Integer'Base)
     return Precision_Float is
   begin
      -- ... Utilize desired algorithm.
      return (TC_Expected);  -- Artificial for testing purposes.
   end "**";

   function "+" (Right: Precision_Float)
     return Precision_Float is
   -- Overrides predefined operator.
   begin
      return Right*2.0;
   end "+";

end C840001_0;
