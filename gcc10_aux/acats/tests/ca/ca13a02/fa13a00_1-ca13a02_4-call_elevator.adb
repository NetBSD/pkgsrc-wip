
     --==================================================================--

separate (FA13A00_1.CA13A02_4)

-- Subunit Call_Elevator declared in Outside Elevator Button Operations.

function Call_Elevator (D : Direction) return Light is
   Elevator_Button : Light;

begin
   -- See if power is on.

   if Power = Off then                       -- Reference package with'ed by
      Elevator_Button := Off;                -- the subunit parent's body.

   else
      case D is
         when Express =>        
            FA13A00_1.FA13A00_3.Move_Elevator -- Reference public sibling of
              (Penthouse, Call_Waiting);      -- the subunit parent's body.

            Elevator_Button := Express;    

         when Up      =>        
            if Current_Floor < Our_Floor then
               FA13A00_1.FA13A00_2.Up         -- Reference private sibling of
                 (Floor'pos (Our_Floor)       -- the subunit parent's body.
                   - Floor'pos (Current_Floor));
            else
               FA13A00_1.FA13A00_2.Down       -- Reference private sibling of
                 (Floor'pos (Current_Floor)   -- the subunit parent's body.
                   - Floor'pos (Our_Floor));
            end if;

            -- Call elevator.

            Call 
              (Current_Floor, Call_Waiting);  -- Reference subprogram declared
                                              -- in the parent of the subunit 
                                              -- parent's body. 
            Elevator_Button := Up;    

         when Down    =>        
            if Current_Floor > Our_Floor then
               FA13A00_1.FA13A00_2.Down       -- Reference private sibling of
                 (Floor'pos (Current_Floor)   -- the subunit parent's body.
                   - Floor'pos (Our_Floor));
            else
               FA13A00_1.FA13A00_2.Up         -- Reference private sibling of
                 (Floor'pos (Our_Floor)       -- the subunit parent's body.
                   - Floor'pos (Current_Floor));
            end if;

            Elevator_Button := Down;    

            -- Call elevator.

            Call 
              (Current_Floor, Call_Waiting);  -- Reference subprogram declared
                                              -- in the parent of the subunit 
                                              -- parent's body.
      end case;

      if not Call_Waiting (Current_Floor)     -- Reference private part of the
      then                                    -- parent of the subunit parent's
                                              -- body.
         TC_Operation := false;              
      end if;

   end if;

   return Elevator_Button;

end Call_Elevator;
