

     --==================================================================--


package body C390A010 is

   use F390A00;  -- Alert system abstraction.


   function Level_Of (LA : in Low_Alert_Type) return Integer is
   begin
      return (LA.Level + 1);
   end Level_Of;


   procedure Handle (LA : in out Low_Alert_Type) is
   begin
      Handle (Alert_Type (LA));          -- Call parent's op (type conversion).
      LA.Level := Level_Of (LA);         -- Call newly declared operation.
      LA.Display_On := Teletype;
      Display (LA);                      -- Call inherited operation.
   end Handle;


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


end C390A010;
