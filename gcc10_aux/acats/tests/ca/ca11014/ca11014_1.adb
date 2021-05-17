
     --==================================================================--

package body CA11014_1 is

   procedure Write_Element (L : in out List_Mgr.List_Type; 
                            E : in     List_Mgr.Element_Type) is
   begin
      L.Current.Item := E;               -- Write to current element.
      L.Current      := L.Current.Next;  -- Advance "current" pointer.
   end Write_Element;
   -------------------------------------------------------
   procedure Read_Element (L : in out List_Mgr.List_Type; 
                           E :    out List_Mgr.Element_Type) is
   begin
      E         := L.Current.Item;       -- Retrieve current element.
      L.Current := L.Current.Next;       -- Advance "current" pointer.
   end Read_Element;
   -------------------------------------------------------
   procedure Add_Element (L : in out List_Mgr.List_Type; 
                          E : in     List_Mgr.Element_Type) is
      New_Node : List_Mgr.Node_Pointer := new List_Mgr.Node_Type'(E, null); 
       use type List_Mgr.Node_Pointer;
   begin
      if L.First = null then                -- No elements in list, so add new
         L.First := New_Node;               -- element at beginning of list.
      else
         L.Last.Next := New_Node;           -- Add new element at end of list.
      end if;
      L.Last := New_Node;                   -- Set last-in-list pointer.
   end Add_Element;

end CA11014_1;
