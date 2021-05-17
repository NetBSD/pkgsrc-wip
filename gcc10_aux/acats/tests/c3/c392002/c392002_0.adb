
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body c392002_0 is

   --
   -- Primitive operations for Motorcycle.
   --

   function Engine_Size         (V : in Motorcycle) return Cubic_Inches is
   begin
      return (V.Size_Of_Engine);
   end Engine_Size;


   function Catalytic_Converter (V : in Motorcycle) return Boolean is
   begin
      return (False);
   end Catalytic_Converter;


   function Emissions_Produced  (V : in Motorcycle) return Emission_Measure is
   begin
      return 100.00;
   end Emissions_Produced;

   --
   -- Overridden operations for Automobile type.
   --

   function Catalytic_Converter (V : in Automobile) return Boolean is
   begin
      return (True);
   end Catalytic_Converter;


   function Emissions_Produced  (V : in Automobile) return Emission_Measure is
   begin
      return 200.00;
   end Emissions_Produced;

   --
   -- Overridden operation for Truck type.
   --

   function Emissions_Produced  (V : in Truck) return Emission_Measure is
   begin
      return 300.00;
   end Emissions_Produced;
                     
end C392002_0;
