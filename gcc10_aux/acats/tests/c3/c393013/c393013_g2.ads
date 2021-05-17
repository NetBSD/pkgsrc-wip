
with C393013_1;
generic
   type Original_Generator is new C393013_1.Generator with private;
package C393013_G2 is
   type Monitored_Generator is new Original_Generator with private;
   -- Inherits all of Power_Output, Set_Power_Output, Location, and
   -- Set_Location as non-abstract operations.
   -- Clone and Create are inherited as requires overriding operations.

   -- Monitor operations would be here.
private
   type Monitored_Generator is new Original_Generator with null record;
   -- Clone and Create become non-abstract operations here, and no
   -- overriding is required.
end C393013_G2;
