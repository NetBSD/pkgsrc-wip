
     --==================================================================--

with FA13A00_1.FA13A00_2;                 -- Floor Calculation

package body FA13A00_1.FA13A00_3 is              

   -- Going up or down depends on the current floor.

   procedure Move_Elevator (F : in     Floor;
                            C : in out Call_Waiting_Type) is
   begin
      if F > Current_Floor then
         FA13A00_1.FA13A00_2.Up (Floor'Pos (F) - Floor'Pos (Current_Floor));
         FA13A00_1.Call (F, C);
      elsif F < Current_Floor then
         FA13A00_1.FA13A00_2.Down (Floor'Pos (Current_Floor) - Floor'Pos (F));
         FA13A00_1.Call (F, C);
      end if;

   end Move_Elevator;

end FA13A00_1.FA13A00_3;
