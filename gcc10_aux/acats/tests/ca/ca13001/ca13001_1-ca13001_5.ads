
     --==================================================================--

with CA13001_0;
use  CA13001_0;

-- Public child.

package CA13001_1.CA13001_5 is

   -- In a real application, tasks could be used to demonstrate 
   -- a family transportation scenario, i.e., each member of
   -- a family can take a vehicle out concurrently, then return
   -- them at the same time. For the purposes of the test, family
   -- transportation happens sequentially.

   procedure Provide_Transportation (Who     : in     Family;
                                     Get_Key :    out Key_Type;
                                     Get_Veh :    out boolean);
   procedure Return_Transportation (What   : in     Transportation;
                                    Rt_Veh :    out boolean);

end CA13001_1.CA13001_5;
