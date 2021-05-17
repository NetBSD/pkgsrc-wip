

     --===================================================================--


with FC54A00;
with BC54A03_1;
package BC54A03_2 is

--
-- Generics declaring access-to-subprogram formals:
--

   -- Designated type is a formal derived type declared in the same formal
   -- part:

   generic
      type Formal_Derived (<>) is abstract new FC54A00.Parent with private;
      type Access_To_Proc is access procedure (P: access Formal_Derived);
   package Formal_Derived_Parameter is end;


   -- Designated type is a formal tagged private type declared in the
   -- formal part of a formal package:

   generic
      with package Formal_Package is new BC54A03_1 (<>);
      type Access_To_Proc is access procedure
        (P: access Formal_Package.Formal_Private);
   package Formal_Tagged_Private_Parameter is end;


   -- Designated type is a formal discrete type declared in the formal part of
   -- a formal package, which is itself declared in the formal part of a
   -- formal package:

   generic
      with package Formal_Package is new BC54A03_1 (<>);
      type Access_To_Func is access function
        (P, Q: access Formal_Package.Outer_FP.Formal_Discrete)
          return Integer;
   package Formal_Discrete_Parameter is end;


end BC54A03_2;
