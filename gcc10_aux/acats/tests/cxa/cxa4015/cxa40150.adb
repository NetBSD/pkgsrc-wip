
package body CXA40150 is

   function AK_to_ZQ_Mapping (From : Wide_Character) 
     return Wide_Character is
   begin
      if From = 'a' then
         return 'z';
      elsif From = 'k' then
         return 'q';
      else
         return From;
      end if;
   end AK_to_ZQ_Mapping;

end CXA40150;
