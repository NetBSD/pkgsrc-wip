

     --==================================================================--


with F731A00;
use  F731A00;
package B731A02_1 is

   type Derived3 is new Parent with null record;
   -- function Vis_Op (P: Derived3) return Boolean implicitly declared here.

   -- Pri_Op inherited from Parent but not implicitly declared (since Pri_Op 
   -- does not become visible within the immediate scope of Derived3). 

end B731A02_1;
