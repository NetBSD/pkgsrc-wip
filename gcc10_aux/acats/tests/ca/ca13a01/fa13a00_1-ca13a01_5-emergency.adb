
     --==================================================================--

separate (FA13A00_1.CA13A01_5)

-- Subunit Emergency declared in Maintenance Operation.

procedure Emergency is
   Bell : Bell_Type;                      -- Reference type declared in the 
                                          -- subunit parent's body.

begin
   -- Calls maintenance operation.

   FA13A00_1.CA13A01_4.Check_System;      -- Reference private sibling of the
                                          -- subunit parent 's body.

   -- Clear all calls to the elevator.

   Clear_Calls (Call_Waiting);            -- Reference subprogram declared
                                          -- in the parent of the subunit
                                          -- parent's body.
   for I in Floor loop                    
      if Call_Waiting (I) then            -- Reference private part of the
        TC_Operation := false;            -- parent of the subunit parent's
      end if;                             -- body.
   end loop;

   -- Move elevator to the basement.

   FA13A00_1.FA13A00_3.Move_Elevator      -- Reference public sibling of the
     (Basement, Call_Waiting);            -- subunit parent's body.

   if Current_Floor /= Basement then      -- Reference type declared in the
      TC_Operation := false;              -- parent of the subunit parent's
   end if;                                -- body.

   -- Shut off power.

   Power := Off;                          -- Reference package with'ed by
                                          -- the subunit parent's body.

   -- Activate bell.

   Bell := Active;                        -- Reference type declared in the 
                                          -- subunit parent's body. 

end Emergency;
