

     --===================================================================--


package body FC51C00 is

   Value : Concrete_GrandChild;


   function Func (P: Concrete_Root) return Concrete_Root is
   begin
      return P;
   end Func;


   function Func (P: Concrete_GrandChild) return Concrete_GrandChild is
   begin
      return P;
   end Func;


   procedure Proc (P: in out Concrete_GrandChild) is
   begin
      P := Value;
   end Proc;


   procedure New_Proc (P : out Concrete_GrandChild) is
   begin
      P := Value;
   end New_Proc;

end FC51C00;
