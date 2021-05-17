

     --==================================================================--


with BC53002_0;
use  BC53002_0;
package BC53002 is

   --
   -- Cases where formal does not have aliased components:
   --

   package Formal_NonAliased_Actual_Aliased is new
     NonAliased_Constrained_Formal (F_Nonaliased_Cons => Aliased_C);  -- OK.


   package Formal_NonAliased_Actual_NonAliased is new
     NonAliased_Constrained_Formal (Nonaliased_C);                    -- OK.



   --
   -- Cases where formal has aliased components:
   --


   package Formal_Aliased_Actual_Aliased is new
     Aliased_Unconstrained_Formal (Aliased_UC);                       -- OK.


   package Formal_Aliased_Actual_Nonaliased is new
     Aliased_Unconstrained_Formal 
       (F_Aliased_Uncons => Nonaliased_UC);                           -- ERROR:
                             -- Formal has aliased components; actual does not.

end BC53002;
