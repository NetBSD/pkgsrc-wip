
     --==================================================================--

package body C730002_3 is

   procedure Routine_Maintenance (E  : in out Electric_Series;
                                  SR : in     Specialist_ID := Curly) is
   begin
      E.Ave_Repair_Time          := 9;
      E.Personnel_Required       := 3;
      E.Specialist               := SR;
      E.Mean_Time_Between_Repair := 1000;
   end Routine_Maintenance;

end C730002_3;
