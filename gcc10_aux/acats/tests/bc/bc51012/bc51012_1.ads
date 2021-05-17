

     --==================================================================--


with BC51012_0;
generic
   type A_Formal_Type is new                          -- Non-abstract formal
     BC51012_0.Ancestor with private;                 -- tagged derived type.   
package BC51012_1 is
  type Derived_Type is new A_Formal_Type with null record;
end BC51012_1;
