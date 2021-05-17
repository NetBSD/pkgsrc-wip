
     --=================================================================--

                               -- Grandchild Package body Message.Text.Encoded
package body CA110050_0.CA110050_1.CA110050_2 is 

   procedure Send (Message : in     Coded_Message;
                   Confirm :    out Coded_Message;
                   Status  :    out Boolean) is

      Confirmation_Message : Coded_Message :=
        (Number    => Message.Number,
         Text      => Confirm_Text,
         Key       => Message.Number,
         Coded_Key => Message.Number,
         Scrambled => Scrambled_Text);  

   begin                                          -- Dummy processing unit.
      Confirm := Confirmation_Message;
      if Confirm.Number /= Null_Message_Descriptor then
         Status := True;                            
      else
         Status := False;
      end if;
   end Send;
   -------------------------------------------------------------------------
   function Encode (Message : Text_Message_Type)  return Coded_Message is
   begin
      Coded_Msg.Number       := Message.Number;
      if Message.Text.Length > 0 then
         Coded_Msg.Text      := Message.Text;     -- Record assignment.
         Coded_Msg.Key       := Message.Number;   -- Same as msg number.
         Coded_Msg.Coded_Key := Message.Number;   -- Same as msg number.
         Coded_Msg.Scrambled := Message.Text;     -- Dummy processing.
      end if;
      return (Coded_Msg);
   end Encode;
   -------------------------------------------------------------------------
   function Decode (Message : Coded_Message) return Boolean is
      Decoded : Boolean := False;
   begin                                                       
      if (Message.Text.Length = Confirm_String'Length)        and then
         (Message.Text.Text_Field = Confirm_String)           and then
         (Message.Scrambled.Length = Scrambled_String'Length) and then
         (Message.Scrambled.Text_Field = Scrambled_String)    and then
         (Message.Coded_Key = 15)
      then
         Decoded := True;
      end if;
      return (Decoded);
   end Decode;
   -------------------------------------------------------------------------
   function Test_Connection return Boolean is
   begin
      return Test_Message.Id = 10;
   end Test_Connection;

end CA110050_0.CA110050_1.CA110050_2;        
