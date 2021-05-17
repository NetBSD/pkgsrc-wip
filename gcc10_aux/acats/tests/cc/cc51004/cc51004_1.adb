

     --==================================================================--


procedure CC51004_1 (Sq : in out Squares) is
begin
   for I in 1 .. Sq.Num1 loop        -- Discriminants inherited from ancestor
      for J in 1 .. Sq.Num1 loop     -- type (should work even for derived type
                                     -- declaring new discriminant part).
         Sq.One.Mat (I, J) := 0;     -- Other components inherited from
                                     -- ancestor type.
      end loop;
   end loop;
end CC51004_1;
