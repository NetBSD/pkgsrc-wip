
--------------------------------------------------------------------- C392002

with C392002_0;        -- with Vehicle_Simulation;
with Report;

procedure C392002 is  

   type Decade                     is (c1970, c1980, c1990);
   type Vehicle_Emissions          is digits 6;
   type Engine_Emissions_by_Decade is array (Decade) of Vehicle_Emissions;
   subtype Engine_Size             is Integer range 100 .. 1000;

   Five_Tons                  : constant Natural := 10000;
   Catalytic_Converter_Offset : constant Vehicle_Emissions := 0.8;
   Truck_Adjustment_Factor    : constant Vehicle_Emissions := 1.2;


   Engine_Emission_Factor : Engine_Emissions_by_Decade := (c1970 => 10.00,
                                                           c1980 =>  8.00,
                                                           c1990 =>  5.00);

   -- Instantiate generic package for 1970 simulation.

   package Sim_1970 is new C392002_0
     (Cubic_Inches                    => Engine_Size,
      Emission_Measure                => Vehicle_Emissions,
      Emissions_Per_Engine_Cubic_Inch => Engine_Emission_Factor (c1970));


   -- Declare and initialize vehicle objects.

   Cycle_1970 : Sim_1970.Motorcycle := (Weight         => 400, 
                                        Wheels         =>   2,
                                        Size_Of_Engine => 100);

   Auto_1970  : Sim_1970.Automobile := (2000, 4, 500, 5);

   Truck_1970 : Sim_1970.Truck      := (Weight             => 5000, 
                                        Wheels             => 18, 
                                        Size_Of_Engine     => 1000, 
                                        Passenger_Capacity => 2, 
                                        Hauling_Capacity   => Five_Tons);

   -- Function Get_Engine_Size performs a dispatching call on a
   -- primitive operation that has been defined for an ancestor type and 
   -- inherited by each type derived from the ancestor.

   function Get_Engine_Size (V : in Sim_1970.Vehicle'Class) 
     return Engine_Size is
   begin
     return (Sim_1970.Engine_Size (V)); -- Dispatch according to tag.
   end Get_Engine_Size;
 

   -- Function Catalytic_Converter_Present performs a dispatching call on 
   -- a primitive operation that has been defined for an ancestor type, 
   -- overridden in the parent extended type, and inherited by the subsequent 
   -- extended type.

   function Catalytic_Converter_Present (V : in Sim_1970.Vehicle'Class)
     return Boolean is
   begin
      return (Sim_1970.Catalytic_Converter (V)); -- Dispatch according to tag.
   end Catalytic_Converter_Present;


   -- Function Air_Quality_Measure performs a dispatching call on 
   -- a primitive operation that has been defined for an ancestor type, and
   -- overridden in each subsequent extended type.

   function Air_Quality_Measure (V : in Sim_1970.Vehicle'Class)
     return Vehicle_Emissions is
   begin
      return (Sim_1970.Emissions_Produced (V));  -- Dispatch according to tag.
   end Air_Quality_Measure;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

begin  -- Main test procedure.

   Report.Test ("C392002",  "Check that the use of a class-wide parameter "
                          & "allows for proper dispatching where root type "
                          & "and extended types are declared in the same "
                          & "generic package" );

   if (Get_Engine_Size (Cycle_1970) /=  100) or
      (Get_Engine_Size (Auto_1970)  /=  500) or
      (Get_Engine_Size (Truck_1970) /= 1000) 
   then
      Report.Failed ("Failed dispatch to Get_Engine_Size");
   end if;

   if Catalytic_Converter_Present (Cycle_1970)    or
      not Catalytic_Converter_Present (Auto_1970) or
      not Catalytic_Converter_Present (Truck_1970)
   then
      Report.Failed ("Failed dispatch to Catalytic_Converter_Present");
   end if;

   if ((Air_Quality_Measure (Cycle_1970) /= 100.00) or
       (Air_Quality_Measure (Auto_1970)  /= 200.00) or
       (Air_Quality_Measure (Truck_1970) /= 300.00)) 
   then
      Report.Failed ("Failed dispatch to Air_Quality_Measure");
   end if;

   Report.Result;

end C392002;
