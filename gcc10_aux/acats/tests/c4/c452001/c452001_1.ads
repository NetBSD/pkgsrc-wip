
with C452001_0;
package C452001_1 is

   type Planet is tagged record
      Name : String (1..15);
      Representation : C452001_0.Colored_Circle;
   end record;

   -- Type Planet will be used to check that predefined equality
   -- for a tagged type with a tagged component incorporates
   -- user-defined equality for the component type.

   type TC_Planet is new Planet with null record;

   -- A "copy" of Planet. Used to create a type extension. An "="
   -- operator will be defined for this type that should be
   -- incorporated by the type extension.

   function "=" (Arg1, Arg2 : in TC_Planet) return Boolean;

   type Craters is array (1..3) of C452001_0.Colored_Circle;

   -- An array type (untagged) with tagged components

   type Moon is new TC_Planet
     with record
        Crater : Craters;
     end record;

   -- A tagged record type. Extended component type is untagged,
   -- but its predefined equality operator should incorporate
   -- the user-defined operator of its tagged component type.

end C452001_1;
