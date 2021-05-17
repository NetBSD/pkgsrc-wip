

-- The following isn't allowed when restriction No_Dynamic_Priorities is
-- in force.
with Ada.Dynamic_Priorities;                  -- OPTIONAL ERROR: {1}
with system;
package body  LXD70071 is

   package ADP renames Ada.Dynamic_Priorities;


   task body Credit_Task is

      Base_Priority     : System.Any_Priority := ADP.Get_Priority;
      Current_Priority  : System.Any_Priority := Base_Priority;
      Queue_Overload_Threshold  : integer := 50;
      Queue_Underload_Threshold : integer := 45;

   begin
      loop
         accept Input do
            null;  -- Application code
         end Input;

         -- SAMPLE code calling Ada.Dynamic_Priorities
         -- After each transaction is handled check the thresholds
         if Current_Priority /= Base_Priority then
            -- We are in the overload situation, check if we have reached
            -- underload
            if Input'Count < Queue_Underload_Threshold then
                  -- Below the underload, reset priority
                  ADP.Set_Priority (Base_Priority);
                  Current_Priority := Base_Priority;
            end if;
         else
            -- check if we have just gone into overload
            if Input'Count > Queue_Overload_Threshold then
               -- yes, increase the priority
               ADP.Set_Priority (System.Priority'Last);
               Current_Priority := System.Priority'Last;
            end if;
         end if;
      end loop;
   end Credit_Task;

begin -- LXD70071

   null;

end LXD70071;
