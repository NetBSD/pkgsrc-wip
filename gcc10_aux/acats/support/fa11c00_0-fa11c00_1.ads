
     --=================================================================--

package FA11C00_0.FA11C00_1 is         -- Package Animal.Mammal

   type Hair_Color_Type is (Black, Brown, Blonde, Grey, White, Red);

   type Mammal is new Animal with
      record
         Hair_Color : Hair_Color_Type;
      end record;

   function Image (M : Mammal) return String;

end FA11C00_0.FA11C00_1;               -- Package Animal.Mammal
