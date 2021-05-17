

package body  LXD70041 is

   task body Ramp_Sensor_01 is
   begin
      loop
         select
            accept Accept_Vehicle do
               null;  -- Application code
            end Accept_Vehicle;
         or
            terminate;                  -- OPTIONAL ERROR: {5:10;-3:0}
                -- Not allowed when restriction No_Terminate_Alteratives
                -- is in force.
         end select;
      end loop;
   end Ramp_Sensor_01;

begin -- LXD70041

   null;

end LXD70041;
