
----------------------------------------------------------------- C390003_3

with C390003_1;
with C390003_2;
package C390003_3 is -- Special_Trucks
  package Vehicle    renames C390003_1;
  package Motivators renames C390003_2;
  Max_Cars_On_Vehicle : constant := 6;
  type Cargo_Index is range 0..Max_Cars_On_Vehicle;
  type Cargo is array(Cargo_Index range 1..Max_Cars_On_Vehicle)
                of Motivators.Car;
  type Auto_Carrier is new Motivators.Truck(18) with
    record
      Load_Count : Cargo_Index := 0;
      Payload    : Cargo;
    end record;
  procedure TC_Validate( It: Auto_Carrier; Key: Vehicle.TC_Keys );
  procedure Load  ( The_Car : in     Motivators.Car;
                    Onto    : in out Auto_Carrier);
  procedure Unload( The_Car :    out Motivators.Car;
                    Off_of   : in out Auto_Carrier);
end C390003_3;
