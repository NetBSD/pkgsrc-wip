
with Report; -- OK only if Is_Preelab = False.
package body CA21002_Preelab1 is

   procedure Triple (Val : in out Integer) is
   begin
      Report.Comment ("In Preelab1.Triple with" & Integer'Image(Val));
      Val := Val * 3;
   end Triple;

end CA21002_Preelab1;
