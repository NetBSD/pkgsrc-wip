

package body  LXD70031 is

   subtype Driver_Index is integer range 1..4;

   task body Line_Driver is
   begin
      loop
         accept Input do
            null;  -- Application code
         end Input;
      end loop;
   end Line_Driver;

   -- Create a group of Line_Driver tasks
   Driver_Array : array (Driver_Index) of acc_Driver :=
                                           (Driver_Index => new Line_Driver);


   task body Close_Control is
   begin
      select
         accept Normal_Shut_Down do
            null;  -- Application code
         end Normal_Shut_Down;
      or
         accept Disaster_Shut_Down do
            null;  -- Application code
               for i in Driver_Index loop
                  -- This abort should not be allowed when
                  -- restriction No_Abort_Statements is in force.
                  abort Driver_Array(i).all;      -- OPTIONAL ERROR: {19}
               end loop;
         end Disaster_Shut_Down;
      end select;
   end Close_Control;

begin -- LXD70031

   null;

end LXD70031;
