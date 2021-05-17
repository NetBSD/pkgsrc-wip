

     --===================================================================--


with B641001_0;
generic                                                   -- Template for
                                                          -- formal package.
   type FP_Formal_Des is private;
   type FP_Formal_Acc is access constant FP_Formal_Des;

   FP_Formal_Obj : in out FP_Formal_Acc;

package B641001_1 is

   Priv : aliased FP_Formal_Des;


   type FP_Local_Desig is tagged record
      Item : B641001_0.Component := 5;
   end record;

   type FP_Local_Acc is access constant FP_Local_Desig;

   Tag : aliased FP_Local_Desig;

end B641001_1;
