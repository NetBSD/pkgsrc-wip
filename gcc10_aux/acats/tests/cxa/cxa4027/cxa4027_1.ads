


-- Function CXA4027_1 will return the upper case form of 
-- Characters in the range 'a'..'z', or whose position is in one
-- of the ranges 223..246 or 248..255, provided the character has
-- an upper case form.

with Ada.Characters.Handling;
function CXA4027_1 (From : Character) return Character;
