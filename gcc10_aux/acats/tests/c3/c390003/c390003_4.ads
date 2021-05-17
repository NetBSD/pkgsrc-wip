
----------------------------------------------------------------- C390003_4

with C390003_1;
with C390003_2;
package C390003_4 is -- James_Bond

  package Vehicle   renames C390003_1;
  package Motivators renames C390003_2;

  type Q_Machine is new Vehicle.Object(4) with record
    Car_Part  : Motivators.Car;
    Bike_Part : Motivators.Motorcycle;
  end record;
  procedure TC_Validate( It: Q_Machine; Key: Vehicle.TC_Keys );

end C390003_4;
