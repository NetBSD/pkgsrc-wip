
with CXAC007_Logger;
package body CXAC007_Test is

   procedure Do_Something (Log_Name : in String) is
   begin
      CXAC007_Logger.Log_Item (Log_Name, "Doing");
      null;
      CXAC007_Logger.Log_Item (Log_Name, "Do more");
   end Do_Something;

end CXAC007_Test;
