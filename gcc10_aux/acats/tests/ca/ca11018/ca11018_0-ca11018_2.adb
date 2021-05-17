
     --=================================================================--

package body CA11018_0.CA11018_2 is    

   procedure Copy (From_The_Word  : in     Message;
                   To_The_Message : in out Message_Type) is

   -- Copy words to the appropriate messages.

   begin
      To_The_Message.The_Content        -- Parent's private type.
        (1 .. From_The_Word'length) := From_The_Word;

      To_The_Message.The_Length         -- Parent's private type.
                                    := From_The_Word'length;
   end Copy;

end CA11018_0.CA11018_2;
