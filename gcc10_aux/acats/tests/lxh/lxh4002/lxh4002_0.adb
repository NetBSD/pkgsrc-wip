
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4002_0 is

  Item_A, Item_B : aliased Item;

  List_C, List_D : List_P;

  procedure Build_OK_List is
  begin
    List_C := Item_A'Access;                                       -- OK
    List_C.Next := Item_B'Access;                                  -- OK
 
    List_D := Item_A'Unchecked_Access;                             -- OK
    List_D.Next := Item_B'Unchecked_Access;                        -- OK
  end Build_OK_List;

  procedure Build_Error_List is
  begin

    List_C := new Item;          -- violate pragma Restrictions(No_Allocators)

    List_D := new Item'(42,List_C);
                                 -- violate pragma Restrictions(No_Allocators)

  end Build_Error_List;

begin

  List_D := Item_A'Unchecked_Access;

  List_D.Next := new Item'(42,List_C);
                                 -- violate pragma Restrictions(No_Allocators)

end LXH4002_0;
