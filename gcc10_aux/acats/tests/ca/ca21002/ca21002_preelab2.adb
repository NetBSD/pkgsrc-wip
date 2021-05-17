
with CA21002_Preelab1;
package body CA21002_Preelab2 is

   procedure Hex (Val : in out Integer) is
   begin
      CA21002_Preelab1.Triple (Val);
      Val := Val * 2;
   end Hex;

end CA21002_Preelab2;
