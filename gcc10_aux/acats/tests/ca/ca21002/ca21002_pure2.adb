
with CA21002_Pure1;
package body CA21002_Pure2 is

   function Quad (I : in Integer) return Integer is
   begin
      return CA21002_Pure1.Double(I) * 2;
   end Quad;

end CA21002_Pure2;
