

     --==================================================================--


procedure CC51003_1 (Dbl : in out Dbl_Square) is
begin
   for I in 1 .. Dbl.Number loop     -- Discriminants inherited from ancestor
      for J in 1 .. Dbl.Number loop  -- type (should work even for derived type
                                     -- declaring new discriminant part).
         Dbl.Left.Mat (I, J)  := 0;  -- Other components inherited from
         Dbl.Right.Mat (I, J) := 0;  -- ancestor type.

      end loop;
   end loop;
end CC51003_1;
