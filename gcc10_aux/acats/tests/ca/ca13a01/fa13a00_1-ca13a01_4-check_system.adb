
     --==================================================================--

separate (FA13A00_1.CA13A01_4)

-- Subunit Check_System declared in Maintenance Operation.

procedure Check_System is
begin
   -- See if regular power is on.

   if Power /= V120 then                  -- Reference package with'ed by
      TC_Operation := false;              -- the subunit parent's body.
   end if;

   -- Test elevator function.

   FA13A00_1.FA13A00_3.Move_Elevator      -- Reference public sibling of
     (Penthouse, Call_Waiting);           -- the subunit parent's body.

   if not Call_Waiting (Penthouse) then   -- Reference private part of the
      TC_Operation := false;              -- parent of the subunit package's 
                                          -- body.
   end if;

   FA13A00_1.FA13A00_2.Down (One_Floor);  -- Reference private sibling of
                                          -- the subunit parent's body.

   if Current_Floor /= Floor'pred (Penthouse) then 
      TC_Operation := false;              -- Reference type declared in the
   end if;                                -- parent of the subunit parent's
                                          -- body.

end Check_System;
