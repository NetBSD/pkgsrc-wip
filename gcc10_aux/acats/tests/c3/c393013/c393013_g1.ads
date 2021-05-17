
with C393013_1;
generic
   type Original_Generator is new C393013_1.Generator with private;
package C393013_G1 is
   type Alarmed_Generator is new Original_Generator with null record;
   -- Inherits all of Power_Output, Set_Power_Output, Location,
   -- Set_Location, Create, and Clone as non-abstract operations.

   -- Alarm operations would be here.
end C393013_G1;
