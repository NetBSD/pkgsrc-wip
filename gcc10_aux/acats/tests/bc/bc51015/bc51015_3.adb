

     --===================================================================--


package body BC51015_3 is

   -- Derivation from formal type in the body: in an instance, the
   -- derivation is legal if the actual is a tagged type.

   type Derived_Type is new Formal_Type;                              -- OK.

   procedure Primitive (Parm : Derived_Type) is
   begin
      null;
   end Primitive;


   function Dummy return Boolean is
   begin
      return True;
   end Dummy;

end BC51015_3;
