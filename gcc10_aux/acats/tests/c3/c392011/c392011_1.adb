
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C392011_1 is

  Integer_1 : Integer := 0;

  function Create return Level_1 is
    Created_Item_1 : constant Level_1
                   := ( C392011_0.Create with Int_Item => Integer_1 );
    -- note call to     ^--------------^   -- A
  begin
    Integer_1 := Integer'Succ(Integer_1);
    TCTouch.Touch('C'); -- --- ---- ----- ---- --- -- --- ---- ----- ---- -- C
    return Created_Item_1;
  end Create;

  procedure Check( Left, Right: in Level_1 ) is
  begin
    TCTouch.Touch('D'); -- --- ---- ----- ---- --- -- --- ---- ----- ---- -- D
  end Check;

end C392011_1;
