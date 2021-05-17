
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4013_1 is

  task body T is
  begin
    -- selective wait with delay alternative
    select
      accept A;
    or delay 1.4;                -- OPTIONAL ERROR: {2:5;-1:0}
    end select;                  -- pragma Restrictions(No_Delay) in force.
  end T;

  procedure Check_For_Delays is
  begin
    T.A;
  end Check_For_Delays;

end LXH4013_1;
