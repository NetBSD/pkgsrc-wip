
with TCTouch;
package body C390012_Manager is

   Map : array (Character) of Ada.Tags.Tag := (others => Ada.Tags.No_Tag);

   procedure Register (The_Tag : in Ada.Tags.Tag; Code : in Character) is
      use type Ada.Tags.Tag;
   begin
      TCTouch.Touch ('r'); TCTouch.Touch (Code); ------------------ "r<code>"
      if Map(Code) /= Ada.Tags.No_Tag then
         raise Program_Error with "Double Registration of code " & Code;
      end if;
      Map(Code) := The_Tag;
   end Register;

   function Decode (Code : in Character) return Ada.Tags.Tag is
   begin
      return Map(Code);
   end Decode;

end C390012_Manager;
