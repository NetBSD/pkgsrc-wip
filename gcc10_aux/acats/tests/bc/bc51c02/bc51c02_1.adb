

     --===================================================================--


package body BC51C02_1 is

   package body RecExt_Overrides_Explicit is

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

   end RecExt_Overrides_Explicit;


   package body RecExt_Overrides_All is

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

   end RecExt_Overrides_All;


   package body PriExt_Overrides_Explicit is

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

   end PriExt_Overrides_Explicit;


   package body PriExt_Overrides_All is

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

   end PriExt_Overrides_All;

end BC51C02_1;
