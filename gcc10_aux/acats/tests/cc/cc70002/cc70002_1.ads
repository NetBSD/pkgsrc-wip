

     --==================================================================--


generic          -- 2D matrix abstraction.
   type Element_Type is range <>;

   type Abscissa is range <>;
   type Ordinate is range <>;

   type Matrix_2D is array (Abscissa, Ordinate) of Element_Type;
package CC70002_1 is

   Add_Ident : constant Matrix_2D := (Abscissa => (others => 1));
                                                          -- Artificial for
                                                          -- testing purposes.
   -- ... Other identity matrices.


   function "+" (A, B : Matrix_2D) return Matrix_2D;

   -- ... Other operations.

end CC70002_1;
