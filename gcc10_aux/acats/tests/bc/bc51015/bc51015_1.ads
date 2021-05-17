

     --===================================================================--


generic
   type Formal_Type is private;
package BC51015_1 is

   -- Derivation from formal type in the visible part: in an instance, the
   -- derivation is illegal if the actual is a tagged type.

   type Derived_Type is new Formal_Type;                              -- OK.

   procedure Primitive (Parm : Derived_Type);

end BC51015_1;
