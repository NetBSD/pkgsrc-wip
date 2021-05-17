
     --==================================================================--

package body CA11013_2 is

   -- Not a real random number generator.
   function Random_Complex (Seed : My_float) return My_Float is
   begin
      return (Seed + 3.0);    
   end Random_Complex;

end CA11013_2;
