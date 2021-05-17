

     --==================================================================--


package body CC50A02_0 is

   -- Link NewItem in at the top of the stack.

   procedure Push (I : in Item; S : in out Stack) is
      NewItem : Item_Ptr  := new Item'(I);
      Element : Stack_Ptr := new Stack_Item'(Item => NewItem, Next => S.Top);
   begin
      S.Top   := Element;
      S.Size  := S.Size + 1;
   end Push;


   -- Return (copy) of top item on stack. Do NOT remove from stack.

   function View_Top (S : Stack) return Item is
   begin
      if S.Top = null then
         raise Stack_Empty;
      else
         return S.Top.Item.all;
      end if;
   end View_Top;

end CC50A02_0;
