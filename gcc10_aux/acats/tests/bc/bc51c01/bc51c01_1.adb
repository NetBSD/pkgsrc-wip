

     --===================================================================--


package body BC51C01_1 is

   package body RecExt_Overrides_Inherited is

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

   end RecExt_Overrides_Inherited;


   package body RecExt_Overrides_All is

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

   end RecExt_Overrides_All;


   package body PriExt_Overrides_Inherited is

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

   end PriExt_Overrides_Inherited;


   package body PriExt_Overrides_All is

      function Func (P: Concrete_Derived) return Concrete_Derived is
      begin
         return P;
      end Func;

      procedure Proc (P: in out Concrete_Derived) is
      begin
         null;
      end Proc;

      procedure New_Proc (P: out Concrete_Derived) is
      begin
         null;
      end New_Proc;

   end PriExt_Overrides_All;


end BC51C01_1;
