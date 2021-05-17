

     --==================================================================--


package body FC70B00 is

   function End_Of_List (L : List_Type) return Boolean is
   begin
      return (L.Current = null);
   end End_Of_List;


   procedure View_Element (L : in List_Type; E : out Element_Type) is
   begin
      -- ... Error-checking code omitted for brevity.
      E := L.Current.Item;               -- Retrieve current element.
   end View_Element;


   procedure Read_Element (L : in out List_Type; E : out Element_Type) is
   begin
      -- ... Error-checking code omitted for brevity.
      E         := L.Current.Item;       -- Retrieve current element.
      L.Current := L.Current.Next;       -- Advance "current" pointer.
   end Read_Element;


   procedure Write_Element (L : in out List_Type; E : in Element_Type) is
   begin
      -- ... Error-checking code omitted for brevity.
      L.Current.Item := E;               -- Write to current element.
      L.Current      := L.Current.Next;  -- Advance "current" pointer.
   end Write_Element;


   procedure Add_Element (L : in out List_Type; E : in Element_Type) is
      New_Node : Node_Pointer := new Node_Type'(E, null); 
   begin
      if L.First = null then             -- No elements in list, so add new
         L.First := New_Node;            -- element at beginning of list.
      else
         L.Last.Next := New_Node;        -- Add new element at end of list.
      end if;
      L.Last := New_Node;                -- Set last-in-list pointer.
   end Add_Element;


   procedure Reset (L : in out List_Type) is
   begin
      L.Current := L.First;              -- Set "current" pointer to first
   end Reset;                            -- list element.


end FC70B00;
