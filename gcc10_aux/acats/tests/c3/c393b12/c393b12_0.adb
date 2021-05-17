 -- Alert_Functions

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C393B12_0 is
          -- Alert_Functions

  procedure Handle (GA : in out Generic_Alert_Type) is
    begin
      GA.Status := Generic_Status_Enum'Last;
    end Handle;

  function Query_Status (GA : Generic_Alert_Type) 
    return Generic_Status_Enum is
    begin
      return GA.Status;
    end Query_Status;

end C393B12_0;
