
with C393013_1;
package C393013_4 is
   type Gas_Turbine is new C393013_1.Generator with private;
   -- Inherits all of Power_Output, Set_Power_Output, Location, and
   -- Set_Location as non-abstract operations.
   -- Clone and Create are inherited as requires overriding operations.
   type Gas_Kind_Type is (Natural_Gas, Gasoline, Biomass_Methane);
   not overriding
   function Kind (Obj : in Gas_Turbine) return Gas_Kind_Type;
   not overriding
   procedure Set_Kind (Obj : in out Gas_Turbine; Kind : in Gas_Kind_Type);
private
   type Gas_Turbine is new C393013_1.Generator with record
       Kind : Gas_Kind_Type;
   end record;
   -- Create and Clone must be overridden:
   overriding
   function Create (Power : in Natural) return Gas_Turbine;
   overriding
   function Clone (Obj : in Gas_Turbine; New_Location : in Character)
     return Gas_Turbine;
       -- Create a copy of Obj at a new location.
end C393013_4;
