
     --==================================================================--

package body FA13A00_1.FA13A00_2 is              

   -- Go up from the current floor.

   procedure Up (HowMany : in Floor_No) is
   begin
      Current_Floor := Floor'val (Floor'pos (Current_Floor) + HowMany);
   end Up;

   --------------------------------------------

   -- Go down from the current floor.

   procedure Down (HowMany : in Floor_No) is
   begin
      Current_Floor := Floor'val (Floor'pos (Current_Floor) - HowMany);
   end Down;

end FA13A00_1.FA13A00_2;
