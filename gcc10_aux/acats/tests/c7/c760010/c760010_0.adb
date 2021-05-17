
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C760010_0 is

  Value : Natural := 101;

  function Unique return Natural is
  begin
    Value := Value +1;
    return Value;
  end Unique;

end C760010_0;
