
with Report; -- OK only if Is_Pure = False.
package body CA21002_Pure1 is

   function Double (I : in Integer) return Integer is
   begin
      Report.Comment ("In Pure1.Double");
      return I * 2;
   end Double;

end CA21002_Pure1;
