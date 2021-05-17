
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body LXH4005_0 is

  Just_A_Number : Natural := 0;

  An_Exception : exception;           

  procedure Raise_One is
  begin
    raise Constraint_Error;  -- violate pragma Restrictions(No_Exceptions)
  end Raise_One;

begin

  Just_A_Number := Just_A_Number -1;                              -- OK
                             -- not a particularly good idea, but legal

  -- the following case may be flagged as any of:
     -- the existence of the handler is an error
     -- the when AND the raise are errors
     -- all three

exception                    -- violate pragma Restrictions(No_Exceptions)

  when Constraint_Error => Just_A_Number := 0;
       raise;                -- violate pragma Restrictions(No_Exceptions)

end LXH4005_0;
