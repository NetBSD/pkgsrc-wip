
package body CXA40220 is

   function Equiv (Ch : Character) return Wide_Character is
      C : Character := Ch;
   begin
      if Ch = ' ' then
         return Ada.Characters.Handling.To_Wide_Character(C);
      else
         return Wide_Character'Val(Character'Pos(Ch) + 
                Character'Pos(Character'Last) + 1);
      end if;
   end Equiv;


   function Equiv (Str : String) return Wide_String is
      WS : Wide_String(Str'First..Str'Last);
   begin
      for i in Str'First..Str'Last loop
         WS(i) := Equiv(Str(i));
      end loop;
      return WS;
   end Equiv;


   function AB_to_US_Mapping_Function (From : Wide_Character) 
     return Wide_Character is
      UnderScore : constant Wide_Character := Equiv('_');
   begin
      if From = Equiv('a')  or  From = Equiv('b')  then
         return UnderScore;
      else
         return From;
      end if;
   end AB_to_US_Mapping_Function;


   function AB_to_Blank_Mapping_Function (From : Wide_Character) 
     return Wide_Character is
   begin
      if From = Equiv('a')  or  From = Equiv('b') then
         return Ada.Strings.Wide_Space;
      else
         return From;
      end if;
   end AB_to_Blank_Mapping_Function;

end CXA40220;
