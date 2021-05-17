
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4007_0 is

  task body Do_Something is
  begin
    select
      accept Wait;
    or
      accept Release;
    or delay 5.0;           -- violate pragma Restrictions(No_Fixed_Point)
    end select;
  
  end Do_Something;

end LXH4007_0;
