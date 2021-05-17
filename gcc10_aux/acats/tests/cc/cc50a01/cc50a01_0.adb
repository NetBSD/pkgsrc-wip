

     --==================================================================--


package body CC50A01_0 is

   -- Link NewItem in at the top of the stack (the extension aggregate within
   -- the allocator initializes the inherited portion of NewItem to equal I,
   -- and NewItem.Next to point to what S.Top points to).

   procedure Push (I : in Item; S : in out Stack) is
      NewItem : Stack_Ptr;
   begin
      NewItem := new Stack_Item'(I with S.Top);     -- Extension aggregate.
      S.Top   := NewItem;
      S.Size  := S.Size + 1;
   end Push;


   -- Remove item from top of stack. This procedure only updates the state of
   -- the stack; it does not return the value of the popped item. Hence, in
   -- order to accomplish a "true" pop, both View_Top and Pop must be called
   -- consecutively.
   --
   -- If the stack is empty, the Pop is ignored (for simplicity; in a true
   -- application this might be treated as an error condition).

   procedure Pop (S : in out Stack) is
   begin
      if S.Top = null then                          -- Stack is empty.
         null;
         -- Raise exception.
      else
         S.Top  := S.Top.Next;
         S.Size := S.Size - 1;
         -- Deallocate discarded node.
      end if;
   end Pop;


   -- Return the value of the top item on the stack. This procedure only
   -- returns the value; it does not remove the top item from the stack.
   -- Hence, in order to accomplish a "true" pop, both View_Top and Pop must
   -- be called consecutively.
   --
   -- Since items on the stack are of a type (Stack_Item) derived from Item,
   -- which is a (tagged) private type, type conversion toward the root is the
   -- only way to get a value of type Item for return to the caller.
   --
   -- If the stack is empty, View_Top returns a pre-specified default value.
   -- (In a true application, an exception might be raised instead).

   function View_Top (S : Stack) return Item is
   begin
      if S.Top = null then                          -- Stack is empty.
         return TC_Default_Value;                   -- Testing artifice.
         -- Raise exception.
      else
         return Item(S.Top.all);                    -- Type conversion.
      end if;
   end View_Top;


   function Size_Of (S : Stack) return Natural is
   begin
      return (S.Size);
   end Size_Of;


end CC50A01_0;
