
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C392011_2 is

  Integer_2 : Integer := 100;

  function Create return Level_2 is
    Created_Item_2 : constant Level_2
                 := ( C392011_1.Create with Another_Int_Item => Integer_2 );
    -- note call to   ^--------------^   -- AC
  begin
    Integer_2 := Integer'Succ(Integer_2);
    TCTouch.Touch('E'); -- --- ---- ----- ---- --- -- --- ---- ----- ---- -- E
    return Created_Item_2;
  end Create;

  procedure Check( Left, Right: in Level_2 ) is
  begin
    TCTouch.Touch('F'); -- --- ---- ----- ---- --- -- --- ---- ----- ---- -- F
  end Check;

end C392011_2;
