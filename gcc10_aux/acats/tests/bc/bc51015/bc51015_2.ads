

     --===================================================================--


generic
   type Formal_Type is private;
package BC51015_2 is

   -- ...Other declarations.

private

   -- Derivation from formal type in the private part: in an instance, the
   -- derivation is legal if the actual is a tagged type.

   type Derived_Type is new Formal_Type;                              -- OK.

   procedure Primitive (Parm : Derived_Type);

end BC51015_2;
