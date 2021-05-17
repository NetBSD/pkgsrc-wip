
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with LXH4003_0;
package body LXH4003_2 is

 procedure Build_OK_List is
  begin
    List_C := Item_A'Access;                                       -- OK
    List_C.Next := Item_B'Access;                                  -- OK
 
    List_D := Item_A'Unchecked_Access;                             -- OK
    List_D.Next := Item_B'Unchecked_Access;                        -- OK
  end Build_OK_List;

  procedure Instance is new LXH4003_0( Item, List_P );             -- OK
                                               -- library level instance

end LXH4003_2;
