
with CXAC009_Logger;
package body CXAC009_Test is

   procedure Do_Something is
   begin
      CXAC009_Logger.Log_Item ("Something");
      null;
      CXAC009_Logger.Log_Item ("Do more");
   end Do_Something;

end CXAC009_Test;
