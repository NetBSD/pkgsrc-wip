
with Report;
with C3A0013_1;
with C3A0013_2;
with C3A0013_3;
package body C3A0013_4 is
  package Root   renames C3A0013_1;
  package Cars   renames C3A0013_2;
  package Trucks renames C3A0013_3;

  type Car_Pool is array(1..4) of aliased Cars.Car;
  Commuters : Car_Pool;

  My_Car      : aliased Cars.Car;
  Company_Car : Root.Vehicle_ID;
  Repair_Shop : Root.Vehicle_ID;

  The_Vehicle : Root.Vehicle;
  The_Car     : Cars.Car;
  The_Truck   : Trucks.Truck;

  procedure TC_Dispatch( Ptr   : Root.Vehicle_ID;
                         Char  : Character ) is
  begin
    Root.TC_Validate( Ptr.all, Char );
  end TC_Dispatch;

  procedure TC_Check_Formal_Access( Item: in out Root.Vehicle'Class;
                                    Char: Character) is
  begin
    TC_Dispatch( Item'Unchecked_Access, Char );
  end TC_Check_Formal_Access;

  procedure Perform_Tests is
  begin  -- Main test procedure.

  for Lane in Commuters'Range loop
    Cars.Create( Commuters(Lane) );
    for Excitement in 1..Lane loop
      Cars.Up_Shift( Commuters(Lane) );
    end loop;
  end loop;

  Cars.Create( My_Car );
  Cars.Up_Shift( My_Car );
  Cars.TC_Validate( My_Car, 2 );

  Root.Create( The_Vehicle, 1 );
  Cars.Create( The_Car    , 4 );
  Trucks.Create( The_Truck, 3 );

  TC_Check_Formal_Access( The_Vehicle, 'V' );
  TC_Check_Formal_Access( The_Car,     'C' );
  TC_Check_Formal_Access( The_Truck,   'T' );

  Root.Up_Shift( The_Vehicle );
  Cars.Up_Shift( The_Car );
  Trucks.Up_Shift( The_Truck );

  Root.TC_Validate( The_Vehicle, 1 ); 
  Cars.TC_Validate( The_Car, 2 ); 
  Trucks.TC_Validate( The_Truck, 3 ); 

  --  general access type may reference allocated objects

  Company_Car := new Cars.Car;
  Root.Create( Company_Car.all );
  Root.Up_Shift( Company_Car.all );
  Root.Up_Shift( Company_Car.all );
  Root.TC_Validate( Company_Car.all, 6 );

  --  general access type may reference aliased objects

  Repair_Shop := My_Car'Access;
  Root.TC_Validate( Repair_Shop.all, 2 );

  --  general access type may reference aliased objects

  Construction: declare
    type Speed_List is array(Commuters'Range) of Natural;
    Accelerations : constant Speed_List := (2, 6, 12, 20);
  begin
    for Rotation in Commuters'Range loop
      Repair_Shop := Commuters(Rotation)'Access;
      Root.TC_Validate( Repair_Shop.all, Accelerations(Rotation) );
    end loop;
  end Construction;

end Perform_Tests;

end C3A0013_4;
