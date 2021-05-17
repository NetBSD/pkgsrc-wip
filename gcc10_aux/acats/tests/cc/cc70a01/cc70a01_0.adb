

     --==================================================================--


package body CC70A01_0 is  -- Generic complex matrix operations.

   use Complex_Package;

               --==============================================--

   function Inner_Product (Left, Right : Complex_Matrix_Type;
                           Row, Column : Positive)    -- Compute inner product
     return Complex_Package.Complex_Type is           -- for matrix-multiply.

      Result : Complex_Type := Zero;                  
      subtype Vector_Size is Positive range Left'Range(2);

   begin  -- Inner_Product.
      for I in Vector_Size loop
         Result := Result +                           -- Complex_Package."+".
                   (Left(Row, I) * Right(I, Column)); -- Complex_Package."*".
      end loop;
      return (Result);
   end Inner_Product;

               --==============================================--

   function Identity_Matrix (Size : Positive) return Complex_Matrix_Type is
      Result : Complex_Matrix_Type (1 .. Size, 1 .. Size) :=
               (others => (others => Zero));          -- Zeroes everywhere...
   begin
      for I in 1 .. Size loop
         Result (I, I) := One;                        -- Ones on the diagonal.
      end loop;
      return (Result);
   end Identity_Matrix;

               --==============================================--

   function "*" (Left  : Complex_Matrix_Type; Right : Complex_Matrix_Type)
     return Complex_Matrix_Type is

      subtype Rows    is Positive range Left'Range(1);
      subtype Columns is Positive range Right'Range(2);

      Result : Complex_Matrix_Type(Rows, Columns);
   begin
      if Left'Length(2) /= Right'Length(1) then       -- # columns of Left must
                                                      -- match # rows of Right.
         raise Dimension_Mismatch;                    
      else
         for I in Rows loop
            for J in Columns loop
                Result(I, J) := Inner_Product (Left, Right, I, J);
            end loop;
         end loop;
         return (Result);
      end if;
   end "*";

end CC70A01_0;
