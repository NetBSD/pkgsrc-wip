
with C393013_1;
package C393013_2 is
   type Water_Turbine is new C393013_1.Generator with null record;
   -- Inherits all of Power_Output, Set_Power_Output, Location,
   -- Set_Location, Create, and Clone as non-abstract operations.
end C393013_2;
