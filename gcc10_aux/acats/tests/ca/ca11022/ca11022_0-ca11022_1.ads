
-- No bodies required for CA11022_0.

     --==================================================================--

-- Child package to provide general graphic functionalities.

generic               

   with procedure Put_Dot (X : in Column;
                           Y : in Row);

package CA11022_0.CA11022_1 is     

   procedure Draw_Square (At_Col : in Column;
                          At_Row : in Row;
                          Len    : in Length);

   procedure Draw_Circle (At_Col : in Column;
                          At_Row : in Row;
                          Rad    : in Radius);

   -- procedure Draw_Ellipse ...
   -- and other drawings ...

end CA11022_0.CA11022_1;
