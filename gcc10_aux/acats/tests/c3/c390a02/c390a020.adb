

     --==================================================================--


package body C390A020 is

   use F390A00;  -- Alert system abstraction.


   function Level_Of (LA : in Low_Alert_Type) return Integer is
   begin
      return (LA.Level + 1);
   end Level_Of;


   procedure Handle (LA : in out Low_Alert_Type) is
   begin
      Handle (Alert_Type (LA));   -- Call parent's oper. (type conversion).
      LA.Level := Level_Of (LA);  -- Call newly declared operation.
      LA.Display_On := Teletype;
      Display (LA);               -- Call inherited operation.
   end Handle;


end C390A020;
