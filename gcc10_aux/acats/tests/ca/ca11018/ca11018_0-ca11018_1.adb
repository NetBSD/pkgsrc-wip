
     --=================================================================--

package body CA11018_0.CA11018_1 is    

   function Find_Word (Wrd : in Message;
                       Msg : in Msg_Type) return Count is

      Num  : Count   := Count'first;

   -- Count how many time the word appears within the given message.

   begin
      -- ... Error-checking code omitted for brevity.

      for I in 1 .. (Msg.The_Length - Wrd'length + 1) loop
                                                 -- Parent's private type
         if Msg.The_Content (I .. I + Wrd'length - 1) = Wrd
                                                 -- Parent's private type
           then
              Num := Num + 1;
         end if;

      end loop;

      TC_Function_Called := true;

      return (Num);

   end Find_Word;

end CA11018_0.CA11018_1;
