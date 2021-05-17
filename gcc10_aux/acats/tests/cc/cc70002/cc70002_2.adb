

     --==================================================================--


package body CC70002_2 is

   function Add_Matrices_With_Coefficients (A  : Matrix_Ops.Matrix_2D;
                                            CA : Integer;
                                            B  : Matrix_Ops.Matrix_2D;
                                            CB : Integer)
     return Matrix_Ops.Matrix_2D is
      Left, Right : Matrix_Ops.Matrix_2D;
   begin
      Left  := Math_Sig.Power (A, CA);      -- Multiply 1st array by its coeff.
      Right := Math_Sig.Power (B, CB);      -- Multiply 2nd array by its coeff.
      return (Matrix_Ops."+" (Left, Right));-- Add these two arrays.
   end Add_Matrices_With_Coefficients;

end CC70002_2;
