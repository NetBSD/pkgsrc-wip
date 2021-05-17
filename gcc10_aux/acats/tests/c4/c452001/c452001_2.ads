
package C452001_2 is

   -- Untagged array types
   -- Equality should not be incorporated.

   type Spacecraft_Design is (Mariner, Pioneer, Viking, Voyager);
   type Spacecraft_Component is record
     Design      : Spacecraft_Design;
     Operational : Boolean;
   end record;
   type Spacecraft is array (1 .. 1) of Spacecraft_Component;

   function "=" (L : in Spacecraft; R : in Spacecraft) return Boolean;

   type Mission is record
      Craft       : Spacecraft;
      Launch_Date : Natural;
   end record;

   type Inventory is array (Positive range <>) of Spacecraft;

end C452001_2;
