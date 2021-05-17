

package body  LXD70011 is

   subtype Driver_Index is integer range 1..4;

   task body Driver_Control is
      task type Line_Driver is
         entry Input;
      end Line_Driver;
      type acc_Driver is access Line_Driver;

      task body Line_Driver is
      begin
         loop
            accept Input do
               null;  -- Application code
            end Input;
         end loop;
      end Line_Driver;

      -- Create a group of Line_Driver tasks.  These tasks are children of
      -- the Driver_Control and thus establish a hierarchy of tasks. This
      -- violates the restriction No_Task__Hierarchy.
      Driver_Array : array (Driver_Index) of acc_Driver :=
                   (Driver_Index => new Line_Driver); -- OPTIONAL ERROR: {1:7}

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
   end Driver_Control;

begin -- LXD70011

   null;

end LXD70011;
