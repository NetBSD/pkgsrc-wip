
     --=================================================================--

package FA11C00_0.FA11C00_1.FA11C00_2 is -- Package Animal.Mammal.Primate

   type Habitat_Type is (Arboreal, Terrestrial);

   type Primate is new Mammal with
      record
         Habitat : Habitat_Type;
      end record;

   function Image (P : Primate) return String;

end FA11C00_0.FA11C00_1.FA11C00_2;       -- Package Animal.Mammal.Primate
