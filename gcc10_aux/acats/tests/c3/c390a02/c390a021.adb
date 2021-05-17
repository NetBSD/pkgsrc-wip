

     --==================================================================--


with F390A00;  -- Basic alert abstraction.
use  F390A00;
package body C390A021 is

   use C390A020;  -- Extended alert abstraction.


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
      return (MA = (Arrival_Time   => Default_Time,      -- Check "=" operator
                    Display_On     => Null_Device,       -- availability.
                    Level          => 0,                 -- Aggregate with
                    Action_Officer => Nobody));          -- named associations.
   end Initial_Values_Okay;


   function Bad_Final_Values (MA : in Medium_Alert_Type) return Boolean is
   begin
      return (MA /= (Alert_Time, Console,                -- Check "/=" operator
                     2         , Duty_Officer));         -- availability.
   end Bad_Final_Values;                                 -- Aggregate with
                                                         -- positional assoc.

end C390A021;
