
     --==================================================================--

package body C730002_1 is

   procedure Routine_Maintenance (Eng      : in out Diesel_Series;
                                  Spec_Req : in     Specialist_ID := Jack) is
   begin
      Eng.Ave_Repair_Time          := 6;
      Eng.Personnel_Required       := 2;
      Eng.Specialist               := Spec_Req;
      Eng.Repair_Facility_Required := On_Site;
   end Routine_Maintenance;

end C730002_1;
