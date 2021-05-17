
with Ada.Tags;
package C390012_Manager is

   procedure Register (The_Tag : in Ada.Tags.Tag; Code : in Character);

   function Decode (Code : in Character) return Ada.Tags.Tag;

   type Dummy is tagged null record; -- A tagged type not related to Object.

end C390012_Manager;
