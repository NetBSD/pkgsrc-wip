
     --==================================================================--

package body C730002_0 is

   procedure Routine_Maintenance (Engine     : in out Engine_Type ; 
                                  Specialist : in     Specialist_ID := Moe) is
   begin
      Engine.Ave_Repair_Time     := 3;
      Engine.Personnel_Required  := 1;
      Engine.Specialist := Specialist;
   end Routine_Maintenance;

end C730002_0;
