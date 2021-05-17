
     --==================================================================--

with Report;

with C3A1002_0;
use  C3A1002_0;

procedure C3A1002 is

   Enum_Val : Enu_Type := M;

   Int_Val  : Small_Int := 15;

   -- Discriminant value comes from default.

   Incomplete6_Obj_1  :  Incomplete6;

   -- Discriminant value comes from explicit constraint.

   Incomplete1_Obj_1  :  Incomplete1 (M);

   Incomplete2_Obj_1  :  Incomplete2 (6);

   Incomplete5_Obj_1  :  Incomplete5 (F);

   Incomplete6_Obj_2  :  Incomplete6 (7);

   -- Discriminant value comes from assignment.        

   Incomplete1_Obj_2  :  Incomplete1
                      := (F, 12);

   Incomplete3_Obj_1  :  Incomplete3
                      := (D => 2, S => "Hi", I => 10, E => F);

   Incomplete4_Obj_1  :  Incomplete4
                      := (E => M, D => 3, S => "Bye", I => 14);

begin

   Report.Test ("C3A1002", "Check that the full type completing a type " &
                "with no discriminant part or an unknown discriminant "  &
                "part may have explicitly declared or inherited "        &
                "discriminants.  Check for cases where the types are "   &
                "tagged records and task types");

   -- Check the initial values.

   if (Incomplete6_Obj_1.D6 /= 4) then 
      Report.Failed ("Wrong initial value for Incomplete6_Obj_1");
   end if;

   -- Check the explicit values.

   if (Incomplete1_Obj_1.D1       /= M) or 
      (Incomplete1_Obj_1.MInteger /= 9) then
        Report.Failed ("Wrong values for Incomplete1_Obj_1");
   end if;

   if (Incomplete2_Obj_1.D2       /= 6) or 
      (Incomplete2_Obj_1.FInteger /= 8) or
      (Incomplete2_Obj_1.ID       /= "ACVC95") then
         Report.Failed ("Wrong values for Incomplete2_Obj_1");
   end if;

   if (Incomplete5_Obj_1.D5 /= F) then 
      Report.Failed ("Wrong value for Incomplete5_Obj_1");
   end if;

   Incomplete5_Obj_1.Read_Disc (Enum_Val);

   if (Enum_Val /= F) then 
      Report.Failed ("Wrong value for Enum_Val");
   end if;

   if (Incomplete6_Obj_2.D6 /= 7) then 
      Report.Failed ("Wrong value for Incomplete6_Obj_2");
   end if;

   Incomplete6_Obj_1.Read_Int (Int_Val);

   if (Int_Val /= 4) then 
      Report.Failed ("Wrong value for Int_Val");
   end if;

   -- Check the assigned values.

   if (Incomplete1_Obj_2.D1       /= F)  or 
      (Incomplete1_Obj_2.FInteger /= 12) then
         Report.Failed ("Wrong values for Incomplete1_Obj_2");
   end if;

   if (Incomplete3_Obj_1.D /= 2 ) or 
      (Incomplete3_Obj_1.I /= 10) or
      (Incomplete3_Obj_1.E /= F ) or
      (Incomplete3_Obj_1.S /= "Hi") then
         Report.Failed ("Wrong values for Incomplete3_Obj_1");
   end if;

   if (Incomplete4_Obj_1.E /= M )      or 
      (Incomplete4_Obj_1.D /= 3)       or
      (Incomplete4_Obj_1.S /= "Bye")   or
      (Incomplete4_Obj_1.I /= 14)      then
         Report.Failed ("Wrong values for Incomplete4_Obj_1");
   end if;

   Report.Result;

end C3A1002;
