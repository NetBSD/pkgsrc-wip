
with Ada.Characters.Handling;
package body CXA4025_0 is
      -- Function Map_To_Lower_Case will return the lower case form of 
      -- Wide_Characters in the range 'A'..'Z' only, and return the input
      -- wide_character otherwise.

      function Map_To_Lower_Case (From : Wide_Character) 
         return Wide_Character is
      begin
         return Ada.Characters.Handling.To_Wide_Character(
                  Ada.Characters.Handling.To_Lower(
                    Ada.Characters.Handling.To_Character(From)));
      end Map_To_Lower_Case;

      -- Function Map_To_Upper_Case will return the upper case form of 
      -- Wide_Characters in the range 'a'..'z', or whose position is in one
      -- of the ranges 223..246 or 248..255, provided the wide_character has
      -- an upper case form.               

      function Map_To_Upper_Case (From : Wide_Character) 
        return Wide_Character is
      begin
         return Ada.Characters.Handling.To_Wide_Character(
                  Ada.Characters.Handling.To_Upper(
                    Ada.Characters.Handling.To_Character(From)));
      end Map_To_Upper_Case;

end CXA4025_0;
