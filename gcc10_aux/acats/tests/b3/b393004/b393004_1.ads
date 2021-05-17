

     --===================================================================--


with B393004_0;
package B393004_1 is

--
-- Generics for actuals which are primitive subprograms of tagged type:
--

   generic
      type FD_Nontagged is          new B393004_0.Field;
      type FD_Abstract  is abstract new B393004_0.Ancestor with private;

      with procedure Proc (P1: in out FD_Abstract; P2: in FD_Nontagged);
   package Tag_Formal_Derived_Proc is end;


   generic
      type FP_Nontagged is                 private;
      type FP_Abstract  is abstract tagged private;

      with function Func (P1: FP_Abstract) return FP_Nontagged;
   package Tag_Formal_Private_Func is end;


   generic
      type FD_Nontagged is new B393004_0.Field;

      with function Func (P1: B393004_0.Ancestor) return FD_Nontagged;
   package Tag_Ancestor_Func is end;
      

   generic
      type FP_Nontagged is private;

      with procedure Proc (P1: in out B393004_0.Ancestor;
                           P2: in     FP_Nontagged);
   package Tag_Ancestor_Proc is end;
      

   generic
      type FD_Nontagged is new B393004_0.Field;

      with function Func (P1: B393004_0.Grandchild) return FD_Nontagged;
   package Tag_Grandchild_Func is end;
      

end B393004_1;
