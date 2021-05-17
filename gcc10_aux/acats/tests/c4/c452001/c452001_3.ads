
package C452001_3 is

   -- Untagged record types
   -- Equality should be incorporated (this is an Ada 2012 change).

   type Star_Class is (Supergiant, Giant, Normal, Dwarf);
   type Star_Color is (Blue, White, Yellow, Red, Brown);
   type Star is record
     Class       : Star_Class;
     Color       : Star_Color;
     Planets     : Natural;
   end record;

   function "=" (L : in Star; R : in Star) return Boolean;

   type Star_Data is record
      Item        : Star;
      Supernova   : Boolean;
   end record;

   type Constellation is array (Positive range <>) of Star;

end C452001_3;
