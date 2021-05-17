

     --==================================================================--


package body BC51B01_0 is

   -- Stack implementation below is purely artificial; a fully functional
   -- implementation would be longer than is needed to test the objective.

   type Item_Ptr is access Item_Type;
   Top : Item_Ptr;

   procedure Push (E : in Item_Type) is
   begin
      Top := new Item_Type'(E);          -- Does not require definite formal.
   end Push;

end BC51B01_0;
