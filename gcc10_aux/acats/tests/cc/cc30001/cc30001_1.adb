

     --==================================================================--


package body CC30001_1 is

   procedure Send (M : in out Mail_Type) is
   begin
      -- ... Code to send message omitted for brevity.
      M.Message_Sent := True;
   end Send;

end CC30001_1;
