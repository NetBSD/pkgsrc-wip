
     --=================================================================--

-- Public generic child to copy words to the messages.

generic
   type Message_Type is new Message_Rec with private; 
                        -- Derived from parent's type.

package CA11018_0.CA11018_2 is    

   procedure Copy (From_The_Word  : in     Message;
                   To_The_Message : in out Message_Type);

end CA11018_0.CA11018_2;
