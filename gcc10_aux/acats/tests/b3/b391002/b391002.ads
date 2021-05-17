

     --===================================================================--


with B391002_0;
with B391002_1;
generic
   type Formal_Private is tagged private;
   type Formal_Derived is new B391002_0.Root with private;
   with package Formal_Package is new B391002_1 (<>);
package B391002 is
   type Local_Parent  is tagged null record;
   type Local_Pri_Ext is new Formal_Private with private;
   type Local_Rec_Ext is new Formal_Derived with null record;
private
   type Local_Pri_Ext is new Formal_Private with null record;

   procedure Dummy_Proc;               -- Needed to allow body
                                       -- for B391002.
end B391002;
