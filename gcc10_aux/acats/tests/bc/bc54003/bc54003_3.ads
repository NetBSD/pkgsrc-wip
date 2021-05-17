

     --===================================================================--


with BC54003_0;
with BC54003_2;
package BC54003_3 is

--
-- Generics declaring formal access-to-subprogram types:
--

   -- Parameter in designated profile is a formal derived type declared in the
   -- same formal part:

   generic
      type Formal_Derived (<>) is abstract new BC54003_0.Parent with private;
      type Access_To_Proc is access procedure (P: in Formal_Derived);
   package Formal_Derived_Parameter is end;



   -- Parameter in designated profile is a formal private type declared in the
   -- same formal part:

   generic
      type Formal_Private (<>) is private;
      type Access_To_Proc is access procedure (P: in out Formal_Private);
   package Formal_Private_Parameter is end;



   -- Parameter in designated profile is a formal discrete type declared in the
   -- formal part of a formal package:

   generic
      with package Formal_Package is new BC54003_2 (<>);

      type Access_To_Func is access function
        (L, R: Formal_Package.Formal_Discrete)
          return Formal_Package.Formal_Discrete;
   package Formal_Discrete_Parameter is end;



   -- Parameter in designated profile is a formal array type declared in the
   -- formal part of a formal package, which is itself declared in the formal
   -- part of a formal package:

   generic
     with package Formal_Package is new BC54003_2 (<>);

      type Access_To_Proc is access function
        (P: Formal_Package.Outer_FP.Formal_Array;
         Q: Formal_Package.Outer_FP.Index)
          return Formal_Package.Outer_FP.Item;
   package Formal_Array_Parameter is end;


end BC54003_3;
