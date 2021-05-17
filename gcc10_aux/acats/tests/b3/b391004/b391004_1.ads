

     --==================================================================--


with B391004_0;
generic
   type FP is limited private;
   type FD is new B391004_0.LimComp;
package B391004_1 is

   generic
      type Formal is tagged limited private;
   package GP_LimRec is
      type Derived is new Formal with record
         C : B391004_0.LimRec;
      end record;
   end;

   generic
      type Formal is tagged limited private;
   package GP_BecomesNL is
      type Derived is new Formal with record
         C : B391004_0.BecomesNL;
      end record;
   end;

   generic
      type Formal is tagged limited private;
   package GP_FP is
      type Derived is new Formal with record
         C : FP;
      end record;
   end;

   generic
      type Formal is tagged limited private;
   package GP_FD is
      type Derived is new Formal with record
         C : FD;
      end record;
   end;

end B391004_1;
