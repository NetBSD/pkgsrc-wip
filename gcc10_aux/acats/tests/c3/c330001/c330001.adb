
     --==================================================================--

with C330001_0.C330001_2;
with Report;

use  C330001_0.C330001_2;

procedure C330001 is  
begin
   Report.Test ("C330001", "Check that a variable object of an indefinite " &
                "type is properly initialized/constrained by an initial "   &
                "value assignment that is a) an aggregate, b) a function, " &
                "or c) an object.  Check that objects of the above types "  &
                "do not need explicit constraints if they have initial "    &
                "values");

   -- Verify values of public child objects.

   if not (Verify_Public_Obj_1 and Verify_Public_Obj_2) then 
      Report.Failed ("Wrong values for PublicChild_Obj_01 or " &
                     "PublicChild_Obj_02");
   end if;
   
   if PublicChild_Obj_03'First /= 1 or
      PublicChild_Obj_03'Last  /= 4 then
      Report.Failed ("Wrong values for PublicChild_Obj_03");
   end if;

   if PublicChild_Obj_05.D  /= 7 or 
      not PublicChild_Obj_05.C1  then
      Report.Failed ("Wrong values for PublicChild_Obj_05");
   end if;

   if PublicChild_Obj_06.ND /= 6 or 
      PublicChild_Obj_06.C2 /= 9 or
      PublicChild_Obj_06.C1      then
      Report.Failed ("Wrong values for PublicChild_Obj_06");
   end if;

   -- Definite object can have its discriminant changed by assignment to
   -- the entire object.

   Assign_Private_Obj_3;

   -- Verify values of private child objects.

   if not Verify_Private_Obj_1 or not 
          Verify_Private_Obj_2 or not 
          Verify_Private_Obj_3 then
      Report.Failed ("Wrong values for PrivateChild_Obj_01 or " &
                     "PrivateChild_Obj_02 or PrivateChild_Obj_03");
   end if;

   -- Attempt to change the discriminants of the objects of the indefinite
   -- subtypes:  Constraint_Error.

   if not Raised_CE_PublicChild_Obj or not Raised_CE_PrivateChild_Obj then
      Report.Failed ("Constraint_Error not raised");
   end if;

   Report.Result;

end C330001;
