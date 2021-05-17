

     --===================================================================--


package CC54003_1 is

   subtype Message     is String;
   type    Message_Ptr is access Message;

   function Add_Prefix (Msg_Ptr : Message_Ptr) return Message_Ptr;
   function Add_Suffix (Msg_Ptr : Message_Ptr) return Message_Ptr;

   -- ...Other operations.

end CC54003_1;
