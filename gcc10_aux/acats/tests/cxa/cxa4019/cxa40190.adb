
package body CXA40190 is

   -- Translates "dog" to "cat".
   function Dog_to_Cat_Mapping (From : Wide_Character) 
     return Wide_Character is
   begin
      if From = 'd' then
         return 'c';
      elsif From = 'o' then
         return 'a';
      elsif From = 'g' then
         return 't';
      else
         return From;
      end if;
   end Dog_to_Cat_Mapping;

end CXA40190;
