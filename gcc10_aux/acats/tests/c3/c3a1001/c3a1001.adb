
     --==================================================================--

with Report;

with C3A1001_0;
use  C3A1001_0;

procedure C3A1001 is

   -- Discriminant value comes from default.

   Incomplete2_Obj_1 :  Incomplete2;                

   Incomplete4_Obj_1 :  Incomplete4;

   Incomplete6_Obj_1 :  Incomplete6;                

   -- Discriminant value comes from explicit constraint.

   Incomplete1_Obj_1 :  Incomplete1 (F);              

   Incomplete5_Obj_1 :  Incomplete5 (M);               

   Incomplete6_Obj_2 :  Incomplete6 (2);           

   -- Discriminant value comes from assignment.        

   Incomplete3_Obj_1 :  Incomplete3 := (Disc => 6, ID => "Sentra");       

   Incomplete1_Obj_2 :  Incomplete1 := (Disc => M, MInteger => 9);    
                                  
   Incomplete2_Obj_2 :  Incomplete2 := (Disc => 5, ID => "Buick");    
                                  
begin

   Report.Test ("C3A1001", "Check that the full type completing a type " &
                "with no discriminant part or an unknown discriminant "  &
                "part may have explicitly declared or inherited "        &
                "discriminants.  Check for cases where the types are "   &
                "records and protected types");

   -- Check the initial values.

   if (Incomplete2_Obj_1.Disc /= 8) or
      (Incomplete2_Obj_1.ID   /= "Plymouth") then
         Report.Failed ("Wrong initial values for Incomplete2_Obj_1");
   end if;

   if (Incomplete4_Obj_1.Disc /= 8) or
      (Incomplete4_Obj_1.ID   /= "Plymouth") then
         Report.Failed ("Wrong initial values for Incomplete4_Obj_1");
   end if;

   if (Incomplete6_Obj_1.Disc         /= 1) or
      (Incomplete6_Obj_1.Get_Priv_Val /= 1) then
         Report.Failed ("Wrong initial value for Incomplete6_Obj_1");
   end if;

   -- Check the explicit values.

   if (Incomplete1_Obj_1.Disc     /= F) or 
      (Incomplete1_Obj_1.FInteger /= 8) then
         Report.Failed ("Wrong values for Incomplete1_Obj_1");
   end if;

   if (Incomplete5_Obj_1.Disc         /= M) or  
      (Incomplete5_Obj_1.Get_Priv_Val /= M) then
         Report.Failed ("Wrong value for Incomplete5_Obj_1");
   end if;

   if (Incomplete6_Obj_2.Disc         /= 2) or
      (Incomplete6_Obj_2.Get_Priv_Val /= 2) then
         Report.Failed ("Wrong value for Incomplete6_Obj_2");
   end if;

   -- Check the assigned values.

   if (Incomplete3_Obj_1.Disc /= 6) or 
      (Incomplete3_Obj_1.ID   /= "Sentra") then
         Report.Failed ("Wrong values for Incomplete3_Obj_1");
   end if;

   if (Incomplete1_Obj_2.Disc     /= M) or
      (Incomplete1_Obj_2.MInteger /= 9) then
         Report.Failed ("Wrong values for Incomplete1_Obj_2");
   end if;

   if (Incomplete2_Obj_2.Disc /= 5) or 
      (Incomplete2_Obj_2.ID   /= "Buick") then
         Report.Failed ("Wrong values for Incomplete2_Obj_2");
   end if;

   -- Make sure that assignments work without problems.

   Incomplete1_Obj_1.FInteger := 1;

   -- Avoid optimization (dead variable removal of FInteger):

   if Incomplete1_Obj_1.FInteger /= Report.Ident_Int(1) 
      then  
         Report.Failed ("Wrong value stored in Incomplete1_Obj_1.FInteger");
   end if;

   Incomplete2_Obj_1.ID       := Return_String ("12345678");

   -- Avoid optimization (dead variable removal of ID)

   if Incomplete2_Obj_1.ID /= Return_String ("12345678")
     then   
        Report.Failed ("Wrong values for Incomplete8_Obj_1.ID");
   end if;

   Incomplete4_Obj_1.ID       := Return_String ("87654321");

   -- Avoid optimization (dead variable removal of ID)

   if Incomplete4_Obj_1.ID /= Return_String ("87654321")
     then   
        Report.Failed ("Wrong values for Incomplete4_Obj_1.ID");
   end if;


   Test1:
   declare
   
      Incomplete8_Obj_1 :  Incomplete8 (10);

   begin
      Incomplete8_Obj_1.Str := "Merry Xmas";

      -- Avoid optimization (dead variable removal of Str):

      if Return_String (Incomplete8_Obj_1.Str) /= "Merry Xmas"
        then   
           Report.Failed ("Wrong values for Incomplete8_Obj_1.Str");
      end if;

   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised in Incomplete8_Obj_1");

   end Test1;

   Test2:
   declare

      Incomplete8_Obj_2 :  Incomplete8 (5);

   begin
      Incomplete8_Obj_2.Str := "Happy";       

      -- Avoid optimization (dead variable removal of Str):

      if Return_String (Incomplete8_Obj_2.Str) /= "Happy"               
        then   
           Report.Failed ("Wrong values for Incomplete8_Obj_1.Str");
      end if;

   exception
      when Constraint_Error =>
          Report.Failed ("Constraint_Error raised in Incomplete8_Obj_2");

   end Test2;

   Report.Result;

end C3A1001;
