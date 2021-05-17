

     --==================================================================--


package body C390A030 is

   use F390A00;  -- Alert system abstraction.


   function Level_Of (LA : in Low_Alert_Type) return Integer is
   begin
      return (LA.Level + 1);
   end Level_Of;


   procedure Handle (LA : in out Low_Alert_Type) is
   begin
      Handle (Alert_Type (LA));   -- Call parent's operation (type conversion).
      LA.Level := Level_Of (LA);  -- Call newly declared operation.
      LA.Display_On := Teletype;
      Display (LA);               -- Call inherited operation.
   end Handle;


   function Initial_Values_Okay (LA : in Low_Alert_Type) return Boolean is
   begin
      return (LA = (Arrival_Time   => Default_Time,      -- Check "=" operator
                    Display_On     => Null_Device,       -- availability.
                    Level          => 0));               -- Aggregate with
   end Initial_Values_Okay;                              -- named associations.


   function Bad_Final_Values (LA : in Low_Alert_Type) return Boolean is
   begin
      return (LA /= (Alert_Time, Teletype, 1));          -- Check "/=" operator
                                                         -- availability.
   end Bad_Final_Values;                                 -- Aggregate with
                                                         -- positional assoc.

   procedure Assign_Officer (MA : in out Medium_Alert_Type;
                             To : in     Person_Enum) is
   begin
      MA.Action_Officer := To;
   end Assign_Officer;


   procedure Handle (MA : in out Medium_Alert_Type) is
   begin
      Handle (Low_Alert_Type (MA));      -- Call parent's op (type conversion).
      MA.Level := Level_Of (MA);         -- Call inherited operation.
      Assign_Officer (MA, Duty_Officer); -- Call newly declared operation.
      MA.Display_On := Console;
      Display (MA);                      -- Call twice-inherited operation.
   end Handle;


   function Initial_Values_Okay (MA : in Medium_Alert_Type) return Boolean is
   begin
      -- Call parent's operation (type conversion).
      return (Initial_Values_Okay (Low_Alert_Type (MA)) and
              MA.Action_Officer = Nobody);
   end Initial_Values_Okay;


   function Bad_Final_Values (MA : in Medium_Alert_Type) return Boolean is
   begin
      return not (MA = (Arrival_Time   => Alert_Time,    -- Check "=" operator
                        Display_On     => Console,       -- availability.
                        Level          => 2,             -- Aggregate with
                        Action_Officer => Duty_Officer));-- named associations.
   end Bad_Final_Values;


end C390A030;
