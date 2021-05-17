
--=======================================================================--

with FA11D00.CA11D03_0;    -- Basic_Complex,
                           -- implicitly with Complex_Definition.
with Report;

procedure CA11D03 is

   package Complex_Pkg renames FA11D00;     -- Complex_Definition_Pkg
   package Basic_Complex_Pkg renames FA11D00.CA11D03_0;   -- Basic_Complex

   use Complex_Pkg;                            
   use Basic_Complex_Pkg;           
           
   TC_Handled_In_Subtest_1,
   TC_Handled_In_Subtest_2 : boolean := false;

begin

   Report.Test ("CA11D03", "Check that an exception declared in a package " &
                "can be raised by a client of a child of the package");

   Multiply_Complex_Subtest:
   declare
      Operand_1  : Complex_Type := Complex (Int_Type (Report.Ident_Int (3)), 
                                   Int_Type (Report.Ident_Int (2)));  
                                   -- Referenced to function in parent package.
      Operand_2  : Complex_Type := Complex (Int_Type (Report.Ident_Int (10)), 
                                   Int_Type (Report.Ident_Int (8)));  
      Mul_Res    : Complex_type := Complex (Int_Type (Report.Ident_Int (30)), 
                                   Int_Type (Report.Ident_Int (16)));  
      Complex_No : Complex_Type := Zero;  -- Zero is declared in parent package.
   begin
      Complex_No := Operand_1 * Operand_2;   -- Basic_Complex."*".
      if Complex_No /= Mul_Res then
         Report.Failed ("Incorrect results from multiplication");
      end if;

      -- Error is raised and exception will be handled.
      if Complex_No = Mul_Res then
         raise Multiply_Error;             -- Reference to exception in
      end if;                              -- parent package.

   exception
      when Multiply_Error => 
         TC_Handled_In_Subtest_1 := true;
      when others => 
         TC_Handled_In_Subtest_1 := false;  -- Improper exception handling.

   end Multiply_Complex_Subtest;

   Add_Complex_Subtest:
   declare
      Error_In_Client : exception renames Add_Error;  
                        -- Reference to exception in parent package.
      Operand_1  : Complex_Type := Complex (Int_Type (Report.Ident_Int (2)), 
                                   Int_Type (Report.Ident_Int (7)));  
      Operand_2  : Complex_Type := Complex (Int_Type (Report.Ident_Int (-4)), 
                                   Int_Type (Report.Ident_Int (1)));  
      Add_Res    : Complex_type := Complex (Int_Type (Report.Ident_Int (-2)), 
                                   Int_Type (Report.Ident_Int (8)));  
      Complex_No : Complex_Type := One;   -- One is declared in parent 
                                          -- package.
   begin
      Complex_No := Operand_1 + Operand_2;   -- Basic_Complex."+".

      if Complex_No /= Add_Res then
         Report.Failed ("Incorrect results from multiplication");
      end if;

      -- Error is raised and exception will be handled.
      if Complex_No = Add_Res then
         raise Error_In_Client;
      end if;

   exception
      when Error_In_Client => 
         TC_Handled_In_Subtest_2 := true;

      when others => 
         TC_Handled_In_Subtest_2 := false;  -- Improper exception handling.

   end Add_Complex_Subtest;

   if not (TC_Handled_In_Subtest_1           and   -- Check to see that all 
           TC_Handled_In_Subtest_2)                -- exceptions were handled
                                                   -- in the proper location.
   then
      Report.Failed ("Exceptions handled in incorrect locations");
   end if;

   Report.Result;

end CA11D03;
