

     --==================================================================--


package body CC51D02_0 is

   -- The implementations of Update_ID are purely artificial; the validity of
   -- their implementations in the context of the abstraction is irrelevant to
   -- the feature being tested.

   procedure Update_ID (Item : in out Blind_ID_Type) is
   begin
      Item.SSN := "111223333";
   end Update_ID;


   procedure Update_ID (Item : in out Named_ID_Type) is
   begin
      Item.SSN := "444556666";
      -- ... Other stuff.
   end Update_ID;

end CC51D02_0;
