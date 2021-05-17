
     --==================================================================--

-- Public child package of an elevator application.  This package provides
-- the actual operation of the elevator.

package FA13A00_1.FA13A00_3 is            -- Move Elevator  

   -- Other type definitions in real application.

   procedure Move_Elevator (F : in     Floor;
                            C : in out Call_Waiting_Type);

end FA13A00_1.FA13A00_3;
