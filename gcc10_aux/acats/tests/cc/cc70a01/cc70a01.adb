

     --==================================================================--


with Report;

with FC70A00;    -- Generic complex integer operations.
with CC70A01_0;  -- Generic complex matrix operations.

procedure CC70A01 is

   type My_Integer is range -100 .. 100;

   package My_Complex_Package is new FC70A00   (My_Integer);
   package My_Matrix_Package  is new CC70A01_0 (My_Complex_Package);

   use My_Complex_Package,                                -- All user-defined
       My_Matrix_Package;                                 -- operators directly
                                                          -- visible.

   subtype Matrix_2x2 is Complex_Matrix_Type (1 .. 2, 1 .. 2);
   subtype Matrix_2x3 is Complex_Matrix_Type (1 .. 2, 1 .. 3);

   function C (Real, Imag : My_Integer) return Complex_Type renames Complex;

begin  -- Main program.

   Report.Test ("CC70A01", "Check that the visible part of a generic " &
                "formal package includes the first list of basic " &
                "declarative items of the package specification. Check " &
                "for a generic package where formal package has (<>) " &
                "actual part");

   declare
      Identity_2x2 : Matrix_2x2 := Identity_Matrix (Size => 2);
      Operand_2x3  : Matrix_2x3 := ( ( C(1, 2), C(3, 6), C(5, 1) ),
                                     ( C(0, 3), C(7, 9), C(3, 4) ) );
      Result_2x3   : Matrix_2x3 := ( others => ( others => Zero ) );
   begin

      begin -- Block #1.
         Result_2x3 := Identity_2x2 * Operand_2x3; -- Should return
                                                   -- Operand_2x3.
         if (Result_2x3 /= Operand_2x3) then
            Report.Failed ("Incorrect results from matrix multiplication");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Block #1");
      end;  -- Block #1.


      begin -- Block #2.
         Result_2x3 := Operand_2x3 * Identity_2x2;  -- Can't multiply 2x3
                                                    -- by 2x2.
         Report.Failed ("Exception Dimension_Mismatch not raised");
      exception
         when Dimension_Mismatch =>
            null;
         when others             =>
            Report.Failed ("Unexpected exception raised - Block #2");
      end;  -- Block #2.

   end;

   Report.Result;

end CC70A01;
