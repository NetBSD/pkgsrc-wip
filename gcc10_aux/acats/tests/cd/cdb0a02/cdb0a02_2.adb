
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
with Report;
with Unchecked_Deallocation;
package body CDB0A02_2 is
  procedure Deallocate is new Unchecked_Deallocation(Small_Cell,Small_Tree);

  -- Sort: zeros on the left, ones on the right...
  procedure Insert( Item: Character; On_Tree : in out Small_Tree ) is
  begin
    if On_Tree = null then
      On_Tree := new Small_Cell'(Item,null,null);
    elsif Item > On_Tree.Data then
      Insert(Item,On_Tree.Right);
    else
      Insert(Item,On_Tree.Left);
    end if;
  end Insert;

  procedure Traverse( The_Tree : Small_Tree ) is
  begin
    if The_Tree = null then
      null;  -- how very symmetrical
    else
      Traverse(The_Tree.Left);
      TCTouch.Touch(The_Tree.Data);
      Traverse(The_Tree.Right);
    end if;
  end Traverse;

  procedure Defoliate( The_Tree : in out Small_Tree ) is
  begin

    if The_Tree.Left /= null then
      Defoliate(The_Tree.Left);
    end if;

    if The_Tree.Right /= null then
      Defoliate(The_Tree.Right);
    end if;

    Deallocate(The_Tree);

  end Defoliate;

  procedure TC_Exceed_Pool is
    Wild_Branch : Small_Tree;
  begin
    for Ever in 1..Pool_Max_Elements loop
       Wild_Branch := new Small_Cell'('a', Wild_Branch, Wild_Branch);
       TCTouch.Validate("A","Allocating element for overflow");
    end loop;
    Report.Failed(" Pool_Overflow not raised on exceeding user pool size");
  exception
    when FDB0A00.Pool_Overflow => null; -- anticipated case
    when others =>
      Report.Failed("wrong exception raised in user Exceed_Pool");
  end TC_Exceed_Pool;

end CDB0A02_2;
