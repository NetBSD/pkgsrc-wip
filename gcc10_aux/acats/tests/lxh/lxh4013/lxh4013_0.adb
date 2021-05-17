
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4013_0 is

  task body T is
  begin
    -- selective wait with delay alternative
    select
      accept A;
    or 
      accept B;
    end select;
  end T;

end LXH4013_0;
