

-- The following isn't allowed when restriction No_Asynchronous_Control is
-- in force.
with Ada.Asynchronous_Task_Control;                  -- OPTIONAL ERROR: {1}
with Ada.Task_Identification;
with ImpDef;
package body  LXD70081 is

   package AATC renames Ada.Asynchronous_Task_Control;
   package ATI  renames Ada.Task_Identification;

   Stats_Collector_ID : ATI.Task_Id;   -- ID for the "hold" call


   task body Stats_Collector is
   begin
      Stats_Collector_ID := ATI.Current_Task;
      accept Start;
      loop
         null;  -- Application code
         delay ImpDef.Minimum_Task_Switch;
      end loop;
   end Stats_Collector;

   task body Controller is
   begin
      Stats_Collector.Start;
      loop
         accept DSA_Critical do
            -- Dynamic Storage Area has reached critical condition, close
            -- down statistics collection
            AATC.Hold (Stats_Collector_ID);
            -- here would be code to close others
         end DSA_Critical;
         -- etc. here would be other application code including the
         -- appropriate "continue"s
         delay ImpDef.Minimum_Task_Switch;
      end loop;
   end Controller;

begin -- LXD70081

   null;

end LXD70081;
