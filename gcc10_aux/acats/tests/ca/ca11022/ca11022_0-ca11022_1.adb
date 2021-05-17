
     --==================================================================--

package body CA11022_0.CA11022_1 is

   procedure Draw_Square (At_Col : in Column;
                          At_Row : in Row;
                          Len    : in Length) is
   begin
      -- use square drawing algorithm 
      -- call
      Put_Dot (At_Col + Column (Len), At_Row + Row(Len));
      -- as needed in the algorithm.
      TC_Draw_Square := true;
   end Draw_Square;

   -------------------------------------------------------
   procedure Draw_Circle (At_Col : in Column;
                          At_Row : in Row;
                          Rad    : in Radius) is
   begin
      -- use circle drawing algorithm 
      -- call
      for I in 1 .. Rad loop
         Put_Dot (At_Col + Column(I), At_Row + Row(I));
      end loop;
      -- as needed in the algorithm.
      TC_Draw_Circle := true;
   end Draw_Circle;

end CA11022_0.CA11022_1;
