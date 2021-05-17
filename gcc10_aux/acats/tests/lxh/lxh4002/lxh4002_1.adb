
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4002_1 is

  Item_A, Item_B : aliased Item;

  List_C, List_D : List_P;

  procedure Build_OK_List is
  begin
    List_C := Item_A'Access;                                       -- OK
    List_C.Next := Item_B'Access;                                  -- OK
 
    List_D := Item_A'Unchecked_Access;                             -- OK
    List_D.Next := Item_B'Unchecked_Access;                        -- OK
  end Build_OK_List;

begin

  List_D := Item_A'Unchecked_Access;

end LXH4002_1;
