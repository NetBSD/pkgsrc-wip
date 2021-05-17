
     --=================================================================--

package body CA11017_0.CA11017_1 is    

   function Equal_Length (Left  : in String_Rec;
                          Right : in String_Rec) return boolean is
   -- Quick comparison between the lengths of the input strings.

   begin
      return (Left.The_Length = Right.The_Length);  -- Parent's private
                                                    -- type.
   end Equal_Length;
   --------------------------------------------------------------------
   function Same_Content (Left  : in String_Rec;
                          Right : in String_Rec) return boolean is

   begin
      for I in 1 .. Left.The_Length loop
         if Left.The_Content (I) = Right.The_Content (I) then
            return true;
         else
            return false;
         end if;
      end loop;

   end Same_Content;
   --------------------------------------------------------------------
   procedure Copy (From_The_Substring : in     Substring;
                   To_The_String      : in out String_Rec) is
   begin
      To_The_String.The_Content        -- Parent's private type.
        (1 .. From_The_Substring'length) := From_The_Substring;

      To_The_String.The_Length         -- Parent's private type.
                                         := From_The_Substring'length;
   end Copy;

end CA11017_0.CA11017_1;
