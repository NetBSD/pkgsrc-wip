

     --==================================================================--


package body F340A000 is  -- Singly-linked list abstraction.

   procedure Add (Item : in     Node_Ptr;
                  Head : in out Node_Ptr) is
   begin
      if Item /= null then
         Item.Next := Head;
         Head := Item;
      end if;
   end Add;


   procedure Remove (Head : in out Node_Ptr;
                     Item :    out Node_Ptr) is
   begin
      Item := Head;
      if Head /= null then
         Head := Head.Next;
      end if;
   end Remove;


   procedure Add (Item : in     Priv_Node_Ptr;
                  Head : in out Priv_Node_Ptr) is
   begin
      if Item /= null then
         Item.Next := Head;
         Head := Item;
      end if;
   end Add;


   procedure Remove (Head : in out Priv_Node_Ptr;
                     Item :    out Priv_Node_Ptr) is
   begin
      Item := Head;
      if Head /= null then
         Head := Head.Next;
      end if;
   end Remove;


end F340A000;
