
----------------------------------------------------------------- C390003_2

with C390003_1;
package C390003_2 is -- Motivators

  package Vehicle renames C390003_1;
  subtype Bicycle is Vehicle.Object(2);  -- constrained subtype

  type Motorcycle is new Bicycle with record
    Displacement : Natural;
  end record;
  procedure TC_Validate( It: Motorcycle; Key: Vehicle.TC_Keys );

  type Tandem is new Bicycle with null record;
  procedure TC_Validate( It: Tandem; Key: Vehicle.TC_Keys );

  type Car is new Vehicle.Object(4) with  -- extended, constrained
    record
      Displacement : Natural;
    end record;
  procedure TC_Validate( It: Car; Key: Vehicle.TC_Keys );

  type Truck is new Vehicle.Object with  -- extended, unconstrained
    record
      Tare : Natural;
    end record;
  procedure TC_Validate( It: Truck; Key: Vehicle.TC_Keys );

end C390003_2; -- Motivators;
