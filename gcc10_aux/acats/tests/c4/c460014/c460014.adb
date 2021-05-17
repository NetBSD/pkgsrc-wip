

with C460014_1;
with Report;

procedure C460014 is

   My_Root_Facade_Ptr : constant C460014_1.Facade_Class_Ptr_Type :=
                                    C460014_1.Init_Facade_Class_Ptr_with_Root;

   My_Facade_A_Ptr    : constant C460014_1.Facade_Class_Ptr_Type :=
                                    C460014_1.Init_Facade_Class_Ptr_with_A;

   My_Facade_B_Ptr    : constant C460014_1.Facade_Class_Ptr_Type :=
                                    C460014_1.Init_Facade_Class_Ptr_with_B;

   My_Null_Facade_B_Ptr    : constant C460014_1.Facade_B_Ptr_Type := null;

   Constraint_Error_Raised : Boolean;

   procedure Test_Define_Construct
    (Facade_Class_Ptr : in C460014_1.Facade_Class_Ptr_Type) is
   begin
      Constraint_Error_Raised := False;
      -- Should fail Tag_Check and therefore raise Constraint_Error if
      -- parameter doesn't designate an object of Facade_A_Type
      -- or Facade_B_Type.
      C460014_1.Define_Construct (Facade_Class_Ptr => Facade_Class_Ptr);
   exception
      when Constraint_Error =>
         Constraint_Error_Raised := True;
   end Test_Define_Construct;


   procedure Test_Define_Class_Construct
    (Facade_Class_Ptr : in C460014_1.Facade_Class_Ptr_Type) is
   begin
      Constraint_Error_Raised := False;
      -- Should fail Tag_Check and therefore raise Constraint_Error if
      -- parameter doesn't designate an object of Facade_A_Type
      -- or Facade_B_Type.
      C460014_1.Define_Class_Construct (Facade_Class_Ptr => Facade_Class_Ptr);
   exception
      when Constraint_Error =>
         Constraint_Error_Raised := True;
   end Test_Define_Class_Construct;

begin

   Report.Test
     ("C460014",
      "Check that if the operand type of a type conversion is " &
      "access-to-class-wide, Constraint_Error is raised if the tag of the " &
      "object designated by the operand does not identify a specific type " &
      "that is covered by or descended from the target type");

   Test_Define_Construct (Facade_Class_Ptr => My_Root_Facade_Ptr);

   if not Constraint_Error_Raised then
      Report.Failed ("Didn't get expected Constraint_Error (1)");
   end if;

   Test_Define_Construct
     (Facade_Class_Ptr => My_Facade_A_Ptr);

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (2)");
   end if;

   Test_Define_Construct
     (Facade_Class_Ptr => My_Facade_B_Ptr);

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (3)");
   end if;

   Test_Define_Class_Construct (Facade_Class_Ptr => My_Root_Facade_Ptr);

   if not Constraint_Error_Raised then
      Report.Failed ("Didn't get expected Constraint_Error (4)");
   end if;

   Test_Define_Class_Construct
     (Facade_Class_Ptr => My_Facade_A_Ptr);

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (5)");
   end if;

   Test_Define_Class_Construct
     (Facade_Class_Ptr => My_Facade_B_Ptr);

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (6)");
   end if;

   -- Check that it is OK to pass null and that does not cause some failure.
   Test_Define_Class_Construct (Facade_Class_Ptr => null);

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (7)");
   end if;

   Test_Define_Class_Construct (Facade_Class_Ptr =>
      C460014_1.Facade_Class_Ptr_Type (My_Null_Facade_B_Ptr));

   if Constraint_Error_Raised then
      Report.Failed ("Unexpected Constraint_Error (8)");
   end if;

   Report.Result;

end C460014;
