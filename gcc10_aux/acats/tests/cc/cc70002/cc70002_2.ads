

     --==================================================================--


with CC70002_0;  -- Mathematical group signature.
with CC70002_1;  -- 2D matrix abstraction.

generic          -- Mathematical 2D matrix addition group.

   with package Matrix_Ops is new CC70002_1 (<>);

   -- Although the restriction of the formal package below to signatures
   -- describing addition groups, and then only for 2D matrices, is rather
   -- artificial in the context of this "application," the passing of types,
   -- objects, and subprograms as actuals to a formal package is not.

   with package Math_Sig is new CC70002_0
     (Group_Type => Matrix_Ops.Matrix_2D,
      Identity   => Matrix_Ops.Add_Ident,
      Operation  => Matrix_Ops."+");

package CC70002_2 is

   -- Add two matrices that are to be multiplied by coefficients:
   -- [ ] = CA*[ ] + CB*[ ].

   function Add_Matrices_With_Coefficients (A  : Matrix_Ops.Matrix_2D;
                                            CA : Integer;
                                            B  : Matrix_Ops.Matrix_2D;
                                            CB : Integer)
     return Matrix_Ops.Matrix_2D;

   -- ...Other operations.

end CC70002_2;
