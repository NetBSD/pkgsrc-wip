

package body  LXD70061 is


   task body Line_Driver is
   begin
      loop
         accept Input do
            null;  -- Application code
         end Input;
      end loop;
   end Line_Driver;

   -- Create a group of Line_Driver tasks
   Driver_Array  : acc_Driver_Array_Type :=
                               new Driver_Array_Type; -- OPTIONAL ERROR: {32;1}
      -- Allocators violate restriction No_Task_Allocators.

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
                  abort Driver_Array(i);
               end loop;
         end Disaster_Shut_Down;
      end select;
   end Close_Control;

begin -- LXD70061

   null;

end LXD70061;
