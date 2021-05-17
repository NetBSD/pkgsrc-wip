

     --===================================================================--


package body B393006_0 is

   function Func (E : Derived_Type) return Derived_Type is
   begin
      return E;
   end Func;

   procedure Proc (Parm : Derived_Type) is
   begin
      null;
   end Proc;

end B393006_0;
