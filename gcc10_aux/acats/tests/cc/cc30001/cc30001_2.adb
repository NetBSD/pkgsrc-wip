

     --==================================================================--


package body CC30001_2 is

   procedure Send (Item : in out Sys_Message) is
   begin
      -- ... Code to send message omitted for brevity.
      Item.Message_Sent := False;  -- Ensure this procedure gives a different
   end Send;                       -- result than CC30001_1.Send.

end CC30001_2;
