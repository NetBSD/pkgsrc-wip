
-- No bodies provided for FA13A00_0.

     --==================================================================--

package FA13A00_1 is                      -- Basic Elevator Operations

   type Call_Waiting_Type is private;
   type Floor is (Basement, Floor1, Floor2, Floor3, Penthouse);
   type Floor_No is range Floor'Pos(Floor'First) .. Floor'Pos(Floor'Last);
   Current_Floor : Floor   := Floor1;

   TC_Operation  : boolean := true;       

   procedure Call (F : in Floor; C : in out Call_Waiting_Type);
   procedure Clear_Calls (C : in out Call_Waiting_Type);

private
   type Call_Waiting_Type is array (Floor) of boolean;
   Call_Waiting : Call_Waiting_Type := (others => false);

end FA13A00_1;
