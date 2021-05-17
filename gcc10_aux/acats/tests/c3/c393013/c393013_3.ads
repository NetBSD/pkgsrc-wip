
with C393013_1;
package C393013_3 is
   type Windmill is new C393013_1.Generator with private;
   -- Inherits all of Power_Output, Set_Power_Output, Location, and
   -- Set_Location as non-abstract operations.

   -- Clone and Create are inherited as requires overriding operations.
private
   type Windmill is new C393013_1.Generator with null record;
   -- Clone and Create become non-abstract operations here, and no
   -- overriding is required.
end C393013_3;
