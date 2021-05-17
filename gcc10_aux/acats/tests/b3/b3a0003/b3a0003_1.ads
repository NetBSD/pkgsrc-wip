

     --===================================================================--


with B3A0003_0;
generic                                                   -- Template for
                                                          -- formal package.
   type FP_Formal_Desig is private;
   type FP_Formal_Acc is access constant FP_Formal_Desig;

   FP_Formal_Obj : in out FP_Formal_Acc;

package B3A0003_1 is

   Priv : aliased FP_Formal_Desig;


   type FP_Local_Desig is tagged record
      Item : B3A0003_0.Component := 5;
   end record;

   type FP_Local_Acc is access constant FP_Local_Desig;

   Tag : aliased FP_Local_Desig;

end B3A0003_1;
