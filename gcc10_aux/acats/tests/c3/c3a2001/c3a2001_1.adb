
----------------------------------------------------------------------------

with TCTouch;
package body C3A2001_1 is
  procedure Fail( The_Breaker : in out Breaker ) is
  begin
    TCTouch.Touch( 'a' ); --------------------------------------------- a
    The_Breaker.State := Failed;
  end Fail;

  procedure Set( The_Breaker : in out Breaker'Class; To_State : Status ) is
  begin
    The_Breaker.State := To_State;
  end Set;

  function  Status_Of( The_Breaker : Breaker ) return Status is
  begin
    TCTouch.Touch( 'b' ); --------------------------------------------- b
    return The_Breaker.State;
  end Status_Of;
end C3A2001_1;
