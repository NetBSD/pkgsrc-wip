

     --===================================================================--


package body CC54003_1 is

   function Add_Prefix (Msg_Ptr : Message_Ptr) return Message_Ptr is
      Sender  : constant String := "Dummy: ";    -- Artificial; in a real
                                                 -- application Sender might
      New_Msg : Message := Sender & Msg_Ptr.all; -- be a call to a function.
   begin
      return new Message'(New_Msg);
   end Add_Prefix;


   function Add_Suffix (Msg_Ptr : Message_Ptr) return Message_Ptr is
      Time : constant String := " (12:03pm)";    -- Artificial; in a real
                                                 -- application Time might be a
      New_Msg : Message := Msg_Ptr.all & Time;   -- be a call to a function.
   begin
      return new Message'(New_Msg);
   end Add_Suffix;

end CC54003_1;
