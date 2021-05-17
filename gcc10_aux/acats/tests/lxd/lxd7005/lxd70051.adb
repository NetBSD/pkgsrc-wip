

package body  LXD70051 is

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
                  (Driver_Index => new Line_Driver); -- OPTIONAL ERROR: {36;2}
       -- The allocations violate the restriction No_Task_Allocators.


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
                  abort Driver_Array(i).all;
               end loop;
         end Disaster_Shut_Down;
      end select;
   end Close_Control;

begin -- LXD70051

   null;

end LXD70051;
