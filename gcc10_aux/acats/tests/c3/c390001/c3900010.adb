

     --==================================================================--


package body C3900010 is


   procedure Display (A : in Alert_Type) is
   begin
      Display_Count_For (A.Display_On) := Display_Count_For (A.Display_On) + 1;
   end Display;


   procedure Handle (A : in out Alert_Type) is
   begin
      A.Arrival_Time := Alert_Time;
   end Handle;


   function Level_Of (LA : in Low_Alert_Type) return Integer is
   begin
      return (LA.Level + 1);
   end Level_Of;


   procedure Assign_Officer (MA : in out Medium_Alert_Type;
                             To : in     Person_Enum) is
   begin
      MA.Action_Officer := To;
   end Assign_Officer;


end C3900010;
