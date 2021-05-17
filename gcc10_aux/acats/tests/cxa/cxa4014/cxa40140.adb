
package body CXA40140 is

   function US_to_Blank_Map (From : Wide_Character) return Wide_Character is
   begin
      if From = UnderScore then
         return Blank;
      else
         return From;
      end if;
   end US_to_Blank_Map;

end CXA40140;
