
     --==================================================================--

separate (FA13A00_1.CA13A01_6)

-- Subunit GoTo_Penthouse declared in Express Operation.

procedure GoTo_Penthouse is
begin
   -- Go faster.

   Power := V240;                         -- Reference package with'ed by
                                          -- the subunit parent's body. 

   -- Call elevator.

   Call (Penthouse, Call_Waiting);        -- Reference subprogram declared in
                                          -- the parent of the subunit 
                                          -- parent's body.

   if not Call_Waiting (Penthouse) then   -- Reference private part of the
      TC_Operation := false;              -- parent of the subunit parent's
   end if;                                -- body.

   -- Move elevator to Penthouse.

   FA13A00_1.FA13A00_3.Move_Elevator      -- Reference public sibling of the
     (Penthouse, Call_Waiting);           -- subunit parent's body.

   if Current_Floor /= Penthouse then     -- Reference type declared in the
      TC_Operation := false;              -- parent of the subunit parent's
   end if;                                -- body.

   -- Return slowly

   while Current_Floor /= Floor1 loop     -- Reference type, subprogram 
      FA13A00_1.FA13A00_2.Down (1);       -- declared in the parent of the
                                          -- subunit parent's body.
   end loop;

   if Current_Floor /= Floor1 then        -- Reference type declared in
      TC_Operation := false;              -- the parent of the subunit
   end if;                                -- parent's body.

   -- Back to normal.
                                          
   Power := V120;                         -- Reference package with'ed by
                                          -- the subunit parent's body.

end GoTo_Penthouse;
