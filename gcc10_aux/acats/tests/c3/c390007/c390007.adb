

     --==================================================================--


with C390007_0.C390007_1.C390007_2;
with C390007_0.C390007_3.C390007_4;
use  C390007_0;

with Report;
procedure C390007 is
begin
   Report.Test ("C390007", "Check that the tag of an object of a tagged " &
                "type is preserved by type conversion and parameter passing");


   --
   -- Check that tags are preserved by parameter passing:
   --

   Parameter_Passing_Subtest:
   declare
      Specific_A  : C390007_0.C390007_1.C390007_2.Param_Derived_Type;
      Specific_B  : C390007_0.C390007_1.C390007_2.Param_Derived_Type;

      ClassWide_A : C390007_0.C390007_1.Param_Parent_Type'Class := Specific_A;
      ClassWide_B : C390007_0.C390007_1.Param_Parent_Type'Class := Specific_B;

      use C390007_0.C390007_1;
      use C390007_0.C390007_1.C390007_2;
   begin

      Outer_Proc (Specific_A);         
      if Specific_A.Last_Call /= Derived_Inner then
         Report.Failed ("Parameter passing: tag not preserved in call to " &
                        "primitive operation with specific operand");
      end if;

      C390007_0.ClassWide_Proc (Specific_B);
      if Specific_B.Last_Call /= Derived_Inner then
         Report.Failed ("Parameter passing: tag not preserved in call to " &
                        "class-wide operation with specific operand");
      end if;

      Outer_Proc (ClassWide_A);        
      if ClassWide_A.Last_Call /= Derived_Inner then
         Report.Failed ("Parameter passing: tag not preserved in call to " &
                        "primitive operation with class-wide operand");
      end if;

      C390007_0.ClassWide_Proc (ClassWide_B);
      if ClassWide_B.Last_Call /= Derived_Inner then
         Report.Failed ("Parameter passing: tag not preserved in call to " &
                        "class-wide operation with class-wide operand");
      end if;

   end Parameter_Passing_Subtest;


   --
   -- Check that tags are preserved by type conversion:
   --

   Type_Conversion_Subtest:
   declare
      Specific_A  : C390007_0.C390007_3.C390007_4.Convert_Derived_Type;
      Specific_B  : C390007_0.C390007_3.C390007_4.Convert_Derived_Type;

      ClassWide_A : C390007_0.C390007_3.Convert_Parent_Type'Class :=
                    C390007_0.C390007_3.Convert_Parent_Type(Specific_A);
      ClassWide_B : C390007_0.C390007_3.Convert_Parent_Type'Class :=
                    C390007_0.C390007_3.Convert_Parent_Type(Specific_B);

      use C390007_0.C390007_3;
      use C390007_0.C390007_3.C390007_4;
   begin

      Outer_Proc (Convert_Parent_Type(Specific_A));
      if (Specific_A.First_Call  /= Parent_Outer)  or
         (Specific_A.Second_Call /= Derived_Inner)
      then
         Report.Failed ("Type conversion: tag not preserved in call to " &
                        "primitive operation with specific operand");
      end if;

      Outer_Proc (ClassWide_A);   
      if (ClassWide_A.First_Call  /= Derived_Outer) or
         (ClassWide_A.Second_Call /= Derived_Inner)
      then
         Report.Failed ("Type conversion: tag not preserved in call to " &
                        "primitive operation with class-wide operand");
      end if;

      C390007_0.ClassWide_Proc (Convert_Parent_Type(Specific_B));
      if (Specific_B.Second_Call /= Derived_Inner) then
         Report.Failed ("Type conversion: tag not preserved in call to " &
                        "class-wide operation with specific operand");
      end if;

      C390007_0.ClassWide_Proc (ClassWide_B);
      if (ClassWide_A.Second_Call /= Derived_Inner) then
         Report.Failed ("Type conversion: tag not preserved in call to " &
                        "class-wide operation with class-wide operand");
      end if;

   end Type_Conversion_Subtest;


   --
   -- Check that tags are preserved by type conversion and parameter passing:
   --

   Type_Conversion_And_Parameter_Passing_Subtest:
   declare
      Specific_A  : C390007_0.C390007_1.C390007_2.Param_Derived_Type;
      Specific_B  : C390007_0.C390007_1.C390007_2.Param_Derived_Type;

      use C390007_0.C390007_1;
      use C390007_0.C390007_1.C390007_2;
   begin

      Outer_Proc (Param_Parent_Type (Specific_A));   
      if Specific_A.Last_Call /= Parent_Outer then
         Report.Failed ("Type conversion and parameter passing: tag not " &
                        "preserved in call to primitive operation with "  &
                        "specific operand");
      end if;

      C390007_0.ClassWide_Proc (Param_Parent_Type (Specific_B));
      if Specific_B.Last_Call /= Derived_Inner then
         Report.Failed ("Type conversion and parameter passing: tag not " &
                        "preserved in call to class-wide operation with "  &
                        "specific operand");
      end if;

   end Type_Conversion_And_Parameter_Passing_Subtest;


   Report.Result;

end C390007;
