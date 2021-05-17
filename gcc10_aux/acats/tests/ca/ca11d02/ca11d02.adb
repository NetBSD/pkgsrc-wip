
--=======================================================================--

with FA11D00.CA11D02_0.CA11D02_1;    -- Array_Complex,
                                     -- implicitly with Basic_Complex.
with Report;

procedure CA11D02 is

   package Complex_Pkg renames FA11D00;
   package Array_Complex_Pkg renames FA11D00.CA11D02_0.CA11D02_1;

   use Complex_Pkg;                            
   use Array_Complex_Pkg;                      

begin

   Report.Test ("CA11D02", "Check that an exception declared in a package " &
                "can be raised by a child of a child package");

   Multiply_Complex_Subtest:
   declare
      Operand_1  : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (3)), 
                      Int_Type (Report.Ident_Int (5))),
                      Complex (Int_Type (Report.Ident_Int (2)), 
                      Int_Type (Report.Ident_Int (8))) );
      Operand_2  : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (1)), 
                      Int_Type (Report.Ident_Int (2))),
                      Complex (Int_Type (Report.Ident_Int (3)), 
                      Int_Type (Report.Ident_Int (6))) );
      Operand_3  : Complex_Array_Type := ( Zero, Zero);
      Mul_Result : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (3)), 
                      Int_Type (Report.Ident_Int (10))),
                      Complex (Int_Type (Report.Ident_Int (6)), 
                      Int_Type (Report.Ident_Int (48))) );
      Complex_No : Complex_Array_Type := (others => Zero);

   begin
      If (Multiply (Operand_1, Operand_2) /= Mul_Result) then
         Report.Failed ("Incorrect results from multiplication");
      end if;

      -- Error is raised and exception will be handled in grandchild package.

      Complex_No := Multiply (Operand_1, Operand_3);

      if Complex_No /= (Zero, Zero) then
         Report.Failed ("Exception was not raised in multiplication");
      end if;

   exception
      when Multiply_Error     =>
         Report.Failed ("Exception raised in multiplication and " &
                        "propagated to caller");
         TC_Handled_In_Grandchild_Pkg_Func := false;  
              -- Improper exception handling in caller.

      when others => 
         Report.Failed ("Unexpected exception in multiplication");
         TC_Handled_In_Grandchild_Pkg_Func := false;  
              -- Improper exception handling in caller.

   end Multiply_Complex_Subtest;


   Add_Complex_Subtest:
   declare
      Operand_1  : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (2)), 
                      Int_Type (Report.Ident_Int (7))),
                      Complex (Int_Type (Report.Ident_Int (5)), 
                      Int_Type (Report.Ident_Int (8))) );
      Operand_2  : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (4)), 
                      Int_Type (Report.Ident_Int (1))),
                      Complex (Int_Type (Report.Ident_Int (2)), 
                      Int_Type (Report.Ident_Int (3))) );
      Operand_3  : Complex_Array_Type := ( Zero, Zero);
      Add_Result : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (6)), 
                      Int_Type (Report.Ident_Int (8))),
                      Complex (Int_Type (Report.Ident_Int (7)), 
                      Int_Type (Report.Ident_Int (11))) );
      Complex_No : Complex_Array_Type := (others => Zero);

   begin
      Complex_No := Add (Operand_1, Operand_2);

      If (Complex_No /= Add_Result) then
         Report.Failed ("Incorrect results from addition");
      end if;

      -- Error is raised in grandchild package and exception 
      -- will be propagated to caller.

      Complex_No := Add (Operand_1, Operand_3);

      if Complex_No = Add_Result then
         Report.Failed ("Exception was not raised in addition");
      end if;

   exception
      when Add_Error => 
         TC_Propagated_To_Caller := true;  -- Exception is propagated.

      when others => 
         Report.Failed ("Unexpected exception in addition subtest");
         TC_Propagated_To_Caller := false;  -- Improper exception handling
                                            -- in caller.
   end Add_Complex_Subtest;

   Inverse_Complex_Subtest:
   declare
      Operand_1  : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (1)), 
                      Int_Type (Report.Ident_Int (5))),
                      Complex (Int_Type (Report.Ident_Int (3)), 
                      Int_Type (Report.Ident_Int (11))) );
      Operand_3  : Complex_Array_Type 
                 := ( Zero, Complex (Int_Type (Report.Ident_Int (3)), 
                      Int_Type (Report.Ident_Int (6))) );
      Inv_Result : Complex_Array_Type 
                 := ( Complex (Int_Type (Report.Ident_Int (-1)), 
                      Int_Type (Report.Ident_Int (-5))),
                      Complex (Int_Type (Report.Ident_Int (-3)), 
                      Int_Type (Report.Ident_Int (-11))) );
      Complex_No : Complex_Array_Type := (others => Zero);

   begin
      Inverse (Operand_1, Complex_No);

      if (Complex_No /= Inv_Result) then
         Report.Failed ("Incorrect results from inverse");
      end if;

      -- Error is raised in grandchild package and exception 
      -- will be handled/reraised to caller.

      Inverse (Operand_3, Complex_No);

      Report.Failed ("Exception was not handled in inverse");

   exception
      when Inverse_Error => 
         if not TC_Handled_In_Grandchild_Pkg_Proc then
            Report.Failed ("Exception was not raised in inverse");
         else
            TC_Handled_In_Caller := true;  -- Exception is reraised from
                                           -- child package.
         end if;

      when others => 
         Report.Failed ("Unexpected exception in inverse");
         TC_Handled_In_Caller := false; 
                -- Improper exception handling in caller.

   end Inverse_Complex_Subtest;

   if not (TC_Handled_In_Caller               and   -- Check to see that all 
           TC_Handled_In_Grandchild_Pkg_Proc  and   -- exceptions were handled
           TC_Handled_In_Grandchild_Pkg_Func  and   -- in proper location.
           TC_Propagated_To_Caller)        
   then
      Report.Failed ("Exceptions handled in incorrect locations");
   end if;

   Report.Result;

end CA11D02;
