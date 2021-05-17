

     --==================================================================--


generic                                                -- Generic package which
   type Element_Type is range <>;                      -- serves as template
   type Rows_Type    is range <>;                      -- for 2nd formal pack.
   type Columns_Type is range <>;
   type Matrix_Type  is array (Rows_Type, Columns_Type) of Element_Type;
package BC70005_1 is

   Add_Ident : Matrix_Type;

   function "+" (A, B : Matrix_Type) return Matrix_Type;

end BC70005_1;
