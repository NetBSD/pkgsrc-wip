

     --==================================================================--


package body CC70C02_0 is

   procedure Read_Element (L : in out Lists.List_Type;
                           E :    out Lists.Element_Type) is
   begin
      if Basic_List_Ops.End_Of_List (L) then  -- Use of op from the previous
         raise End_Of_List_Reached;           -- generic package.
      else
         E         := L.Current.Item;         -- Retrieve current element.
         L.Current := L.Current.Next;         -- Advance "current" pointer.
      end if;
   end Read_Element;


   procedure Add_Element (L : in out Lists.List_Type;
                          E : in     Lists.Element_Type) is
      New_Node : Lists.Node_Pointer := new Lists.Node_Type'(E, null); 
      use type Lists.Node_Pointer;
   begin
      if L.First = null then                -- No elements in list, so add new
         L.First := New_Node;               -- element at beginning of list.
      else
         L.Last.Next := New_Node;           -- Add new element at end of list.
      end if;
      L.Last := New_Node;                   -- Set last-in-list pointer.
   end Add_Element;


end CC70C02_0;
