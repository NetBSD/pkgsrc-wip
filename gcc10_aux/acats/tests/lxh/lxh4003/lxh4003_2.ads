                                                -- library level instance

----------------------------------------------------------------- LXH4003_2

package LXH4003_2 is

  type Item;

  type List_P is access all Item;

  type Item is record
    Data : Natural;
    Next : List_P;
  end record;
 
  Global_List : List_P := new Item'(0,new Item'(1,null));         -- OK
                                                 -- non-local allocator

  procedure Build_OK_List;

private
  Item_A, Item_B : aliased Item;

  List_C, List_D : List_P;

end LXH4003_2;
