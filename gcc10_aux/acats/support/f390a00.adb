

     --==================================================================--


package body F390A00 is  -- Alert system abstraction.


   procedure Display (A : in Alert_Type) is
   begin
      Display_Count_For (A.Display_On) := Display_Count_For (A.Display_On) + 1;
   end Display;


   procedure Handle (A : in out Alert_Type) is
   begin
      A.Arrival_Time := Alert_Time;
      Display (A);
   end Handle;


end F390A00;
