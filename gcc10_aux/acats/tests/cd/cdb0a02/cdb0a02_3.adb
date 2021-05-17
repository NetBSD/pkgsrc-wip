
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
with Unchecked_Deallocation;
package body CDB0A02_3 is
  procedure Deallocate is new Unchecked_Deallocation(Large_Cell,Large_Tree);

  -- Sort: zeros on the left, ones on the right...
  procedure Insert( Item: Character; On_Tree : in out Large_Tree ) is
  begin
    if On_Tree = null then
      On_Tree := new Large_Cell'(Item,(Item,Item),null,null);
    elsif Item > On_Tree.Data then
      Insert(Item,On_Tree.Right);
    else
      Insert(Item,On_Tree.Left);
    end if;
  end Insert;

  procedure Traverse( The_Tree : Large_Tree ) is
  begin
    if The_Tree = null then
      null;  -- how very symmetrical
    else
      Traverse(The_Tree.Left);
      TCTouch.Touch(The_Tree.Data);
      Traverse(The_Tree.Right);
    end if;
  end Traverse;

  procedure Defoliate( The_Tree : in out Large_Tree ) is
  begin

    if The_Tree.Left /= null then
      Defoliate(The_Tree.Left);
    end if;

    if The_Tree.Right /= null then
      Defoliate(The_Tree.Right);
    end if;

    Deallocate(The_Tree);

 end Defoliate;

end CDB0A02_3;
