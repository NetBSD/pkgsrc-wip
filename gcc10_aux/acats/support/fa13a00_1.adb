

     --==================================================================--

package body FA13A00_1 is              

   -- Call the elevator.

   procedure Call (F : in Floor; C : in out Call_Waiting_Type) is
   begin
      C (F) := true;
   end Call;

   --------------------------------------------

   -- Clear all calls of the elevator.

   procedure Clear_Calls (C : in out Call_Waiting_Type) is
   begin
      C := (others => false);
   end Clear_Calls;

end FA13A00_1;
