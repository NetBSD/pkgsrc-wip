

     --==================================================================--


package body CC70002_1 is

   function "+" (A, B : Matrix_2D) return Matrix_2D is
      C : Matrix_2D;
   begin
      for I in Abscissa loop
         for J in Ordinate loop
            C(I,J) := A(I,J) + B(I,J);
         end loop;
      end loop;
      return C;
   end "+";

end CC70002_1;
