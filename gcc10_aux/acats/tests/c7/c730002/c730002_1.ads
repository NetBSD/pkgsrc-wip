
     --==================================================================--

with C730002_0; use C730002_0;
generic
   type T is new C730002_0.Engine_Type with private;
package C730002_1 is

   -- This generic package contains types/procedures specific to engines 
   -- of the diesel variety.

   type Repair_Facility_Type is (On_Site, Repair_Shop, Factory);

   type Diesel_Series is new T with private;

   procedure Routine_Maintenance (Eng      : in out Diesel_Series;
                                  Spec_Req : in     Specialist_ID := Jack);
  
   -- Other diesel specific operations... (not required in this test).

private

   type Diesel_Series is new T with record
      Repair_Facility_Required : Repair_Facility_Type := On_Site;
   end record;

end C730002_1;
